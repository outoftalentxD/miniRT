/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:22:42 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 20:08:18 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_figure		*create_new_sphere(char *line)
{
	int			error;
	t_figure	*sphere;

	error = 0;
	sphere = init_figure();
	if (!sphere)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "sp");
	sphere->name = SPHERE;
	sphere->pos = get_point(&line);
	sphere->d = ft_atof_join(&line, &error);
	sphere->color = get_color(&line);
	check_line_remainder(line, &error);
	if (error > 0 || figure_error(sphere))
	{
		emancipate_figure(sphere);
		display_error_message(SPHERE_ERROR, 0);
		return (0);
	}
	return (sphere);
}

t_figure		*create_new_plane(char *line)
{
	int			error;
	t_figure	*plane;

	error = 0;
	plane = init_figure();
	if (!plane)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "pl");
	plane->name = PLANE;
	plane->pos = get_point(&line);
	plane->vector = get_point(&line);
	plane->color = get_color(&line);
	check_line_remainder(line, &error);
	if (error > 0 || figure_error(plane))
	{
		emancipate_figure(plane);
		display_error_message(PLANE_ERROR, 0);
		return (0);
	}
	return (plane);
}

t_figure		*create_new_square(char *line)
{
	int			error;
	t_figure	*square;

	error = 0;
	square = init_figure();
	if (!square)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "sq");
	square->name = SQUARE;
	square->pos = get_point(&line);
	square->vector = get_point(&line);
	square->d = ft_atof_join(&line, &error);
	square->color = get_color(&line);
	check_line_remainder(line, &error);
	if (error > 0 || figure_error(square))
	{
		emancipate_figure(square);
		display_error_message(SQUARE_ERROR, 0);
		return (0);
	}
	get_square_vertices(square);
	return (square);
}

t_figure		*create_new_cylinder(char *line)
{
	int			error;
	t_figure	*cylinder;

	error = 0;
	cylinder = init_figure();
	if (!cylinder)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "cy");
	cylinder->name = CYLINDER;
	cylinder->pos = get_point(&line);
	cylinder->vector = get_point(&line);
	cylinder->color = get_color(&line);
	cylinder->d = ft_atof_join(&line, &error);
	cylinder->h = ft_atof_join(&line, &error);
	check_line_remainder(line, &error);
	if (error > 0 || figure_error(cylinder))
	{
		emancipate_figure(cylinder);
		display_error_message(CYLINDER_ERROR, 0);
		return (0);
	}
	cylinder->d = cylinder->d / 2;
	return (cylinder);
}

t_figure		*create_new_triangle(char *line)
{
	int			error;
	t_figure	*triangle;

	error = 0;
	triangle = init_figure();
	if (!triangle)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "tr");
	triangle->name = TRIANGLE;
	triangle->p1 = get_point(&line);
	triangle->p2 = get_point(&line);
	triangle->p3 = get_point(&line);
	triangle->color = get_color(&line);
	check_line_remainder(line, &error);
	if (error > 0 || figure_error(triangle))
	{
		emancipate_figure(triangle);
		display_error_message(TRIANGLE_ERROR, 0);
		return (0);
	}
	get_triangle_norm_vec(triangle);
	return (triangle);
}
