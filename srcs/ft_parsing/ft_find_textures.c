/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:10:26 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/16 18:49:18 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


//Determine tetxure ID 

//Get Filename of Texture 
static char	*ft_attribute_tetxure(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		// TODO
		// Je sais pas si la il faut ajouter une protection si ft_strdup foire (en tout cas pas de leaks ni segfault)
		if (str[i] == 'N' && str[i + 1] == 'O')
			map->north_textxure = ft_strdup(str);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			map->south_textxure = ft_strdup(str);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			map->east_textxure = ft_strdup(str);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			map->west_textxure = ft_strdup(str);
		i++;
	}
	return (NULL);
}

int	ft_find_textures(t_map *map)
{
	int i;

	i = 0;
	while (map->dirty_grid[i])
	{
		ft_attribute_tetxure(map->dirty_grid[i], map);
		i++;
	}
	return (0);
}