/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err_message.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:59:46 by melaena           #+#    #+#             */
/*   Updated: 2020/12/05 03:22:36 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int		display_error_message(char *message, int ret)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(message, 1);
	return (ret);
}
