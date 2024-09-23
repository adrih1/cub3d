/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:20:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/18 19:03:29 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_map_find_info(t_map *map)
{
	// Find Colors
	if (ft_find_colors(map))
	{
		printf("There was an error with colors\n");
		return (1);
	}
	// ft_display_colors(map);
	// Find Textures
	if (ft_find_textures(map))
	{
		printf("There was an error finding textures\n");
		return (1);
	}
	return (0);
}