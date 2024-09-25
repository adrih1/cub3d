/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:38:07 by edouard           #+#    #+#             */
/*   Updated: 2024/09/25 14:34:43 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_destroy(t_map *map)
{
	ft_clean(map);
	exit(1);
}

int	on_keypress(int keynum, t_map *map)
{
	if (keynum == 53 || keynum == 65307)
		on_destroy(map);
	return (keynum);
}
int	ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		printf("Error initializing MLX\n");
		return (1);
	}
	data->win_width = 1200;
	data->win_height = 700;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "cub3D");
	if (!data->win_ptr)
	{
		printf("Error creating window\n");
		return (1);
	}
	return (0);
}


int	ft_executor(t_map *map)
{
	(void)map;
	t_data data;

	if (ft_init_mlx(&data))
	{
		printf("There was an issue to initialize data\n");
		return (1);
	}
	map->data = &data;
	mlx_hook(data.win_ptr, 2, 1L << 0, on_keypress, map);
	mlx_hook(data.win_ptr, 17, 1L << 4, on_destroy, map);

	// TODO - Appeller render frame dans un hook
	ft_raycasting(map);
	mlx_loop(data.mlx_ptr);
	return (0);
}