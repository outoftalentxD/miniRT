/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:02:51 by melaena           #+#    #+#             */
/*   Updated: 2020/12/18 20:28:57 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void			write_fileheader(int fd, t_window *win, int padding)
{
	char	*line;
	int		file_size;

	line = ft_calloc(14, sizeof(char));
	if (!line)
		return ;
	file_size = win->scene->resolution->y * (win->scene->resolution->x *
			win->img->bits_per_pixel / 8 + padding) + 54;
	line[0] = 'B';
	line[1] = 'M';
	line[2] = file_size;
	line[3] = file_size / 256;
	line[4] = file_size / 256 / 256;
	line[5] = file_size / 256 / 256 / 256;
	line[10] = 54;
	write(fd, line, 14);
	free(line);
}

void			write_infoheader(int fd, t_window *win)
{
	char	*line;

	line = ft_calloc(40, sizeof(char));
	if (!line)
		return ;
	line[0] = 40;
	line[4] = win->scene->resolution->x;
	line[5] = win->scene->resolution->x / 256;
	line[6] = win->scene->resolution->x / 256 / 256;
	line[7] = win->scene->resolution->x / 256 / 256 / 256;
	line[8] = win->scene->resolution->y;
	line[9] = win->scene->resolution->y / 256;
	line[10] = win->scene->resolution->y / 256 / 256;
	line[11] = win->scene->resolution->y / 256 / 256 / 256;
	line[12] = 1;
	line[14] = win->img->bits_per_pixel;
	write(fd, line, 40);
	free(line);
}

void			save_bmp(t_window *win)
{
	int		fd;
	int		padding;
	int		x;
	int		y;
	int		pad;

	pad = 0;
	y = win->scene->resolution->y;
	fd = open("image.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		return ;
	padding = (4 - (win->scene->resolution->x *
		win->img->bits_per_pixel / 8) % 4) % 4;
	write_fileheader(fd, win, padding);
	write_infoheader(fd, win);
	while (y-- >= 0)
	{
		x = -1;
		while (++x < win->scene->resolution->x)
			write(fd, win->img->addr + (x * win->img->bits_per_pixel / 8)
				+ y * win->img->line_length, win->img->bits_per_pixel / 8);
		write(fd, &pad, padding);
	}
}
