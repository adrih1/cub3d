/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:25:37 by edouard           #+#    #+#             */
/*   Updated: 2024/10/14 15:19:19 by ahors            ###   ########.fr       */
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

int	rgb_to_int(char **color)
{
	int r = atoi(color[0]);
	int g = atoi(color[1]);
	int b = atoi(color[2]);
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_pixel_put(t_texture *texture, int x, int y, int color)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
