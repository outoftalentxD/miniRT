/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:05:25 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 19:49:51 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void				set_up_resolution(t_resolution *resolution)
{
	if (resolution->x > 1920)
		resolution->x = 1920;
	if (resolution->x < 800)
		resolution->x = 800;
	if (resolution->y > 1080)
		resolution->y = 1080;
	if (resolution->y < 600)
		resolution->y = 600;
}

static t_resolution		*create_new_resolution(char *line)
{
	t_resolution	*resolution;
	int				error;

	error = 0;
	resolution = init_resolution();
	if (!resolution)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "R");
	resolution->x = ft_atof_join(&line, &error);
	resolution->y = ft_atof_join(&line, &error);
	check_line_remainder(line, &error);
	if (error > 0)
	{
		free(resolution);
		return (0);
	}
	set_up_resolution(resolution);
	return (resolution);
}

int						add_new_resolution(t_scene *scene, char *line, int *err)
{
	t_resolution	*resolution;

	if (scene->resolution)
	{
		display_error_message(M_RESOLUTION_ERROR, 0);
		*err = -1;
		return (-1);
	}
	resolution = create_new_resolution(line);
	if (!resolution)
	{
		display_error_message(REOLUTION_ERROR, 0);
		*err = -1;
		return (-1);
	}
	scene->resolution = resolution;
	return (0);
}
