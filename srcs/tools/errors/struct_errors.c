/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:30:44 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 20:38:28 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int				ambient_error(t_ambient *ambient)
{
	if (ambient->ratio < 0.0)
		return (1);
	else if (ambient->ratio > 1.0)
		return (1);
	else if (color_error(ambient->color))
		return (1);
	else
		return (0);
}

int				light_error(t_light *light)
{
	if (light->brightness < 0.0 || light->brightness > 1.0)
		return (1);
	else if (color_error(light->color))
		return (1);
	else
		return (0);
}

int				cam_error(t_cam *cam)
{
	if (cam->vector->x == 0 && cam->vector->z == 0 && cam->vector->y != 0)
		cam->vector->x = 0.0001;
	if (!cam->pos)
		return (1);
	if (vector_error(cam->vector))
		return (1);
	if (cam->fov == -1)
		return (1);
	return (0);
}

int				figure_error(t_figure *figure)
{
	if (!figure->pos && figure->name != TRIANGLE)
		return (1);
	if (color_error(figure->color))
		return (1);
	if (!figure->name)
		return (1);
	if (figure->d < 0)
		return (1);
	if (figure->h < 0)
		return (1);
	if (figure->name == CYLINDER || figure->name == PLANE ||
		figure->name == SQUARE)
		if (vector_error(figure->vector))
			return (1);
	return (0);
}
