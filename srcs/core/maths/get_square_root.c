/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square_root.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:58:44 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 18:18:11 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_point				*vector_create_free(t_point *start, t_point *end)
{
	t_point *vector;

	vector = init_point();
	if (!vector)
		return (0);
	vector->x = end->x - start->x;
	vector->y = end->y - start->y;
	vector->z = end->z - start->z;
	free(vector);
	return (0);
}

static int			ft_free(t_point *elem, int ret)
{
	free(elem);
	return (ret);
}

static double		get_discr(double *a, double *b, double *c, t_point *coef)
{
	double discr;

	*a = coef->x;
	*b = coef->y;
	*c = coef->z;
	discr = *b * *b - 4 * *a * *c;
	return (discr);
}

double				get_square_root(t_point *coef, double *x0, double *x1)
{
	double discr;
	double q;
	double a;
	double b;
	double c;

	discr = get_discr(&a, &b, &c, coef);
	if (discr < 0)
		return (ft_free(coef, -1));
	if (discr == 0)
	{
		*x0 = -0.5 * b / a;
		*x1 = *x0;
		return (ft_free(coef, 0));
	}
	if (b > 0)
		q = -0.5 * (b + sqrtf(discr));
	else
		q = -0.5 * (b - sqrtf(discr));
	*x0 = q / a;
	*x1 = c / q;
	if (*x0 > *x1)
		ft_swapf(x0, x1);
	return (ft_free(coef, 0));
}
