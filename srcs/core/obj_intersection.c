/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 07:37:18 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 18:11:04 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int					intersect_sphere(t_point *ray, t_figure *sphere,
					t_cam *cam, double *root0)
{
	double	a;
	double	b;
	double	c;
	double	root1;
	t_point	*temp;

	vector_normalize(ray);
	temp = vector_sub(cam->pos, sphere->pos);
	a = vector_scalar_mult(ray, ray);
	b = 2 * vector_scalar_mult(ray, temp);
	c = vector_scalar_mult(temp, temp) - sphere->d * sphere->d / 4;
	get_square_root(new_point(a, b, c), root0, &root1);
	vector_normalize(ray);
	free(temp);
	if (*root0 < 1)
		*root0 = root1;
	if (*root0 > 1)
		return (1);
	else
		return (0);
}

int					intersect_plane(t_point *ray, t_figure *plane,
					t_cam *cam, double *root0)
{
	double	denom;
	double	t;
	t_point *vec;

	vector_normalize(ray);
	vector_normalize(plane->vector);
	denom = vector_scalar_mult(plane->vector, ray);
	if (denom < 0)
	{
		vector_mult(plane->vector, -1);
		denom = vector_scalar_mult(plane->vector, ray);
	}
	if (denom > 0.0001)
	{
		if (plane->name == TRIANGLE)
			vec = vector_sub(plane->p1, cam->pos);
		else
			vec = vector_sub(plane->pos, cam->pos);
		t = vector_scalar_mult(vec, plane->vector) / denom;
		free(vec);
		if (t > 1)
			return (*root0 = t);
	}
	return (0);
}

int					intersect_disk(t_point *ray, t_figure *disk,
					t_cam *cam, double *root)
{
	double	t;
	double	len;
	t_point	*point;
	t_point *vec;

	t = 0;
	vector_normalize(ray);
	if (intersect_plane(ray, disk, cam, &t) == 0)
		return (0);
	vector_normalize(ray);
	point = vector_sum(cam->pos, vector_mult(ray, t));
	vec = vector_create(point, disk->pos);
	len = vector_len(vec);
	free(vec);
	free(point);
	if (t > 1 && len < disk->d)
		return (*root = t);
	return (0);
}

int					check_intersection(t_point *point,
					t_light *light, t_scene *scene)
{
	t_point		*ray;
	t_cam		*cam;
	double		t;
	double		root;

	cam = init_cam();
	cam->pos = point;
	ray = vector_create(point, light->pos);
	t = vector_len(ray);
	vector_normalize(ray);
	cam->vector = ray;
	ray_intersect(ray, scene->figures, cam, &root);
	free(ray);
	free(cam);
	if (root < t)
		return (1);
	return (0);
}
