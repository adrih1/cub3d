/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:10:26 by adrienhors        #+#    #+#             */
/*   Updated: 2024/10/18 14:45:49 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_texture	*ft_create_texture(t_texture_type id, char *filename)
{
	t_texture	*new_texture;
	char		*filename_cleaned;

	new_texture = (t_texture *)malloc(sizeof(t_texture));
	if (!new_texture)
	{
		free(new_texture);
		return (NULL);
	}
	new_texture->texture_id = id;
	filename_cleaned = ft_delete_id_filename(filename);
	if (!filename_cleaned)
		return (NULL);
	new_texture->filename = ft_strdup(filename_cleaned);
	new_texture->next = NULL;
	free(filename_cleaned);
	return (new_texture);
}

static void	ft_attribute_texture(t_map *map, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
			map->north = ft_create_texture(NORTH_TEXTURE, str);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			map->south = ft_create_texture(SOUTH_TEXTURE, str);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			map->east = ft_create_texture(EAST_TEXTURE, str);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			map->west = ft_create_texture(WEST_TEXTURE, str);
		i++;
	}
}

int	ft_find_textures(t_map *map)
{
	int	i;

	i = 0;
	while (map->dirty_grid[i])
	{
		ft_attribute_texture(map, map->dirty_grid[i]);
		i++;
	}
	return (0);
}
