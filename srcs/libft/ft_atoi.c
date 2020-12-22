/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:38:31 by melaena           #+#    #+#             */
/*   Updated: 2020/12/05 02:51:20 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_isspace(char str)
{
	if (str == '\t' ||
		str == '\n' ||
		str == '\v' ||
		str == '\f' ||
		str == '\r' ||
		str == ' ')
		return (1);
	else
		return (0);
}

static int		ft_isnumeric(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int		count;
	int		num;
	int		neg;

	count = 0;
	num = 0;
	neg = 1;
	while (ft_isspace(str[count]))
		count++;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			neg = -1;
		else
			neg = 1;
		count++;
	}
	while (ft_isnumeric(str[count]))
	{
		if (num * 10 < num)
			return ((neg < 0) ? 0 : -1);
		num *= 10;
		num += str[count++] - '0';
	}
	return (num * neg);
}
