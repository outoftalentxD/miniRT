/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:47:39 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 19:42:10 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_color			*new_color(int r, int g, int b)
{
	t_color *color;

	color = init_color();
	if (!color)
		return (0);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

void			set_up_color(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->r < 0)
		color->r = 0;
	if (color->g > 255)
		color->g = 255;
	if (color->g < 0)
		color->g = 0;
	if (color->b > 255)
		color->b = 255;
	if (color->b < 0)
		color->b = 0;
}

t_color			*get_color(char **line)
{
	t_color		*color;
	int			error;

	error = 0;
	color = init_color();
	if (!color)
		return (0);
	color->r = ft_atof_join(line, &error);
	color->g = ft_atof_join(line, &error);
	color->b = ft_atof_join(line, &error);
	if (error > 0 || color_error(color))
		return (0);
	set_up_color(color);
	return (color);
}

t_point			*get_point(char **line)
{
	t_point *pos;
	int		error;

	error = 0;
	if (!(*line))
		return (0);
	if (**line == 'c')
		(*line)++;
	pos = init_point();
	while (ft_isspace(**line))
		(*line)++;
	pos->x = ft_atof_join(line, &error);
	pos->y = ft_atof_join(line, &error);
	pos->z = ft_atof_join(line, &error);
	if (error > 0)
		return (0);
	return (pos);
}
