/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info_is_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:27:22 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/18 17:09:03 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int ft_color_is_valid(char **color_array)
{
    int i; 
    int r; 
    int g; 
    int b; 

    i = 0; 
    r = ft_atoi(color_array[0]);
    g = ft_atoi(color_array[1]);
    b = ft_atoi(color_array[2]);
    while(i < 2)
    {
        if(( 0 > r || r > 255) || ( 0 > g || g > 255)  || (0 > b || b > 255))
        {
            printf("Use values between 0 and 255\n");
            return (1); 
        }
        i++; 
    }
    return (0); 
    
}

static int ft_colors_is_valid(char **f_color, char	**c_color)
{
    if(ft_color_is_valid(f_color))
    {
        printf("There was an error in f_colors\n");
        return (1); 
    }
    if(ft_color_is_valid(c_color))
    {
        printf("There was an error in c_colors\n");
        return (1); 
    }
    return (0); 
}
static int ft_texture_is_valid(t_texture *texture)
{
    int fd; 

    fd = open(texture->filename, O_RDONLY); 
    if (fd < 0)
    {
        printf("Texture : %s was not found\n", texture->filename); 
        close(fd); 
        return (1);
    }
    return (0); 
}

static int ft_textures_is_valid(t_texture *texture)
{

    while (texture)
    {
        if(ft_texture_is_valid(texture))
        {
            printf("A texture was not found\n");
            return (1); 
        }
        texture = texture->next;
    }
    return (0);
}

int ft_map_info_is_valid(t_map *map)
{
    if(ft_colors_is_valid(map->f_color, map->c_color))
        return (1);
    if (ft_textures_is_valid(map->textures))
        return (1); 
    return (0); 
}