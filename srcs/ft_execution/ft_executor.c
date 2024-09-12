/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:38:07 by edouard           #+#    #+#             */
/*   Updated: 2024/09/12 19:48:13 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_load_textures(t_map *map)
{
	map->north_textxure = load_texture(map->data.mlx_ptr, "./textures/1.xpm");
	map->east_textxure = load_texture(map->data.mlx_ptr, "./textures/1.xpm");
	map->south_textxure = load_texture(map->data.mlx_ptr, "./textures/1.xpm");
	map->west_textxure = load_texture(map->data.mlx_ptr, "./textures/1.xpm");
	if (!map->north_textxure || !map->east_textxure || !map->south_textxure || !map->west_textxure)
		return (ft_message_error("Error loading textures\n"));
	return (0);
}

void ft_render_textures(t_map *map)
{
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr, map->north_textxure, 0, 0);
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr, map->east_textxure, 200, 0);
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr, map->south_textxure, 400, 0);
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr, map->west_textxure, 600, 0);
}

int init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_message_error("Error initializing MLX\n"));
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "cub3D");
	if (!data->win_ptr)
		return (ft_message_error("Error creating window\n"));
	return (0);
}

int ft_executor(t_map *map)
{
	if (init_mlx(&map->data))
		return (1);
	if (ft_load_textures(map))
		return (1);
	ft_render_textures(map);
	mlx_loop(map->data.mlx_ptr);

	return (0);
}