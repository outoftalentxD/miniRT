/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:19:31 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 20:06:39 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_figure		*get_figure(char *line)
{
	t_figure	*figure;

	if (ft_first_occurence(line, "sp", 0))
		figure = create_new_sphere(line);
	else if (ft_first_occurence(line, "pl", 0))
		figure = create_new_plane(line);
	else if (ft_first_occurence(line, "sq", 0))
		figure = create_new_square(line);
	else if (ft_first_occurence(line, "cy", 0))
		figure = create_new_cylinder(line);
	else if (ft_first_occurence(line, "tr", 0))
		figure = create_new_triangle(line);
	else
		figure = 0;
	if (!figure)
		return (0);
	else
		return (figure);
}

t_figure			*create_new_disk(t_point *point, t_point *vec,
					t_color *color, double rad)
{
	t_figure *new;

	new = init_figure();
	if (!new)
		return (0);
	new->name = DISK;
	new->pos = point;
	new->vector = vec;
	new->d = rad;
	new->color = new_color(color->r, color->g, color->b);
	new->next = 0;
	return (new);
}

int					add_disk_to_figures(t_figure *figure, t_scene *scene)
{
	t_figure	*d1;
	t_figure	*d2;
	t_point		*pos1;
	t_point		*pos2;

	vector_normalize(figure->vector);
	pos1 = vector_sum(figure->pos, vector_mult(figure->vector, figure->h / 2));
	vector_normalize(figure->vector);
	pos2 = vector_sub(figure->pos, vector_mult(figure->vector, figure->h / 2));
	vector_normalize(figure->vector);
	d1 = create_new_disk(pos1, new_point(figure->vector->x,
		figure->vector->y, figure->vector->z), figure->color, figure->d);
	d2 = create_new_disk(pos2, new_point(figure->vector->x,
		figure->vector->y, figure->vector->z), figure->color, figure->d);
	lst_addback_figure(&(scene->figures), d1);
	lst_addback_figure(&(scene->figures), d2);
	return (1);
}

int					add_new_figure(t_scene *scene, char *line, int *err)
{
	t_figure	*figure;

	figure = get_figure(line);
	if (!figure)
	{
		emancipate_figure_all(&(scene->figures));
		*err = -1;
		return (-1);
	}
	lst_addback_figure(&(scene->figures), figure);
	if (figure->name == CYLINDER)
		add_disk_to_figures(figure, scene);
	return (0);
}
