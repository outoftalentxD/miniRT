/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:28:02 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 18:04:30 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		emancipate_all(t_window *win)
{
	mlx_destroy_image(win->mlx, win->img->img);
	mlx_clear_window(win->mlx, win->mlx_win);
	mlx_destroy_window(win->mlx, win->mlx_win);
	emancipate_scene(win->scene);
	free(win->img);
	free(win);
	win = 0;
	return (0);
}

void	new_render(t_window *win)
{
	mlx_destroy_image(win->mlx, win->img->img);
	win->img->img = mlx_new_image(win->mlx,
			win->scene->resolution->x, win->scene->resolution->y);
	win->img->addr = mlx_get_data_addr(win->img->img,
			&win->img->bits_per_pixel,
			&win->img->line_length, &win->img->endian);
	render_scene(win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img->img, 0, 0);
}

int		key_hook(int key, void *param)
{
	t_window	*win;

	win = (t_window *)param;
	if (key == 53)
	{
		emancipate_all(win);
		exit(0);
	}
	if (key == 49)
	{
		switch_camera(win);
		new_render(win);
	}
	return (0);
}

int		ft_close(void *param)
{
	t_window *win;

	win = (t_window *)param;
	emancipate_all(win);
	exit(0);
}

void	switch_camera(t_window *win)
{
	t_cam *cam;

	cam = win->scene->cam;
	cam = cam->next;
	if (!cam)
		cam = win->scene->first_cam;
	win->scene->cam = cam;
	return ;
}
