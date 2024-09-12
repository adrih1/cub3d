/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:20:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/12 17:10:18 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_display_grid(t_map *map, char *grid_name)
{
    int i; 
    int dirty; 
    int clean; 

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

void    ft_display_colors(t_map *map)
{
    printf("CeilingColor:\n");
    printf("First RGB: %s\n", map->c_color[0]);
    printf("Second RGB: %s\n", map->c_color[1]);
    printf("Third RGB: %s\n", map->c_color[2]);

    printf("Floor Color:\n");
    printf("First RGB: %s\n", map->f_color[0]);
    printf("Second RGB: %s\n", map->f_color[1]);
    printf("Third RGB: %s\n", map->f_color[2]);
}

int ft_map_find_info(t_map *map)
{

    // Find Colors
    if (ft_find_colors(map))
    {
        printf("Issue while searching for colors\n"); 
        return (1); 
    }
    // Find Textures


    return (0);
}