/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_occurence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:02:15 by melaena           #+#    #+#             */
/*   Updated: 2020/12/05 03:06:17 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first_occurence(char *line, char *occurence, int len)
{
	while (ft_isspace(*line))
		line++;
	if (!occurence)
	{
		while (ft_isalpha(*line))
		{
			line++;
			len--;
		}
		if (len == 0)
			return (1);
		else
			return (0);
	}
	if (!ft_strncmp(line, occurence, ft_strlen(occurence)))
	{
		line += ft_strlen(occurence);
		if (ft_isspace(*line) || !*line)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
