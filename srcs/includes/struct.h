/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:57:13 by melaena           #+#    #+#             */
/*   Updated: 2020/12/18 20:12:58 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** struct contains info about mlx image
** image - mlx image;
** addr - adress; idk
** endian smth bout image conf
*/
typedef struct			s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}						t_data;

/*
** struct contains info about x0y0 x1y1
** start and end of line
** null if error occured
*/
typedef struct			s_line
{
	int x1;
	int y1;
	int x0;
	int y0;
}						t_line;

/*
** struct contains info about xy point coords
** null if error occured
*/
typedef struct			s_dot
{
	int		x;
	int		y;
}						t_dot;

/*
** struct contains info about xyz point coords
** null if error occured
*/
typedef struct			s_point
{
	double	x;
	double	y;
	double	z;
}						t_point;

/*
** MAKE set_up_color() !!
** struct contains info about RGB color
** error if color->x > 255 || color->x < 0
** null if error occured
*/
typedef struct			s_color
{
	int	r;
	int	g;
	int	b;
}						t_color;

/*
** struct contains info about resolution
** min resolution -	 800 x 600
** max reoslution - 1920 x 1080
** null if error occured
*/
typedef struct			s_resolution
{
	int x;
	int y;
}						t_resolution;

/*
** struct contains info about ambient
** null if error occured
*/
typedef struct			s_ambient
{
	double		ratio;
	t_color		*color;
}						t_ambient;

/*
** struct contains info about cam
** in scene we have chained list of cameras
** null if error occured
*/
typedef struct			s_cam
{
	struct s_point	*pos;
	struct s_point	*vector;
	double			fov;
	struct s_cam	*next;
	t_point			*forward;
	t_point			*right;
	t_point			*up;
}						t_cam;

/*
** struct contains info about light
** in scene we have chained list of ligts
** null if error occured
*/
typedef struct			s_light
{
	t_point			*pos;
	t_color			*color;
	double			brightness;
	struct s_light	*next;
}						t_light;

/*
** struct contains info about figure
** in scene we have chained list of figures
** null if error occured
*/
typedef struct			s_figure
{
	int				name;
	t_point			*pos;
	t_point			*vector;
	t_color			*color;
	double			d;
	double			h;
	t_point			*p1;
	t_point			*p2;
	t_point			*p3;
	t_point			*v1;
	t_point			*v2;
	t_point			*v3;
	t_point			*v4;
	struct s_figure	*next;
}						t_figure;

/*
** struct contains file.rt params
** null if error occured
*/
typedef struct			s_scene
{
	t_resolution	*resolution;
	t_light			*light;
	t_ambient		*ambient;
	t_cam			*cam;
	t_figure		*figures;
	t_cam			*first_cam;
}						t_scene;

/*
** info about ray
** should delete
*/
typedef struct			s_ray
{
	t_point	*origin;
	t_point	*dir;
}						t_ray;

/*
** struct contains info bout window;
** rt scene and mlx stuff;
** null if error occured
*/
typedef struct			s_window
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	t_scene	*scene;
}						t_window;

/*
** orient of figure
** if orient's for some point
** are same sign, then point
** is in figure
*/
typedef	struct			s_orient
{
	double o1;
	double o2;
	double o3;
	double o4;
}						t_orient;

/*
** 3 vec's for some
** new frame
*/
typedef	struct			s_frame
{
	t_point *x;
	t_point *y;
	t_point *z;
}						t_frame;
#endif
