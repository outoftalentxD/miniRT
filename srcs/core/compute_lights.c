/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:16:34 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 19:40:49 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_point		*get_body_norm(t_figure *figure, t_point *point)
{
	t_point *vec;
	t_point	*d;
	t_point *norm;
	double	dot;

	vector_normalize(figure->vector);
	vec = vector_create(figure->pos, point);
	dot = vector_scalar_mult(vec, figure->vector)
			/ vector_scalar_mult(figure->vector, figure->vector);
	d = vector_sum(figure->pos, vector_mult(figure->vector, dot));
	free(vec);
	norm = vector_create(d, point);
	free(d);
	return (norm);
}

t_point		*get_cylinder_norm(t_figure *figure, t_point *point)
{
	t_point	*d;
	t_point *vec;
	t_point *norm;
	double	dot;

	vector_normalize(figure->vector);
	vec = vector_create(figure->pos, point);
	dot = vector_scalar_mult(vec, figure->vector)
		/ vector_scalar_mult(figure->vector, figure->vector);
	d = vector_sum(figure->pos, vector_mult(figure->vector, dot));
	free(vec);
	norm = vector_create(d, point);
	free(d);
	dot = vector_len(norm);
	return (norm);
}

t_point		*calculate_figure_norm_vector(t_figure *figure,
			t_point *point, t_point *ray)
{
	t_point *n;

	n = 0;
	vector_normalize(ray);
	if (figure->name == SPHERE)
		n = vector_create(figure->pos, point);
	else if (figure->name == PLANE || figure->name == DISK)
		n = new_point(figure->vector->x, figure->vector->y, figure->vector->z);
	else if (figure->name == SQUARE)
		n = new_point(figure->vector->x, figure->vector->y, figure->vector->z);
	else if (figure->name == TRIANGLE)
		n = new_point(figure->vector->x, figure->vector->y, figure->vector->z);
	else if (figure->name == CYLINDER)
		n = get_cylinder_norm(figure, point);
	vector_normalize(n);
	if (vector_angle_cos(ray, n) > 0)
		vector_mult(n, -1);
	return (n);
}

double		calculate_light_intensity(t_point *point,
			t_light *light, t_point *ray, t_figure *figure)
{
	double	intensity;
	t_point *vec;
	t_point *norm;
	double	coef;

	coef = 1;
	vector_normalize(ray);
	vec = vector_create(point, light->pos);
	norm = calculate_figure_norm_vector(figure, point, ray);
	vector_normalize(norm);
	intensity = vector_angle_cos(vec, norm);
	if (figure->name != SPHERE && figure->name != CYLINDER)
		coef = 4;
	if (intensity < 0)
		intensity = 0;
	else
		intensity = powf(intensity, coef);
	free(vec);
	free(norm);
	return (intensity * light->brightness);
}

t_color		*apply_color_lightness(t_figure *figure,
			t_point *ray, t_scene *scene, double t)
{
	double	intensity;
	t_light	*light;
	t_point	*point;
	t_point *vec;
	t_point	*lightning;

	intensity = 0;
	lightning = new_point(0, 0, 0);
	vector_normalize(ray);
	light = scene->light;
	add_ambient_to_lightning(scene->ambient, lightning);
	point = vector_sum(scene->cam->pos, vector_mult(ray, t));
	while (light)
	{
		vec = vector_create_free(point, light->pos);
		if (!check_intersection(point, light, scene))
		{
			intensity = calculate_light_intensity(point, light, ray, figure);
			intensity *= is_one_side(scene, figure, light);
			add_light_to_lighting(light, lightning, intensity);
		}
		light = light->next;
	}
	free(point);
	return (apply_lightning(figure->color, lightning));
}
