/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:58:31 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/12 17:25:03 by adrienhors       ###   ########.fr       */
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
    int found_c;
    int found_f;

    i = 0; 
    found_c = 0; 
    found_f = 0; 
    while (map->dirty_grid[i])
    {
        if (ft_find_c_color(map->dirty_grid[i]))
        {
            map->c_color= ft_split(map->dirty_grid[i], ','); 
            if (!map->c_color)
            {
                printf("There was an issue during malloc for map->c_color\n"); 
                return (1); 
            }
            found_c = 1; 
        }
        if (ft_find_f_color(map->dirty_grid[i]))
        {
            map->f_color = ft_split(map->dirty_grid[i], ','); 
            if (!map->f_color)
            {
                printf("There was an issue during malloc for map->f_color\n"); 
                return (1); 
            }
            found_f = 1; 
        }
        if (found_c && found_f)
            break;
        i++;
    }
    ft_display_colors(map); 
    return (0);
}
