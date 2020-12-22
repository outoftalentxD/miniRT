/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_to_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:54:18 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 23:23:42 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_point				*compute_up_axis(t_point *forward, t_point *right)
{
	t_point *up;

	up = vector_cross_product(forward, right);
	vector_normalize(up);
	return (up);
}

t_point				*compute_right_axis(t_point *forward)
{
	t_point	*temp;
	t_point *right;

	temp = new_point(0, 1, 0);
	vector_normalize(temp);
	right = vector_cross_product(temp, forward);
	free(temp);
	vector_normalize(right);
	return (right);
}

t_point				*compute_forward_axis(t_cam *cam)
{
	t_point		*forward;

	forward = new_point(cam->vector->x, cam->vector->y, cam->vector->z);
	vector_mult(forward, -1);
	vector_normalize(forward);
	return (forward);
}

static void			matrix4x4_fill(t_cam *cam, double **matrix)
{
	t_point *forward;
	t_point *up;
	t_point *right;

	forward = cam->forward;
	right = cam->right;
	up = cam->up;
	matrix[0][0] = right->x;
	matrix[0][1] = right->y;
	matrix[0][2] = right->z;
	matrix[1][0] = up->x;
	matrix[1][1] = up->y;
	matrix[1][2] = up->z;
	matrix[2][0] = forward->x;
	matrix[2][1] = forward->y;
	matrix[2][2] = forward->z;
	matrix[3][0] = cam->pos->x;
	matrix[3][1] = cam->pos->y;
	matrix[3][2] = cam->pos->z;
	return ;
}

double				**camera_to_world(t_cam *cam)
{
	double	**matrix;
	int		i;

	matrix = (double **)malloc(sizeof(double *) * 4);
	if (!matrix)
		return (0);
	i = -1;
	while (++i < 4)
		matrix[i] = (double *)malloc(sizeof(double) * 4);
	matrix4x4_fill(cam, matrix);
	return (matrix);
}
