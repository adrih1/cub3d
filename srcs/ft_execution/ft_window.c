/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:38:07 by edouard           #+#    #+#             */
/*   Updated: 2024/10/15 12:48:27 by ahors            ###   ########.fr       */
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
	ft_clear_window(map->data, map->main_image);
	ft_move_player(keynum, map);
	ft_rotate_camera(keynum, map);
	ft_raycasting(map);
	return (keynum);
}

int	ft_check_error(int ret_value, const char *error_msg)
{
	if (ret_value != 0)
	{
		printf("%s\n", error_msg);
		return (1);
	}
	return (0);
}


int	ft_executor(t_map *map)
{
	t_data		data;
	t_texture	main_image;

	if (ft_init_mlx(&data))
		return (ft_message_error("There was an issue to initialize data in executor"));
	map->data = &data;
	if (ft_load_textures(map))
		return (ft_message_error("Error with textures in ft_executor"));
	if (ft_init_main_image(map->data, &main_image))
		return (ft_message_error("Error: Could not initialize main image\n"));
	map->main_image = &main_image;
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr,
		main_image.img, 0, 0);
	mlx_hook(data.win_ptr, 2, 1L << 0, on_keypress, map);
	mlx_hook(data.win_ptr, 17, 1L << 4, on_destroy, map);
	ft_raycasting(map);
	mlx_loop(data.mlx_ptr);
	return (0);
}
