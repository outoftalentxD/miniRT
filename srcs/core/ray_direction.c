/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:51:13 by melaena           #+#    #+#             */
/*   Updated: 2020/12/18 16:35:09 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void			emancipate_matrix(double **matrix)
{
	int i;

	i = -1;
	while (++i < 4)
		free(matrix[i]);
	free(matrix);
	matrix = 0;
}

t_point				*matrix4x4_vector_mult(double **matrix, t_point *vector)
{
	t_point *result;

	result = init_point();
	if (!result)
		return (0);
	result->x = vector->x * matrix[0][0] + vector->y
		* matrix[1][0] + vector->z * matrix[2][0];
	result->y = vector->x * matrix[0][1] + vector->y
		* matrix[1][1] + vector->z * matrix[2][1];
	result->z = vector->x * matrix[0][2] + vector->y
		* matrix[1][2] + vector->z * matrix[2][2];
	return (result);
}

void				compute_pixel_ndc(double *x, double *y,
					t_resolution *res, t_cam *cam)
{
	double	image_aspect_ratio;
	double	px;
	double	py;
	double	width;
	double	height;

	width = (double)res->x;
	height = (double)res->y;
	if (width > height)
		image_aspect_ratio = width / height;
	else
		image_aspect_ratio = height / width;
	px = (2 * (*x + 0.5) / width - 1) * tan(cam->fov * M_PI / 360.0);
	py = (1 - 2 * (*y + 0.5) / height) * tan(cam->fov * M_PI / 360.0);
	if (width > height)
		px *= image_aspect_ratio;
	else
		py *= image_aspect_ratio;
	*x = px;
	*y = py;
}

t_point				*get_ray_direction(t_cam *cam,
					t_resolution *resolution, double x, double y)
{
	t_point *ray_direction;
	t_point	*temp;
	double	**matrix;

	compute_pixel_ndc(&x, &y, resolution, cam);
	ray_direction = new_point(x, y, -1);
	matrix = camera_to_world(cam);
	temp = ray_direction;
	ray_direction = matrix4x4_vector_mult(matrix, temp);
	vector_normalize(ray_direction);
	free(temp);
	emancipate_matrix(matrix);
	return (ray_direction);
}
