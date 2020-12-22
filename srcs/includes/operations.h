/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:16:00 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 02:28:04 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "header.h"
# define SQUARE_ROOT_ERROR "doubleing point exception, a = 0"

double			get_square_root(t_point *coef, double *x0, double *x1);
t_point			*vector_mult(t_point *vector, double mult);
t_point			*vector_sub(t_point *vec1, t_point *vec2);
t_point			*vector_sum(t_point *vec1, t_point *vec2);
double			vector_scalar_mult(t_point *vec1, t_point *vec2);
double			vector_len(t_point *vector);
t_point			*vector_normalize(t_point *vector);
t_point			*vector_create(t_point *start, t_point *end);
t_point			*vector_cross_product(t_point *vec1, t_point *vec2);
int				is_collinear(t_point *vec1, t_point *vec2);
double			vector_angle_cos(t_point *vec1, t_point *vec2);
t_point			*get_perpend_vec(t_point *vec);
t_point			*vector_create_free(t_point *start, t_point *end);

t_point			*compute_up_axis(t_point *forward, t_point *right);
t_point			*compute_right_axis(t_point *forward);
t_point			*compute_forward_axis(t_cam *cam);
#endif
