/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:20:18 by ahors             #+#    #+#             */
/*   Updated: 2024/10/23 12:55:08 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_map_find_info(t_map *map)
{
	if (ft_find_colors(map))
	{
		printf("Error: Colors \n");
		return (1);
	}
	if (ft_find_textures(map))
	{
		printf("Error: Textures\n");
		return (1);
	}
	return (0);
}
