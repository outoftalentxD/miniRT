/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:50:34 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 19:47:45 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define BUFFER_SIZE 1

# include "header.h"

int						get_next_line(int fd, char **line);

int						add_new_resolution(t_scene *scene,
						char *line, int *err);
int						add_new_ambient(t_scene *scene, char *line, int *err);
int						add_new_light(t_scene *scene, char *line, int *err);
int						add_new_cam(t_scene *scene, char *line, int *err);
int						add_new_figure(t_scene *scene, char *line, int *err);

t_figure				*create_new_sphere(char *line);
t_figure				*create_new_plane(char *line);
t_figure				*create_new_square(char *line);
t_figure				*create_new_cylinder(char *line);
t_figure				*create_new_triangle(char *line);
t_figure				*create_new_disk(t_point *point, t_point *vec,
						t_color *color, double rad);
int						add_disk_to_figures(t_figure *figure, t_scene *scene);

t_point					*get_point(char **line);
t_color					*get_color(char **line);

t_scene					*parse_scene(char *filename);
int						args_error(char **av, int ac, int *save);
void					check_line_remainder(char *line, int *err);

#endif
