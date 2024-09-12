/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:58:31 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/12 17:03:42 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_find_c_color(char *str)
{
    int i; 

    i = 0; 
    while (str[i])
    {
        if (str[i] == 'C')
            return (1); 
        i++;
    }
    return (0); 
}

int			ft_find_f_color(char *str)
{
    int i; 

    i = 0; 
    while (str[i])
    {
        if (str[i] == 'F')
            return (1); 
        i++;
    }
    return (0); 
}

int ft_find_colors(t_map *map)
{
    int i; 

    i = 0; 
    while (map->dirty_grid[i])
    {
        if (ft_find_c_color(map->dirty_grid[i]))
        {
            map->c_color = malloc(sizeof(char * ) * 3); 
            if (!map->c_color)
            {
                printf("There was an issue during malloc for map->c_color\n"); 
                return (1); 
            }
            map->c_color= ft_split(map->dirty_grid[i], ','); 
        }
        if (ft_find_f_color(map->dirty_grid[i]))
        {
            map->f_color = malloc(sizeof(char * ) * 3); 
            if (!map->f_color)
            {
                printf("There was an issue during malloc for map->c_color\n"); 
                return (1); 
            }
            map->f_color= ft_split(map->dirty_grid[i], ','); 
        }
        i++;
    }
    ft_display_colors(map); 
    return (0);
}
