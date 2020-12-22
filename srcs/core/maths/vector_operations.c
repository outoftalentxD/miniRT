/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:08:33 by melaena           #+#    #+#             */
/*   Updated: 2020/12/18 05:26:07 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_point			*vector_sum(t_point *vec1, t_point *vec2)
{
	t_point	*vector;

	vector = init_point();
	if (!vector)
		return (0);
	vector->x = vec1->x + vec2->x;
	vector->y = vec1->y + vec2->y;
	vector->z = vec1->z + vec2->z;
	return (vector);
}

t_point			*vector_sub(t_point *vec1, t_point *vec2)
{
	t_point	*vector;

	vec2 = vector_mult(vec2, -1);
	vector = vector_sum(vec1, vec2);
	if (!vector)
	{
		vec2 = vector_mult(vec2, -1);
		return (0);
	}
	vec2 = vector_mult(vec2, -1);
	return (vector);
}

double			vector_scalar_mult(t_point *vec1, t_point *vec2)
{
	double res;

	res = vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;
	return (res);
}

double			vector_len(t_point *vector)
{
	double len;

	len = sqrtf(powf(vector->x, 2) + powf(vector->y, 2) + powf(vector->z, 2));
	return (len);
}

t_point			*vector_normalize(t_point *vector)
{
	double		len;

	len = 0;
	len = vector_len(vector);
	vector->x = vector->x / len;
	vector->y = vector->y / len;
	vector->z = vector->z / len;
	return (vector);
}
