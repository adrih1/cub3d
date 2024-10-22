/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:14:30 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 12:34:01 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Fonction pour libérer un tableau de chaînes de caractères
int	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (1);
	while (array[i])
	{
		if (array[i] != NULL)
			free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

void	ft_free_data(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_free_texture(t_texture *texture, t_data *data)
{
	if (texture)
	{
		if (data)
			mlx_destroy_image(data->mlx_ptr, texture->img);
		texture->img = NULL;
		free(texture->filename);
		free(texture);
	}
}

void	ft_free_textures(t_map *map)
{
	ft_free_texture(map->north, map->data);
	ft_free_texture(map->east, map->data);
	ft_free_texture(map->south, map->data);
	ft_free_texture(map->west, map->data);
}

void	ft_free_main_image(t_data *data, t_texture *main_image)
{
	mlx_destroy_image(data->mlx_ptr, main_image->img);
	main_image->img = NULL;
}

// Fonction pour libérer toute la structure t_map
void	ft_clean(t_map *map)
{	
	if (!map)
		return ;
	if (map->dirty_grid)
		if (free_char_array(map->dirty_grid))
			printf("Could not free map dirty grid\n");
	if (map->f_color)
		if (free_char_array(map->f_color))
			printf("Could not free f_color\n");
	if (map->c_color)
		if (free_char_array(map->c_color))
			printf("Could not free c_color\n");
	if (map->grid)
		if (free_char_array(map->grid))
			printf("Could not free map grid\n");
	ft_free_textures(map);
	if (map->main_image)
		ft_free_main_image(map->data, map->main_image);
	if (map->player)
		free(map->player);
	if (map->data)
		ft_free_data(map->data);
	free(map);
	map = NULL;
}
