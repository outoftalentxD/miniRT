/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:47:27 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 19:51:11 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_ambient		*create_new_ambient(char *line)
{
	int			error;
	t_ambient	*ambient;

	error = 0;
	ambient = init_ambient();
	if (!ambient)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "A");
	ambient->ratio = ft_atof_join(&line, &error);
	ambient->color = get_color(&line);
	check_line_remainder(line, &error);
	if (error > 0 || ambient_error(ambient))
	{
		display_error_message(AMBIENT_ERROR, 0);
		free(ambient->color);
		free(ambient);
		return (0);
	}
	return (ambient);
}

int						add_new_ambient(t_scene *scene, char *line, int *err)
{
	t_ambient *ambient;

	if (scene->ambient)
	{
		display_error_message(M_AMBIENT_ERROR, 0);
		*err = -1;
		return (-1);
	}
	ambient = create_new_ambient(line);
	if (!ambient)
		return ((*err = -1));
	scene->ambient = ambient;
	return (0);
}

static int				option_error(char *option, int *save)
{
	if (!option)
		return (0);
	if (!ft_strcmp(option, "--save"))
	{
		*save = 1;
		return (0);
	}
	return (1);
}

static int				filename_error(char *filename)
{
	while (*filename && *filename != '.')
		filename++;
	if (*filename == 0)
		return (1);
	if (!ft_strcmp(filename, ".rt"))
		return (0);
	return (1);
}

int						args_error(char **av, int ac, int *save)
{
	char	*filename;
	char	*option;

	if (ac < 2 || ac > 3)
		return (1);
	if (ac == 2)
	{
		filename = av[1];
		option = 0;
	}
	else
	{
		filename = av[1];
		option = av[2];
	}
	if (option_error(option, save) || filename_error(filename))
		return (1);
	return (0);
}
