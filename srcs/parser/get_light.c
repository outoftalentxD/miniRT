/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:43:04 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 20:05:25 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_light		*create_new_light(char *line)
{
	t_light	*light;
	int		error;

	error = 0;
	light = init_light();
	if (!light)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "l");
	light->pos = get_point(&line);
	light->brightness = ft_atof_join(&line, &error);
	light->color = get_color(&line);
	check_line_remainder(line, &error);
	if (error > 0 || light_error(light))
	{
		free(light->pos);
		free(light->color);
		free(light);
		return (0);
	}
	return (light);
}

int					add_new_light(t_scene *scene, char *line, int *err)
{
	t_light *light;

	light = create_new_light(line);
	if (!light)
	{
		display_error_message(LIGHT_ERROR, 0);
		emancipate_light_all(&(scene->light));
		*err = -1;
		return (-1);
	}
	lst_addback_light(&(scene->light), light);
	return (0);
}
