/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:10:26 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/13 15:07:10 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int ft_find_north_tetxure(t_map *map)
// {
//     return (0); 
// }


// int ft_find_textures(t_map *map)
// {
//     int i;

//     i = 0; 
//     while (map->dirty_grid[i])
//     {
//         if (ft_find_north_tetxure(map->dirty_grid[i]))
//         {
//             map->north_textxure = malloc(sizeof(char *)); 
//             if (!map->north_textxure)
//             {
//                 printf("There was an issue during malloc for map->north_texture\n"); 
//                 return (1); 
//             }
//             map->north_textxure = ft_strdup(map->dirty_grid[i]);  
//         }
//         i++;
//     }
//     return (0);
// }