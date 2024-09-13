/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:14:30 by ahors             #+#    #+#             */
/*   Updated: 2024/09/13 15:33:10 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"


void    ft_clean(t_map *map)
{
    int i; 

    i = 0;
    while(map->dirty_grid[i])
    {
        free(map->dirty_grid[i]);
        i++;
    }
    i = 0;
    // while(map->grid[i])
    // {
    //     free(map->grid[i]);
    //     i++;
    // }
}