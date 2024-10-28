/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:38:07 by edouard           #+#    #+#             */
/*   Updated: 2024/09/18 16:17:02 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_message_error("Error initializing MLX\n"));
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 800, "cub3D");
	if (!data->win_ptr)
		return (ft_message_error("Error creating window\n"));
	return (0);
}

int ft_executor(t_map *map)
{
	if (init_mlx(&map->data))
		return (1);

	ft_render_floor_ceiling(map);
	mlx_loop(map->data.mlx_ptr);

	return (0);
}