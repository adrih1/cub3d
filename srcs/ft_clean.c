/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:14:30 by ahors             #+#    #+#             */
/*   Updated: 2024/10/18 16:39:43 by ebaillot         ###   ########.fr       */
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

void	ft_free_textures(t_map *map)
{
	if (map->north)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->north->img);
		free(map->north->filename);
		free(map->north);
	}
	if (map->east)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->east->img);
		free(map->east->filename);
		free(map->east);
	}
	if (map->south)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->south->img);
		free(map->south->filename);
		free(map->south);
	}
	if (map->west)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->west->img);
		free(map->west->filename);
		free(map->west);
	}
}

void	ft_free_main_image(t_data *data, t_texture *main_image)
{
	mlx_destroy_image(data->mlx_ptr, main_image->img);
	main_image->img = NULL; // Optionnel : éviter les pointeurs pendants
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
	ft_free_textures(map);
	if (map->player)
		free(map->player);
	if (map->main_image)
		ft_free_main_image(map->data, map->main_image);
	if (map->data)
		ft_free_data(map->data);
	free(map);
}
