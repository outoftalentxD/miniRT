/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:15:53 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 02:14:26 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define FD_ERROR 			"fd_error"
# define SCENE_ERROR		"scene_error. few elements"
# define CAM_ERROR 			"wrong_cam_params"
# define AMBIENT_ERROR 		"wrong_ambient_params"
# define M_AMBIENT_ERROR	"multiply_ambient_types"
# define REOLUTION_ERROR 	"wrong_resolution_params"
# define M_RESOLUTION_ERROR	"multiply_resolution_types"
# define LIGHT_ERROR 		"wrong_light_params"
# define SPHERE_ERROR		"wrong_sphere_params"
# define PLANE_ERROR 		"wrong_plane_params"
# define SQUARE_ERROR 		"wrong_square_params"
# define CYLINDER_ERROR		"wrong_cylinder_params"
# define TRIANGLE_ERROR		"wrong_triangle_params"
# define WRONG_INPUT_FILES	"wrong_input_files"
# define SAVE_OPT			"wrong_--save_use"
# define BMPFD_ERROR		"cannot save image.bmp fd_error"
# define WRONG_RT_FILE		"wrong .rt file. Undefined symbols"

# include "header.h"
# include "struct.h"

int				display_error_message(char *message, int ret);

int				ambient_error(t_ambient *ambient);
int				cam_error(t_cam *cam);
int				light_error(t_light *light);
int				figure_error(t_figure *figure);

void			set_up_color(t_color *color);
int				vector_error(t_point *vector);
int				color_error(t_color *color);
int				scene_validation_error(t_scene *scene);

void			lst_addback_figure(t_figure **figures, t_figure *figure);
void			lst_addback_cam(t_cam **cam, t_cam *newcam);
void			lst_addback_light(t_light **lights, t_light *light);

void			emancipate_cam(t_cam *cam);
void			emancipate_cam_all(t_cam **elem);
void			emancipate_light_all(t_light **elem);
void			emancipate_figure(t_figure *figure);
void			emancipate_figure_all(t_figure **figures);
t_scene			*emancipate_scene(t_scene *scene);

t_point			*init_point(void);
t_ambient		*init_ambient(void);
t_cam			*init_cam(void);
t_light			*init_light(void);
t_scene			*init_scene(void);
t_figure		*init_figure(void);
t_color			*init_color(void);
t_resolution	*init_resolution(void);

t_point			*new_point(double x, double y, double z);
t_color			*new_color(int r, int g, int b);
t_ambient		*new_ambient(double ratio, t_color *color);
t_cam			*new_cam(t_point *pos, t_point *vector, double fov);
t_light			*new_light(t_point *pos, t_color *color, double brightness);
t_scene			*new_scene(t_cam *cam, t_light *light,
				t_ambient *ambient, t_figure *figures);

int				emancipate_all(t_window *win);
void			new_render(t_window *win);
int				ft_close(void *param);
int				key_hook(int key, void *param);
void			switch_camera(t_window *win);

#endif
