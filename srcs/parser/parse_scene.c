/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:36:01 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 20:01:14 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void				check_line_remainder(char *line, int *err)
{
	while (ft_isspace(*line))
		line++;
	if (*line == 0)
		return ;
	*err = 1;
	return ;
}

static int			type_handler(char *line, t_scene *scene, int *err)
{
	if (ft_first_occurence(line, "R", 0))
		return (add_new_resolution(scene, line, err));
	if (ft_first_occurence(line, "A", 0))
		return (add_new_ambient(scene, line, err));
	else if (ft_first_occurence(line, "c", 0))
		return (add_new_cam(scene, line, err));
	else if (ft_first_occurence(line, "l", 0))
		return (add_new_light(scene, line, err));
	else if (ft_first_occurence(line, 0, 2))
		return (add_new_figure(scene, line, err));
	else
	{
		if (ft_isblankline(line))
			return (0);
		else
		{
			*err = -1;
			return (display_error_message(WRONG_RT_FILE, 0));
		}
	}
}

static t_scene		*create_new_scene(char *filename, int *err)
{
	t_scene		*scene;
	char		*line;
	int			fd;

	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_error_message(FD_ERROR, 0);
		return (0);
	}
	scene = init_scene();
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_isblankline(line))
		{
			free(line);
			continue;
		}
		type_handler(line, scene, err);
		free(line);
	}
	type_handler(line, scene, err);
	free(line);
	return (scene);
}

t_scene				*parse_scene(char *filename)
{
	t_scene			*scene;
	int				err;

	err = 0;
	scene = 0;
	scene = create_new_scene(filename, &err);
	if (!scene)
		return (emancipate_scene(scene));
	if (err == -1 || !scene)
	{
		display_error_message(SCENE_ERROR, 0);
		emancipate_scene(scene);
		return (0);
	}
	if (scene_validation_error(scene))
	{
		display_error_message(SCENE_ERROR, 0);
		return (emancipate_scene(scene));
	}
	scene->first_cam = scene->cam;
	return (scene);
}
