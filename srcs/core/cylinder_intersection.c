/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:50:50 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 23:32:15 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			is_one_side(t_scene *scene, t_figure *figure, t_light *light)
{
	t_point *lvec;
	t_point	*cvec;
	double	dl;
	double	dc;

	if (figure->name != SPHERE && figure->name != CYLINDER)
		return (1);
	lvec = vector_create(figure->pos, light->pos);
	cvec = vector_create(figure->pos, scene->cam->pos);
	dl = vector_len(lvec);
	dc = vector_len(cvec);
	free(cvec);
	free(lvec);
	if (figure->name == SPHERE)
		if (!sphere_one_side(figure, dl, dc))
			return (0);
	if (figure->name == CYLINDER)
		if (!cylinder_one_side(figure, scene, light))
			return (0);
	return (1);
}

int			is_in_cylinder(t_figure *figure, t_point *point)
{
	t_point *vec;
	double	dot;
	t_point	*d;

	vector_normalize(figure->vector);
	vec = vector_create(figure->pos, point);
	dot = vector_scalar_mult(vec, figure->vector)
			/ vector_scalar_mult(figure->vector, figure->vector);
	free(vec);
	if (dot == 0)
		d = new_point(figure->pos->x, figure->pos->y, figure->pos->x);
	else
		d = vector_sum(figure->pos, vector_mult(figure->vector, dot));
	dot = vector_len(d);
	vector_normalize(figure->vector);
	if (dot >= figure->h / 2)
		return (0);
	vec = vector_create(d, point);
	dot = vector_len(vec);
	free(vec);
	free(d);
	if (dot <= figure->d / 2)
		return (1);
	return (0);
}

int			point_in_valid_range(t_point *ray, t_figure *cylinder,
			t_cam *cam, double root)
{
	t_point *point;
	t_point *vec;
	double	len;

	if (root < 1)
		return (0);
	vector_normalize(ray);
	point = vector_sum(cam->pos, vector_mult(ray, root));
	vec = vector_create(cylinder->pos, point);
	len = vector_len(vec);
	len = pow(len, 2);
	len = sqrt(len - cylinder->d * cylinder->d);
	free(point);
	free(vec);
	if (len > cylinder->h / 2)
		return (0);
	else
		return (1);
}

double		solve_cylinder_equation(t_point *ray, t_figure *cylinder,
			t_cam *cam, t_point *vec)
{
	double a;
	double b;
	double c;
	double root1;
	double root2;

	vector_normalize(ray);
	vector_normalize(cylinder->vector);
	a = vector_scalar_mult(ray, ray)
		- pow(vector_scalar_mult(ray, cylinder->vector), 2);
	c = vector_scalar_mult(vec, vec)
		- pow(vector_scalar_mult(vec, cylinder->vector), 2)
		- pow(cylinder->d, 2);
	b = 2 * (vector_scalar_mult(ray, vec)
		- vector_scalar_mult(ray, cylinder->vector)
		* vector_scalar_mult(vec, cylinder->vector));
	get_square_root(new_point(a, b, c), &root1, &root2);
	if (root1 < 1)
		root1 = root2;
	if (point_in_valid_range(ray, cylinder, cam, root1))
		return (root1);
	return (0);
}

int			intersect_cylinder(t_point *ray, t_figure *cylinder,
			t_cam *cam, double *root)
{
	t_point *vec;
	double	t;

	vector_normalize(cylinder->vector);
	vector_normalize(ray);
	vec = vector_sub(cam->pos, cylinder->pos);
	t = solve_cylinder_equation(ray, cylinder, cam, vec);
	vector_normalize(ray);
	free(vec);
	if (t > 1)
		return (*root = t);
	return (0);
}
