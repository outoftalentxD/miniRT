/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:18:59 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 20:59:17 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void				add_light_to_lighting(t_light *light,
					t_point *lightning, double intensity)
{
	lightning->x += (double)light->color->r / 255
		* intensity * light->brightness;
	lightning->y += (double)light->color->g / 255
		* intensity * light->brightness;
	lightning->z += (double)light->color->b / 255
		* intensity * light->brightness;
}

void				add_ambient_to_lightning(t_ambient *amb, t_point *lightning)
{
	lightning->x += (double)amb->color->r / 255 * amb->ratio * 0.3;
	lightning->y += (double)amb->color->g / 255 * amb->ratio * 0.3;
	lightning->z += (double)amb->color->b / 255 * amb->ratio * 0.3;
}

t_color				*apply_lightning(t_color *color, t_point *lightning)
{
	t_color *new;

	new = init_color();
	new->r = color->r * lightning->x;
	new->g = color->g * lightning->y;
	new->b = color->b * lightning->z;
	free(lightning);
	return (new);
}

t_color				*apply_col_shade_intensity(t_color *color, double intensity)
{
	t_color *new;

	new = new_color(color->r, color->g, color->b);
	new->r *= intensity;
	new->g *= intensity;
	new->b *= intensity;
	set_up_color(new);
	return (new);
}

unsigned int		convert_rgb_to_hex(t_color *color)
{
	unsigned int	ret;

	ret = 0;
	ret += color->r / 16 * pow(16, 5) +
		(color->r - color->r / 16 * 16) * pow(16, 4);
	ret += color->g / 16 * pow(16, 3) +
		(color->g - color->g / 16 * 16) * pow(16, 2);
	ret += color->b / 16 * pow(16, 1) +
		(color->b - color->b / 16 * 16) * pow(16, 0);
	return (ret);
}
