/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:10 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 20:58:15 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void				put_pixel(t_data *image, int x, int y, t_color *color)
{
	char			*dst;
	unsigned int	hexcolor;

	hexcolor = convert_rgb_to_hex(color);
	dst = image->addr + (y * image->line_length
		+ x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = hexcolor;
}

int					render_scene(t_window *win)
{
	t_data	*img;
	t_scene *scene;
	int		x;
	int		y;
	t_color	*color;

	x = 0;
	y = 0;
	scene = win->scene;
	img = win->img;
	while (x < scene->resolution->x)
	{
		y = -1;
		while (++y < scene->resolution->y)
		{
			color = trace_ray(x, y, scene);
			if (!color)
				continue;
			put_pixel(img, x, y, color);
			free(color);
		}
		x++;
	}
	return (0);
}
