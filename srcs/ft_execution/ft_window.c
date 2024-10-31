/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:38:07 by edouard           #+#    #+#             */
/*   Updated: 2024/10/28 09:46:22 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int on_destroy(t_map *map)
{
	ft_clean(map);
	exit(1);
}

static int on_keypress(int keynum, t_map *map)
{
	if (keynum == 53 || keynum == 65307)
		on_destroy(map);
	ft_clear_window(map->data, map->main_image);
	ft_move_player(keynum, map);
	ft_move_camera(keynum, map);
	ft_render_frame(map);
	return (keynum);
}

static int ft_init_window(t_map *map)
{
	map->data->win_ptr = mlx_new_window(map->data->mlx_ptr,
													map->data->win_width, map->data->win_height, "cub3D");
	if (!map->data->win_ptr)
	{
		printf("Error creating window\n");
		return (1);
	}
	return (0);
}

int ft_executor(t_map *map)
{
	t_texture main_image;

	map->data = malloc(sizeof(t_data));
	if (ft_init_mlx(map->data))
		return (ft_message_error("Error: initialize data in executor"));
	if (ft_load_textures(map))
	{
		printf("Error with textures in executor\n");
		return (1);
	}
	if (ft_init_window(map))
		return (1);
	if (ft_init_main_image(map->data, &main_image))
		return (ft_message_error("Error: Could not initialize main image\n"));
	map->main_image = &main_image;
	ft_render_floor_ceiling(map);
	ft_render_frame(map);
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr,
									main_image.img, 0, 0);
	mlx_hook(map->data->win_ptr, 2, 1L << 0, on_keypress, map);
	mlx_hook(map->data->win_ptr, 17, 1L << 4, on_destroy, map);
	mlx_loop(map->data->mlx_ptr);
	return (0);
}
