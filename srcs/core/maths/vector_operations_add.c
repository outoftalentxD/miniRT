/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_add.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:23:39 by melaena           #+#    #+#             */
/*   Updated: 2020/12/17 19:19:58 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_point		*vector_mult(t_point *vector, double mult)
{
	vector->x = vector->x * mult;
	vector->y = vector->y * mult;
	vector->z = vector->z * mult;
	return (vector);
}

t_point		*vector_create(t_point *start, t_point *end)
{
	t_point *vector;

	vector = init_point();
	if (!vector)
		return (0);
	vector->x = end->x - start->x;
	vector->y = end->y - start->y;
	vector->z = end->z - start->z;
	return (vector);
}

t_point		*vector_cross_product(t_point *a, t_point *b)
{
	t_point *result;

	result = init_point();
	if (!result)
		return (0);
	result->x = a->y * b->z - a->z * b->y;
	result->y = a->z * b->x - a->x * b->z;
	result->z = a->x * b->y - a->y * b->x;
	return (result);
}

t_point		*get_perpend_vec(t_point *vec)
{
	double a;

	if (vec->x)
	{
		a = vec->y / vec->x * -1;
		if (a == 0)
			a = fabs(a);
		return (new_point(a, 1, 0));
	}
	if (vec->y)
	{
		a = vec->x / vec->y * -1;
		if (a == 0)
			a = fabs(a);
		return (new_point(1, a, 0));
	}
	if (vec->z)
	{
		a = vec->x / vec->z * -1;
		if (a == 0)
			a = fabs(a);
		return (new_point(1, 0, a));
	}
	return (0);
}

double		vector_angle_cos(t_point *vec1, t_point *vec2)
{
	double cos;

	cos = vector_scalar_mult(vec1, vec2);
	cos /= vector_len(vec1);
	cos /= vector_len(vec2);
	return (cos);
}
