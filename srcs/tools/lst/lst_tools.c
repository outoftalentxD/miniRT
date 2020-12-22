/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:53:58 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 20:04:37 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_scene		*emancipate_scene(t_scene *scene)
{
	if (!scene)
		return (0);
	free(scene->resolution);
	if (scene->ambient)
	{
		free(scene->ambient->color);
		free(scene->ambient);
	}
	if (scene->figures)
		emancipate_figure_all(&(scene->figures));
	if (scene->first_cam)
		emancipate_cam_all(&(scene->first_cam));
	if (scene->light)
		emancipate_light_all(&(scene->light));
	free(scene);
	scene = 0;
	return (0);
}

int			scene_validation_error(t_scene *scene)
{
	if (!scene->resolution)
		return (1);
	if (!scene->ambient)
		return (1);
	if (!scene->cam)
		return (1);
	if (!scene->light)
		return (1);
	if (!scene->figures)
		return (1);
	return (0);
}
