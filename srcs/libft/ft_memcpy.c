/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:56:26 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:30:45 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int count;

	if (dest == 0 && src == 0)
		return (0);
	count = -1;
	while (n-- && ++count != -1)
		((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
	return (dest);
}
