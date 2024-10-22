/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:10:03 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 15:43:50 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_load_north_texture(t_map *map, t_texture *texture, int width, int height)
{
	map->north->img = mlx_xpm_file_to_image(map->data->mlx_ptr,
			texture->filename, &width, &height);
	if (!map->north->img)
	{
		printf("Failed to load North texture: %s\n", texture->filename);
		return (1);
	}
	map->north->addr = mlx_get_data_addr(map->north->img,
			&map->north->bits_per_pixel, &map->north->line_length,
			&map->north->endian);
	map->north->width = width;
	map->north->height = height;
	return (0);
}

int	ft_load_east_texture(t_map *map, t_texture *texture, int width, int height)
{
	
	map->east->img = mlx_xpm_file_to_image(map->data->mlx_ptr,
			texture->filename, &width, &height);
	if (!map->east->img)
	{
		printf("Failed to load East texture: %s\n", texture->filename);
		return (1);
	}
	map->east->addr = mlx_get_data_addr(map->east->img,
			&map->east->bits_per_pixel, &map->east->line_length,
			&map->east->endian);
	map->east->width = width;
	map->east->height = height;
	return (0);
}

int	ft_load_south_texture(t_map *map, t_texture *texture, int width, int height)
{

	map->south->img = mlx_xpm_file_to_image(map->data->mlx_ptr,
			texture->filename, &width, &height);
	if (!map->south->img)
	{
		printf("Failed to load South texture: %s\n", texture->filename);
		return (1);
	}
	map->south->addr = mlx_get_data_addr(map->south->img,
			&map->south->bits_per_pixel, &map->south->line_length,
			&map->south->endian);
	map->south->width = width;
	map->south->height = height;
	return (0);
}

int	ft_load_west_texture(t_map *map, t_texture *texture, int width, int height)
{
	map->west->img = mlx_xpm_file_to_image(map->data->mlx_ptr,
			texture->filename, &width, &height);
	if (!map->west->img)
	{
		printf("Failed to load West texture: %s\n", texture->filename);
		return (1);
	}
	map->west->addr = mlx_get_data_addr(map->west->img,
			&map->west->bits_per_pixel, &map->west->line_length,
			&map->west->endian);
	map->west->width = width;
	map->west->height = height;
	return (0);
}

int	ft_load_textures(t_map *map)
{
	int			width;
	int			height;

	width = 10000;
	height = 10000;

	if (map->north)
	{
		if(ft_load_north_texture(map, map->north, width, height))
			return(1);
	}
	if (map->east)
	{	
		if(ft_load_east_texture(map, map->east, width, height))
			return (1);
	}
	if (map->south)
	{	
		if(ft_load_south_texture(map, map->south, width, height))
			return (1);
	}
	if (map->west)
	{	
		if(ft_load_west_texture(map, map->west, width, height))
			return (1);
	}
	return (0);
}
