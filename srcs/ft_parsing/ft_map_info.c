/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:20:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/16 16:17:16 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	ft_map_find_info(t_map *map)
{
	// Find Colors
	if (ft_find_colors(map))
		ft_message_error("There was an error finding colors\n");
	// ft_display_colors(map);

	// Find Textures
	if(	ft_find_textures(map))
		ft_message_error("There was an errrir finding textures\n");
	return (0);
}
