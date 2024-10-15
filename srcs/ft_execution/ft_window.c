/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:38:07 by edouard           #+#    #+#             */
/*   Updated: 2024/10/15 12:11:24 by ahors            ###   ########.fr       */
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

int	ft_init_image(t_data *data, t_texture *texture)
{
	// Créer une nouvelle image avec les dimensions de la fenêtre
	texture->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	if (!texture->img)
	{
		printf("Error: Could not create image\n");
		return (1);
	}
	// Obtenir l'adresse de l'image et les informations associées
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		printf("Error: Could not get image data address\n");
		return (1);
	}
	// Afficher les informations pour déboguer
	printf("bits_per_pixel = %d\n", texture->bits_per_pixel);
	printf("line_length = %d\n", texture->line_length);
	printf("endian = %d\n", texture->endian);
	printf("Image address = %p\n", (void *)texture->addr);
	return (0);
}


int	ft_executor(t_map *map)
{
	(void)map;
	t_data data;
	t_texture	main_image;

	if (ft_init_mlx(&data))
	{
		printf("There was an issue to initialize data\n");
		return (1);
	}
	printf("Window initialized with width = %d and height = %d\n", data.win_width, data.win_height);
	map->data = &data;
	if(ft_load_textures(map))
	{
		printf("Isssue with textures in ft_executor\n");
		return (1);		
	}
	if (ft_init_image(map->data, &main_image))
	{
		printf("Error: Could not initialize main image\n");
		return (1);
	}
	map->main_image = &main_image;
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, main_image.img, 0, 0);
	printf("Image put to window at position (0, 0)\n");
	
	mlx_hook(data.win_ptr, 2, 1L << 0, on_keypress, map);
	mlx_hook(data.win_ptr, 17, 1L << 4, on_destroy, map);
	ft_raycasting(map);
	mlx_loop(data.mlx_ptr);
	return (0);
}
