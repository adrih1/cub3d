/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:25:37 by edouard           #+#    #+#             */
/*   Updated: 2024/10/15 12:23:22 by ahors            ###   ########.fr       */
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


void	ft_clear_window(t_data *data, t_texture *main_image)
{
	for (int y = 0; y < data->win_height; y++)
	{
		for (int x = 0; x < data->win_width; x++)
		{
			my_mlx_pixel_put(main_image, x, y, 0x00000000);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, main_image->img, 0, 0);
}