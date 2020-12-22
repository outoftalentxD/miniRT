/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:09:28 by melaena           #+#    #+#             */
/*   Updated: 2020/12/22 20:03:24 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static double		get_fov(char **line)
{
	char	*ptr;
	double	fov;
	int		error;

	error = 0;
	ptr = *line;
	while (ft_isspace(*ptr))
		ptr++;
	fov = ft_atof_join(&ptr, &error);
	*line = ptr;
	if (error == 1)
		return (-1);
	if (fov < 0 || fov > 180)
		return (-1);
	return (fov);
}

static t_cam		*create_new_cam(char *line)
{
	t_cam	*cam;
	int		error;

	error = 0;
	cam = init_cam();
	if (!cam)
		return (0);
	ft_skip_occurence_and_whitespaces(&line, "c");
	cam->pos = get_point(&line);
	cam->vector = get_point(&line);
	cam->fov = get_fov(&line);
	check_line_remainder(line, &error);
	if (error > 0 || cam_error(cam))
	{
		free(cam->pos);
		free(cam->vector);
		free(cam);
		return (0);
	}
	cam->forward = compute_forward_axis(cam);
	cam->right = compute_right_axis(cam->forward);
	cam->up = compute_up_axis(cam->forward, cam->right);
	return (cam);
}

int					add_new_cam(t_scene *scene, char *line, int *err)
{
	t_cam	*cam;

	cam = create_new_cam(line);
	if (!cam)
	{
		display_error_message(CAM_ERROR, 0);
		emancipate_cam_all(&(scene->cam));
		*err = -1;
		return (-1);
	}
	lst_addback_cam(&(scene->cam), cam);
	return (0);
}
