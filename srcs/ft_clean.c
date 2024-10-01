/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:14:30 by ahors             #+#    #+#             */
/*   Updated: 2024/10/01 15:12:16 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	ft_free_images(t_map *map)
{
	if (map->north)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->north->image);
		free(map->north);
	}
	if (map->east)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->east->image);
		free(map->east);
	}
	if (map->south)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->south->image);
		free(map->south);
	}
	if (map->west)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->west->image);
		free(map->west);
	}
}

void	ft_free_textures(t_texture *map_textures, t_map *map)
{
	t_texture	*current;
	t_texture	*next;

	current = map_textures;
	while (current)
	{
		next = current->next;
		free(current->filename);
		free(current);
		current = next;
	}
	ft_free_images(map);
	map_textures = NULL;
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

// Fonction pour libérer toute la structure t_map
void	ft_clean(t_map *map)
{
	if (!map)
		return ;
	if (map->dirty_grid)
		if (free_char_array(map->dirty_grid))
			printf("Could not free map dirty grid\n");
	if (map->grid)
		if (free_char_array(map->grid))
			printf("Could not free map grid\n");
	if (map->f_color)
		if (free_char_array(map->f_color))
			printf("Could not free f_color\n");
	if (map->c_color)
		if (free_char_array(map->c_color))
			printf("Could not free c_color\n");
	if (map->textures)
		ft_free_textures(map->textures, map);
	if (map->player)
		free(map->player);
	if (map->data)
		ft_free_data(map->data);
	free(map);
}
