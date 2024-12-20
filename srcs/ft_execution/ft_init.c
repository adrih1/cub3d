/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:35:52 by ahors             #+#    #+#             */
/*   Updated: 2024/10/23 12:50:59 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		printf("Error: Initializing MLX\n");
		return (1);
	}
	data->win_width = 1700;
	data->win_height = 1000;
	data->win_ptr = NULL;
	return (0);
}

int	ft_init_main_image(t_data *data, t_texture *texture)
{
	texture->img = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height);
	if (!texture->img)
	{
		printf("Error: Could not create main image\n");
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		printf("Error: Could not get image data address of main image\n");
		return (1);
	}
	return (0);
}
