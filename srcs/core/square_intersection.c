/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:20:27 by melaena           #+#    #+#             */
/*   Updated: 2020/12/18 02:34:24 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

double				compute_orient(t_point *point, t_point *p1,
					t_point *p2, t_point *norm)
{
	t_point *v1;
	t_point *v2;
	t_point *cross;
	double	ret;

	vector_normalize(norm);
	v1 = vector_sub(p1, point);
	v2 = vector_sub(p2, point);
	cross = vector_cross_product(v1, v2);
	ret = vector_scalar_mult(cross, norm);
	free(v1);
	free(v2);
	free(cross);
	return (ret);
}

void				get_square_vertices(t_figure *square)
{
	t_point *in_plane;
	t_point *temp;

	vector_normalize(square->vector);
	in_plane = get_perpend_vec(square->vector);
	vector_normalize(in_plane);
	vector_mult(in_plane, square->d / sqrt(2));
	square->v1 = vector_sum(in_plane, square->pos);
	vector_mult(in_plane, -1);
	square->v3 = vector_sum(in_plane, square->pos);
	vector_normalize(in_plane);
	temp = vector_cross_product(in_plane, square->vector);
	vector_mult(temp, square->d / sqrt(2));
	square->v2 = vector_sum(temp, square->pos);
	vector_mult(temp, -1);
	square->v4 = vector_sum(temp, square->pos);
	free(temp);
	free(in_plane);
	return ;
}

static int			free_orinet_and_return(t_orient *orient, double t,
					double *root, int ret)
{
	free(orient);
	if (root)
		*root = t;
	return (ret);
}

static t_orient		*get_orient_sq(t_point *point, t_figure *square)
{
	t_orient *new;

	new = malloc(sizeof(t_orient));
	if (!new)
		return (0);
	vector_normalize(square->vector);
	new->o1 = compute_orient(point, square->v1, square->v2, square->vector);
	new->o2 = compute_orient(point, square->v2, square->v3, square->vector);
	new->o3 = compute_orient(point, square->v3, square->v4, square->vector);
	new->o4 = compute_orient(point, square->v4, square->v1, square->vector);
	return (new);
}

int					intersect_square(t_point *ray, t_figure *square,
					t_cam *cam, double *root0)
{
	t_orient	*orient;
	t_point		*point;
	double		t;

	vector_normalize(square->vector);
	if (intersect_plane(ray, square, cam, &t) == 0)
		return (0);
	vector_normalize(ray);
	point = vector_sum(cam->pos, vector_mult(ray, t));
	orient = get_orient_sq(point, square);
	free(point);
	if (orient->o1 <= 0 && orient->o2 <= 0 &&
		orient->o3 <= 0 && orient->o4 <= 0)
		return (free_orinet_and_return(orient, t, root0, 1));
	else if (orient->o1 >= 0 && orient->o2 >= 0 &&
		orient->o3 >= 0 && orient->o4 >= 0)
		return (free_orinet_and_return(orient, t, root0, 1));
	else
		return (free_orinet_and_return(orient, 0, 0, 0));
}
