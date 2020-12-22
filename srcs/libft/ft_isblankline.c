/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblankline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:16:37 by melaena           #+#    #+#             */
/*   Updated: 2020/12/03 21:51:22 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblankline(char *ptr)
{
	if (!ptr)
		return (0);
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == 0)
		return (1);
	else
		return (0);
}
