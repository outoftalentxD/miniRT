/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:40:27 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 01:52:21 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_point		*init_point(void)
{
	t_point		*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (0);
	point->x = 0;
	point->y = 0;
	point->z = 0;
	return (point);
}

t_ambient	*init_ambient(void)
{
	t_ambient	*ambient;

	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (!ambient)
		return (0);
	ambient->ratio = 0;
	ambient->color = 0;
	return (ambient);
}

t_cam		*init_cam(void)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		return (0);
	cam->fov = 0;
	cam->pos = 0;
	cam->vector = 0;
	cam->next = 0;
	cam->forward = 0;
	cam->right = 0;
	cam->up = 0;
	return (cam);
}

t_light		*init_light(void)
{
	t_light *light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (0);
	light->pos = 0;
	light->color = 0;
	light->brightness = 0;
	light->next = 0;
	return (light);
}

t_scene		*init_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (0);
	scene->resolution = 0;
	scene->cam = 0;
	scene->light = 0;
	scene->ambient = 0;
	scene->figures = 0;
	scene->first_cam = 0;
	return (scene);
}
