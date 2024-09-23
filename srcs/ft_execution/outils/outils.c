/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:25:37 by edouard           #+#    #+#             */
/*   Updated: 2024/09/23 11:06:33 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_message_error(char *error)
{
	perror(error);
	return (1);
}

void	ft_exit_error(char *error)
{
	perror(error);
	exit(1);
}