/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 00:13:57 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 20:13:58 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		get_sign(char *str, int *elem)
{
	int		neg;
	int		count;

	neg = 1;
	count = *elem;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			neg = -1;
		else
			neg = 1;
		count++;
	}
	if (elem)
		*elem = count;
	return (neg);
}

int				ft_atoi_join(char **line, double *power, int *error)
{
	int		count;
	int		num;
	int		neg;
	char	*str;

	str = *line;
	count = 0;
	num = 0;
	neg = get_sign(str, &count);
	while (ft_isdigit(str[count]))
	{
		if (num * 10 < num)
		{
			*line = str + count;
			return ((neg < 0) ? 0 : -1);
		}
		num *= 10;
		num += str[count++] - '0';
		if (power)
			(*power)++;
	}
	*line = str + count;
	if (count == 0 && error)
		*error += 1;
	return (num * neg);
}

double			ft_atof_join(char **line, int *error)
{
	double	num;
	double	decimal_places;
	double	power;

	decimal_places = 0;
	power = 1;
	while (ft_isspace(**line))
		(*line)++;
	num = ft_atoi_join(line, 0, error);
	if (**line != '.')
		decimal_places = 0;
	else
	{
		*line += 1;
		decimal_places = ft_atoi_join(line, &power, 0);
		while (--power > 0)
			decimal_places /= 10;
		if (num < 0)
			decimal_places *= -1;
	}
	while (ft_isspace(**line))
		(*line)++;
	if (**line == ',')
		(*line)++;
	return (num + decimal_places);
}

double			ft_atof(char *ptr)
{
	double	num;
	double	decimal_places;
	double	power;

	decimal_places = 0;
	num = ft_atoi(ptr);
	power = 1;
	if (num < 0)
		power = -1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr && *ptr != '.')
		ptr++;
	if (*ptr++ != '.')
		return (num);
	decimal_places = ft_atoi(ptr);
	while (ft_isdigit(*ptr++))
		power /= 10;
	return (num + power * decimal_places);
}
