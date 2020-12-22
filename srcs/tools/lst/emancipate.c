/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emancipate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:04 by melaena           #+#    #+#             */
/*   Updated: 2020/12/18 20:13:06 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	emancipate_figure(t_figure *figure)
{
	if (!figure)
		return ;
	free(figure->pos);
	free(figure->vector);
	free(figure->color);
	free(figure->p1);
	free(figure->p2);
	free(figure->p3);
	free(figure->v1);
	free(figure->v2);
	free(figure->v3);
	free(figure->v4);
	free(figure);
	figure = 0;
}

void	emancipate_figure_all(t_figure **figures)
{
	t_figure *temp;
	t_figure *figure;

	figure = *figures;
	while (figure)
	{
		temp = figure;
		figure = figure->next;
		emancipate_figure(temp);
	}
	*figures = 0;
}

void	emancipate_cam(t_cam *cam)
{
	free(cam->pos);
	free(cam->vector);
	free(cam->forward);
	free(cam->right);
	free(cam->up);
	free(cam);
	cam = 0;
}

void	emancipate_cam_all(t_cam **elem)
{
	t_cam	*temp;
	t_cam	*cam;

	cam = *elem;
	while (cam)
	{
		temp = cam;
		cam = cam->next;
		emancipate_cam(temp);
	}
	*elem = 0;
}

void	emancipate_light_all(t_light **elem)
{
	t_light	*temp;
	t_light	*light;

	light = *elem;
	while (light)
	{
		temp = light;
		light = light->next;
		free(temp->color);
		free(temp->pos);
		free(temp);
	}
	*elem = 0;
}
