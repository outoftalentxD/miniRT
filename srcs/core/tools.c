/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:14:57 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 23:20:29 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			sphere_one_side(t_figure *figure, double dl, double dc)
{
	if (dl <= figure->d / 2 &&
		dc <= figure->d / 2)
		return (1);
	else if (dl > figure->d / 2 &&
		dc > figure->d / 2)
		return (1);
	else
		return (0);
}

int			cylinder_one_side(t_figure *figure, t_scene *scene, t_light *light)
{
	if (is_in_cylinder(figure, scene->cam->pos) &&
		is_in_cylinder(figure, light->pos))
		return (1);
	else if (!is_in_cylinder(figure, scene->cam->pos) &&
		!is_in_cylinder(figure, light->pos))
		return (1);
	else
		return (0);
}
