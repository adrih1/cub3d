/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:10:26 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/18 16:57:28 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_texture	*ft_new_texture(t_texture_type id, char *filename)
{
	t_texture	*new_texture;
	char *filename_cleaned; 

	new_texture = (t_texture *)malloc(sizeof(t_texture));
	if (!new_texture)
		return (NULL);
	new_texture->texture_id = id;
	filename_cleaned = ft_delete_id_filename(filename);
	new_texture->filename = ft_strdup(filename_cleaned);
	new_texture->next = NULL;
	return (new_texture);
}

void	ft_add_texture(t_texture **textures, t_texture *new_texture)
{
	t_texture	*tmp;

	if (!*textures)
		*textures = new_texture;
	else
	{
		tmp = *textures;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_texture;
	}
}

static void	ft_attribute_texture(char *str, t_texture **textures)
{
	int i; 

	i = 0;
	while(str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
			ft_add_texture(textures, ft_new_texture(NORTH_TEXTURE, str));
		else if (str[i] == 'S' && str[i + 1] == 'O')
			ft_add_texture(textures, ft_new_texture(SOUTH_TEXTURE, str));
		else if (str[i] == 'E' && str[i + 1] == 'A')
			ft_add_texture(textures, ft_new_texture(EAST_TEXTURE, str));
		else if (str[i] == 'W' && str[i + 1] == 'E')
			ft_add_texture(textures, ft_new_texture(WEST_TEXTURE, str));
		i++;
	}

}

int	ft_find_textures(t_map *map)
{
	int i;

	i = 0;
	map->textures = NULL;
	while (map->dirty_grid[i])
	{
		ft_attribute_texture(map->dirty_grid[i], &(map->textures));
		i++;
	}
	return (0);
}