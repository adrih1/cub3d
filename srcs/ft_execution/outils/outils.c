/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:25:37 by edouard           #+#    #+#             */
/*   Updated: 2024/10/28 08:44:26 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_message_error(char *error)
{
	printf("%s\n", error);
	return (1);
}

void ft_exit_error(char *error)
{
	perror(error);
	exit(1);
}

int rgb_to_int(char **color)
{
	int r;
	int g;
	int b;

	r = atoi(color[0]);
	g = atoi(color[1]);
	b = atoi(color[2]);
	return ((r << 16) | (g << 8) | b);
}

void my_mlx_pixel_put(t_texture *texture, int x, int y, int color)
{
	char *dst;

	dst = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void ft_clear_window(t_data *data, t_texture *main_image)
{
	int y;
	int x;

	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			my_mlx_pixel_put(main_image, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, main_image->img, 0,
									0);
}
