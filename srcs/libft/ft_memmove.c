/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:26:24 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:31:14 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *dt;
	unsigned char *sc;

	dt = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (dt <= sc)
		ft_memcpy(dt, sc, len);
	else
		while (len--)
			dt[len] = sc[len];
	return (dest);
}
