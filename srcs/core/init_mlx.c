/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:34:16 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 18:00:54 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_data		*init_image(void)
{
	t_data *image;

	image = (t_data *)malloc(sizeof(t_data));
	if (!image)
		return (0);
	return (image);
}

void		create_new_mlx_image(t_window *window)
{
	t_data	*image;
	t_scene *scene;

	scene = window->scene;
	image = init_image();
	image->img = mlx_new_image(window->mlx,
		scene->resolution->x, scene->resolution->y);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
				&image->line_length, &image->endian);
	window->img = image;
	return ;
}

t_window	*init_window(t_scene *scene, int save)
{
	t_window	*window;
	void		*mlx;
	t_data		*image;

	if (!scene)
		return (0);
	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		return (0);
	mlx = mlx_init();
	window->mlx = mlx;
	window->mlx_win = 0;
	image = init_image();
	image->img = mlx_new_image(mlx, scene->resolution->x, scene->resolution->y);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
				&image->line_length, &image->endian);
	window->img = image;
	window->scene = scene;
	if (save == 1)
		return (window);
	window->mlx_win = mlx_new_window(mlx,
			scene->resolution->x, scene->resolution->y, "hehe");
	return (window);
}
