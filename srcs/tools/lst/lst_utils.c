/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:38:49 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 01:49:50 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_figure			*init_figure(void)
{
	t_figure *figure;

	figure = (t_figure *)malloc(sizeof(t_figure));
	if (!figure)
		return (0);
	figure->next = 0;
	figure->d = 0;
	figure->h = 0;
	figure->name = 0;
	figure->pos = 0;
	figure->vector = 0;
	figure->color = 0;
	figure->p1 = 0;
	figure->p2 = 0;
	figure->p3 = 0;
	figure->v1 = 0;
	figure->v2 = 0;
	figure->v3 = 0;
	figure->v4 = 0;
	return (figure);
}

t_resolution		*init_resolution(void)
{
	t_resolution	*resolution;

	resolution = (t_resolution *)malloc(sizeof(t_resolution));
	if (!resolution)
		return (0);
	resolution->x = 0;
	resolution->y = 0;
	return (resolution);
}

void				lst_addback_cam(t_cam **cam, t_cam *newcam)
{
	t_cam *temp;

	if (!cam)
		return ;
	if (!*cam)
	{
		*cam = newcam;
		return ;
	}
	temp = *cam;
	while (temp->next)
		temp = temp->next;
	temp->next = newcam;
	return ;
}

void				lst_addback_light(t_light **lights, t_light *light)
{
	t_light	*temp;

	if (!lights)
		return ;
	if (!*lights)
	{
		*lights = light;
		return ;
	}
	temp = *lights;
	while (temp->next)
		temp = temp->next;
	temp->next = light;
	return ;
}

void				lst_addback_figure(t_figure **figures, t_figure *figure)
{
	t_figure	*temp;

	if (!figures)
		return ;
	if (!*figures)
	{
		*figures = figure;
		return ;
	}
	temp = *figures;
	while (temp->next)
		temp = temp->next;
	temp->next = figure;
	return ;
}
