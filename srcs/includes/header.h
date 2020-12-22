/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:28:56 by melaena           #+#    #+#             */
/*   Updated: 2020/12/18 18:18:18 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define SPHERE		100001
# define PLANE		100010
# define SQUARE		100100
# define CYLINDER	101000
# define TRIANGLE	110000
# define DISK		111111

# define FILEHEADER 14
# define INFOHEADER	40

# define RED		0x00FF0000

# include "struct.h"
# include "tools.h"
# include "parser.h"
# include "graphics.h"
# include "core.h"
# include "operations.h"
# include "../libft/libft.h"

void	print_scene(t_scene *scene);
void	print_figure(t_figure *figure);
void	print_point(t_point *point);
void	print_color(t_color *color);
void	print_matrix4x4(double **matrix);

#endif
