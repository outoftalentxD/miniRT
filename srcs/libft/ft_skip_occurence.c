/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_occurence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:43:13 by melaena           #+#    #+#             */
/*   Updated: 2020/12/05 03:06:01 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_skip_occurence_and_whitespaces(char **line, char *occurence)
{
	while (ft_isspace(**line) || ft_isinstr(**line, occurence))
		(*line)++;
}
