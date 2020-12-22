/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:02:03 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 02:34:00 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "header.h"

t_window	*init_window(t_scene *scene, int save);
t_data		*init_image(void);
void		create_new_mlx_image(t_window *window);

double		**camera_to_world(t_cam *cam);
t_point		*get_ray_direction(t_cam *cam,
			t_resolution *resolution, double x, double y);
t_ray		*new_ray(t_point *ray_direction, t_cam *cam);
int			render_scene(t_window *win);
t_color		*trace_ray(int x, int y, t_scene *scene);
t_color		*apply_color_lightness(t_figure *figure,
			t_point *ray, t_scene *scene, double t);

int			is_in_cylinder(t_figure *figure, t_point *point);
int			is_one_side(t_scene *scene, t_figure *figure, t_light *light);
int			cylinder_one_side(t_figure *figure, t_scene *scene, t_light *light);
int			sphere_one_side(t_figure *figure, double dl, double dc);

void		get_square_vertices(t_figure *square);

void		get_triangle_norm_vec(t_figure *triangle);
double		compute_orient(t_point *point, t_point *p1,
			t_point *p2, t_point *norm);

int			check_intersection(t_point *point, t_light *light, t_scene *scene);
t_figure	*ray_intersect(t_point *ray,
			t_figure *figures, t_cam *cam, double *root0);
int			intersect_sphere(t_point *ray,
			t_figure *sphere, t_cam *cam, double *root0);
int			intersect_plane(t_point *ray,
			t_figure *plane, t_cam *cam, double *root0);
int			intersect_cylinder(t_point *ray,
			t_figure *cylinder, t_cam *cam, double *root);
int			intersect_square(t_point *ray,
			t_figure *square, t_cam *cam, double *root0);
int			intersect_triangle(t_point *ray,
			t_figure *triangle, t_cam *cam, double *root0);
int			intersect_disk(t_point *ray,
			t_figure *disk, t_cam *cam, double *root);

t_point		*matrix4x4_vector_mult(double **matrix,
			t_point *vector);
void		compute_pixel_ndc(double *x, double *y,
			t_resolution *res, t_cam *cam);

void		save_bmp(t_window *win);
#endif
