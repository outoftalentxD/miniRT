/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:24:44 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 19:02:50 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void				get_triangle_norm_vec(t_figure *triangle)
{
	t_point *vec1;
	t_point *vec2;

	vec1 = vector_create(triangle->p1, triangle->p2);
	vec2 = vector_create(triangle->p1, triangle->p3);
	triangle->vector = vector_cross_product(vec1, vec2);
	if (triangle->vector->x == 0)
		triangle->vector->x = fabs(triangle->vector->x);
	if (triangle->vector->y == 0)
		triangle->vector->y = fabs(triangle->vector->y);
	if (triangle->vector->z == 0)
		triangle->vector->z = fabs(triangle->vector->z);
	vector_normalize(triangle->vector);
	free(vec1);
	free(vec2);
	return ;
}

static int			free_orient_and_return_ret(t_orient *orient, double t,
					double *root, int ret)
{
	free(orient);
	if (root)
		*root = t;
	return (ret);
}

static t_orient		*get_orient_tr(t_point *point, t_figure *triangle)
{
	t_orient *new;

	new = (t_orient *)malloc(sizeof(t_orient));
	if (!new)
		return (0);
	vector_normalize(triangle->vector);
	new->o1 = compute_orient(point, triangle->p1,
				triangle->p2, triangle->vector);
	new->o2 = compute_orient(point, triangle->p2,
				triangle->p3, triangle->vector);
	new->o3 = compute_orient(point, triangle->p3,
				triangle->p1, triangle->vector);
	new->o4 = 0;
	return (new);
}

int					intersect_triangle(t_point *ray, t_figure *triangle,
					t_cam *cam, double *root0)
{
	t_orient	*orient;
	t_point		*point;
	double		t;

	vector_normalize(triangle->vector);
	vector_normalize(ray);
	if (intersect_plane(ray, triangle, cam, &t) == 0)
		return (0);
	vector_normalize(ray);
	point = vector_sum(cam->pos, vector_mult(ray, t));
	orient = get_orient_tr(point, triangle);
	free(point);
	if (orient->o1 <= 0 && orient->o2 <= 0 && orient->o3 <= 0)
		return (free_orient_and_return_ret(orient, t, root0, 1));
	else if (orient->o1 >= 0 && orient->o2 >= 0 && orient->o3 >= 0)
		return (free_orient_and_return_ret(orient, t, root0, 1));
	else
		return (free_orient_and_return_ret(orient, 0, 0, 0));
}
