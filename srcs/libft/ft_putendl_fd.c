/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:09:21 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:31:43 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int count;
	int len;

	if (!s)
		return ;
	len = ft_strlen(s);
	count = -1;
	while (++count < len)
		write(fd, &s[count], 1);
	write(fd, "\n", 1);
}
