/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:58:31 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/13 13:16:40 by ahors            ###   ########.fr       */
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
    if(str[i])
    {
        while (str[i])
        {
            if (str[i] == 'F')
                return (1); 
            i++;
        }
    }
    return (0); 
}

int ft_process_c_color(t_map *map, int i)
{
    if (ft_find_c_color(map->dirty_grid[i]))
    {
        map->c_color= ft_split(map->dirty_grid[i], ','); 
        if (!map->c_color)
        {
            printf("There was an issue during malloc for map->c_color\n"); 
            return (1);
        }
        return (0); 
    }
    return (1);
}

int ft_process_f_color(t_map *map, int i)
{
    if (ft_find_f_color(map->dirty_grid[i]))
    {
        map->f_color= ft_split(map->dirty_grid[i], ','); 
        if (!map->c_color)
        {
            printf("There was an issue during malloc for map->f_color\n"); 
            return (1);
        }
        return (0); 
    }
    return (1);
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
        found_c = ft_process_c_color(map, i);
        found_f = ft_process_c_color(map, i);
        if (found_c == 0 && found_f == 0)
        {
            ft_display_colors(map);
            return (0);             
        }
        i++;
    }
    return (1);
}
