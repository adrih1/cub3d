/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:20:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/24 14:23:49 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_map_find_info(t_map *map)
{
	if (ft_find_colors(map))
	{
		printf("There was an error with colors\n");
		return (1);
	}
	if (ft_find_textures(map))
	{
		printf("There was an error finding textures\n");
		return (1);
	}
	return (0);
}
