/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:27:26 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 18:17:44 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	ft_exit(t_window *win)
{
	emancipate_scene(win->scene);
	mlx_destroy_image(win->mlx, win->img->img);
	free(win->img);
	free(win->mlx_win);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_scene		*scene;
	char		*filename;
	t_window	*win;
	int			save;

	save = 0;
	if (args_error(argv, argc, &save))
		return (display_error_message(WRONG_INPUT_FILES, 0));
	filename = argv[1];
	scene = parse_scene(filename);
	if (!scene)
		return (0);
	win = init_window(scene, save);
	render_scene(win);
	if (save == 1)
	{
		save_bmp(win);
		ft_exit(win);
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img->img, 0, 0);
	mlx_key_hook(win->mlx_win, key_hook, win);
	mlx_hook(win->mlx_win, 17, 1, ft_close, win);
	mlx_loop(win->mlx);
	return (0);
}
