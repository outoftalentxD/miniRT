/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_sym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:11:58 by melaena           #+#    #+#             */
/*   Updated: 2020/12/05 03:07:50 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first_sym(char *line, int c)
{
	if (!line)
		return (0);
	while (ft_isspace(*line))
		line++;
	if (*line == c)
		return (1);
	else
		return (0);
}
