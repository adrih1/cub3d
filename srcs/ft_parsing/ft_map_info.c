/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:20:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/12 14:43:59 by adrienhors       ###   ########.fr       */
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