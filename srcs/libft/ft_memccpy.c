/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:08:06 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:31:00 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int count;

	count = 0;
	while (n--)
	{
		((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
		if (((unsigned char *)src)[count] == (unsigned char)c)
			return ((unsigned char *)(dest + count + 1));
		count++;
	}
	return (NULL);
}
