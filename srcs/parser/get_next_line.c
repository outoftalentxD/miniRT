/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:09:43 by melaena           #+#    #+#             */
/*   Updated: 2020/12/05 11:45:18 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../includes/parser.h"

static int		check_newl(char **storage)
{
	int		count;
	char	*ptr;

	count = 0;
	if (!*storage)
		*storage = ft_strdup("");
	ptr = *storage;
	if (!ptr)
		return (-1);
	while (ptr[count] && ptr[count] != '\n')
		count++;
	if (ptr[count] == '\n')
		return (count);
	else
		return (-1);
}

static char		*get_newline(char **ptr)
{
	int		len;
	char	*new;
	int		start;
	char	*storage;

	storage = *ptr;
	len = check_newl(&storage);
	if (len == -1)
		len = ft_strlen(storage);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	new[len] = 0;
	start = len + storage[len] / 10;
	while (--len > -1)
		new[len] = storage[len];
	*ptr = ft_substr(storage, start, ft_strlen(storage) - start);
	free(storage);
	return (new);
}

static int		ft_free(char *storage, char *buf, int rd)
{
	free(buf);
	if (rd == 0)
		free(storage);
	return (rd);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*storage = 0;
	int			rd;
	char		*leaked;

	rd = 0;
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)) ||
		fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	buf[BUFFER_SIZE] = 0;
	while (check_newl(&storage) == -1)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (-1);
		if (rd == 0 || !buf)
			break ;
		buf[rd] = 0;
		leaked = storage;
		storage = ft_strjoin(leaked, buf);
		free(leaked);
	}
	*line = get_newline(&storage);
	return (ft_free(storage, buf, rd));
}
