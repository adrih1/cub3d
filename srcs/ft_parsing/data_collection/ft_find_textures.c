/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:10:26 by adrienhors        #+#    #+#             */
/*   Updated: 2024/10/22 17:48:43 by ahors            ###   ########.fr       */
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

static int	ft_attribute_texture(int *texture_number, t_map *map, char *str,
		int info_found)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
		{
			if (!map->north->filename)
				ft_create_texture(map->north, NORTH_TEXTURE, str);
			ft_last_info_found(map, info_found);
			(*texture_number)++;
		}
		else if (str[i] == 'S' && str[i + 1] == 'O')
		{
			if (!map->south->filename)
				ft_create_texture(map->south, SOUTH_TEXTURE, str);
			ft_last_info_found(map, info_found);
			(*texture_number)++;
		}
		else if (str[i] == 'E' && str[i + 1] == 'A')
		{
			if (!map->east->filename)
				ft_create_texture(map->east, EAST_TEXTURE, str);
			ft_last_info_found(map, info_found);
			(*texture_number)++;
		}
		else if (str[i] == 'W' && str[i + 1] == 'E')
		{
			if (!map->west->filename)
				ft_create_texture(map->west, WEST_TEXTURE, str);
			ft_last_info_found(map, info_found);
			(*texture_number)++;
		}
		i++;
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
