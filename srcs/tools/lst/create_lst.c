/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:40:27 by melaena           #+#    #+#             */
/*   Updated: 2020/12/03 21:56:52 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_point		*new_point(double x, double y, double z)
{
	t_point		*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (0);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_ambient	*new_ambient(double ratio, t_color *color)
{
	t_ambient	*ambient;

	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (!ambient)
		return (0);
	ambient->ratio = ratio;
	ambient->color = color;
	return (ambient);
}

t_light		*new_light(t_point *pos, t_color *color, double brightness)
{
	t_light *light;

	light = (t_light *)malloc(sizeof(light));
	if (!light)
		return (0);
	light->pos = pos;
	light->color = color;
	light->brightness = brightness;
	return (light);
}

t_scene		*new_scene(t_cam *cam, t_light *light,
			t_ambient *ambient, t_figure *figures)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (0);
	scene->cam = cam;
	scene->light = light;
	scene->ambient = ambient;
	scene->figures = figures;
	return (0);
}

t_color		*init_color(void)
{
	t_color		*color;

	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		return (0);
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
