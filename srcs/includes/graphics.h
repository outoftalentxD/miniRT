/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:21:59 by melaena           #+#    #+#             */
/*   Updated: 2020/12/21 20:57:24 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "header.h"

void				add_light_to_lighting(t_light *light,
					t_point *lightning, double intensity);
void				add_ambient_to_lightning(t_ambient *amb,
					t_point *lightning);
t_color				*apply_lightning(t_color *color, t_point *lightning);
t_color				*apply_col_shade_intensity(t_color *color,
					double intensity);

unsigned int		convert_rgb_to_hex(t_color *color);
void				put_pixel(t_data *image, int x, int y, t_color *color);

#endif
