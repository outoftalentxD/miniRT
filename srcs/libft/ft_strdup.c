/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:17:37 by melaena           #+#    #+#             */
/*   Updated: 2020/12/02 22:15:32 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		len;

	if (!s1)
		return (0);
	len = ft_strlen(s1) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (0);
	ft_memcpy(new, s1, len);
	return (new);
}
