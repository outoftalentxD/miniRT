/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:26:05 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 20:54:49 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int				vector_error(t_point *vector)
{
	if (!vector)
		return (0);
	if (vector->x == 0 && vector->y == 0 && vector->z == 0)
		return (0);
	if (vector->x > 1.0)
		return (1);
	if (vector->x < -1.0)
		return (1);
	if (vector->y > 1.0)
		return (1);
	if (vector->y < -1.0)
		return (1);
	if (vector->z > 1.0)
		return (1);
	if (vector->z < -1.0)
		return (1);
	return (0);
}

int				color_error(t_color *color)
{
	if (!color)
		return (1);
	if (color->r > 255 || color->r < 0)
		return (1);
	if (color->g > 255 || color->g < 0)
		return (1);
	if (color->b > 255 || color->b < 0)
		return (1);
	return (0);
}
