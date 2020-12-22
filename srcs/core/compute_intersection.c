/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:38:04 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 18:11:08 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void			update_intersection_data(t_figure *figure, double *root,
					t_figure **temp_figure, double *temp)
{
	if (*root < *temp)
	{
		*temp = *root;
		*temp_figure = figure;
	}
	return ;
}

static int			intersection_handler(t_point *ray, t_figure *figure,
					t_cam *cam, double *root0)
{
	if (figure->name == SPHERE)
		if (intersect_sphere(ray, figure, cam, root0))
			return (1);
	if (figure->name == PLANE)
		if (intersect_plane(ray, figure, cam, root0))
			return (1);
	if (figure->name == SQUARE)
		if (intersect_square(ray, figure, cam, root0))
			return (1);
	if (figure->name == TRIANGLE)
		if (intersect_triangle(ray, figure, cam, root0))
			return (1);
	if (figure->name == CYLINDER)
		if (intersect_cylinder(ray, figure, cam, root0))
			return (1);
	if (figure->name == DISK)
		if (intersect_disk(ray, figure, cam, root0))
			return (1);
	return (0);
}

t_figure			*ray_intersect(t_point *ray, t_figure *figures,
					t_cam *cam, double *root0)
{
	double		temp;
	t_figure	*figure;
	t_figure	*temp_figure;

	temp = INFINITY;
	temp_figure = 0;
	figure = figures;
	while (figure)
	{
		if (intersection_handler(ray, figure, cam, root0))
			update_intersection_data(figure, root0, &temp_figure, &temp);
		figure = figure->next;
	}
	*root0 = temp;
	return (temp_figure);
}

t_color				*trace_ray(int x, int y, t_scene *scene)
{
	t_point		*ray;
	t_figure	*figure;
	t_color		*newcolor;
	double		root;

	ray = get_ray_direction(scene->cam,
			scene->resolution, (double)x, (double)y);
	figure = ray_intersect(ray, scene->figures, scene->cam, &root);
	if (figure)
	{
		newcolor = apply_color_lightness(figure, ray, scene, root);
		free(ray);
		set_up_color(newcolor);
		return (newcolor);
	}
	else
	{
		free(ray);
		return (0);
	}
}
