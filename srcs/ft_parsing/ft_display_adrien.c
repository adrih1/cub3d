/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_adrien.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:50:42 by ahors             #+#    #+#             */
/*   Updated: 2024/09/19 17:19:44 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	ft_display_grid(t_map *map, char *grid_name)
{
	int	i;
	int	dirty;
	int	clean;

	i = 0;
	dirty = ft_strcmp(grid_name, "dirty");
	clean = ft_strcmp(grid_name, "clean");
	if (dirty == 0)
	{
		printf("***********************DIRTY GRID***********************\n\n");
		while (i < map->m_height)
		{
			printf("%s", map->dirty_grid[i]);
			i++;
		}
		printf("\n");
	}
	else if (clean == 0)
	{
		printf("GRID");
		while (i < map->m_height)
		{
			printf("%s", map->grid[i]);
			i++;
		}
		printf("\n");
	}
	else
		printf("Unknown grid name");
}

void	ft_display_colors(t_map *map)
{
	printf("**********Map Colors************\n");
	printf("CeilingColor:\n");
	printf("First RGB: %s\n", map->c_color[0]);
	printf("Second RGB: %s\n", map->c_color[1]);
	printf("Third RGB: %s\n", map->c_color[2]);
	printf("Floor Color:\n");
	printf("First RGB: %s\n", map->f_color[0]);
	printf("Second RGB: %s\n", map->f_color[1]);
	printf("Third RGB: %s\n", map->f_color[2]);
}

void	ft_display_textures(t_texture *map_texures)
{
	t_texture *first_texture;

	printf("**********Map Textures************\n");
	first_texture = map_texures; 	
	while(map_texures)
	{
		printf("%u: %s\n", map_texures->texture_id, map_texures->filename);
		map_texures = map_texures->next;
	}
	map_texures = first_texture;
}

void	ft_display_map_info(t_map *map)
{
	ft_display_colors(map);
	ft_display_textures(map->textures);
}