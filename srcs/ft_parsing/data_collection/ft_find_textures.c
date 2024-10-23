/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:10:26 by adrienhors        #+#    #+#             */
/*   Updated: 2024/10/23 10:34:03 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_create_texture(t_texture *texture, t_texture_type id,
		char *filename)
{
	char	*filename_cleaned;

	texture->texture_id = id;
	filename_cleaned = ft_delete_id_filename(filename);
	if (!filename_cleaned)
	{
		free(texture);
		return ;
	}
	texture->filename = ft_strdup(filename_cleaned);
	if (!texture->filename)
	{
		free(filename_cleaned);
		free(texture);
		return ;
	}
	free(filename_cleaned);
}

static void	ft_handle_texture_creation(t_texture *texture, int texture_type,
		char *str)
{
	if (!texture->filename)
		ft_create_texture(texture, texture_type, str);
}

static void	ft_update_texture_info(int *texture_number, t_map *map, int info_found)
{
	ft_last_info_found(map, info_found);
	(*texture_number)++;
}

static int	ft_attribute_texture(int *texture_number, t_map *map, char *str,
		int info_found)
{
	if (ft_strncmp(str, "NO", 2) == 0 && str[2] == ' ')
	{
		ft_handle_texture_creation(map->north, NORTH_TEXTURE, str + 2);
		ft_update_texture_info(texture_number, map, info_found);
	}
	else if (ft_strncmp(str, "SO", 2) == 0 && str[2] == ' ')
	{
		ft_handle_texture_creation(map->south, SOUTH_TEXTURE, str + 2);
		ft_update_texture_info(texture_number, map, info_found);
	}
	else if (ft_strncmp(str, "EA", 2) == 0 && str[2] == ' ')
	{
		ft_handle_texture_creation(map->east, EAST_TEXTURE, str + 2);
		ft_update_texture_info(texture_number, map, info_found);
	}
	else if (ft_strncmp(str, "WE", 2) == 0 && str[2] == ' ')
	{
		ft_handle_texture_creation(map->west, WEST_TEXTURE, str + 2);
		ft_update_texture_info(texture_number, map, info_found);
	}
	return (0);
}

int	ft_find_textures(t_map *map)
{
	int	i;

	i = 0;
	while (map->dirty_grid[i])
	{
		ft_attribute_texture(&map->nb_textures, map, map->dirty_grid[i], i);
		i++;
	}
	if (map->nb_textures != 4)
	{
		printf("You should have 4 textures\n");
		return (1);
	}
	map->textures_found = 1;
	return (0);
}
