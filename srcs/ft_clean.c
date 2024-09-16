/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:14:30 by ahors             #+#    #+#             */
/*   Updated: 2024/09/16 17:31:13 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Fonction pour libérer un tableau de chaînes de caractères
int	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (1);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

// Fonction pour libérer toute la structure t_map
void	ft_clean(t_map *map)
{
	if (!map)
		return ;
	if (free_char_array(map->dirty_grid))
		printf("Could not free map dirty grid\n");
	// if(free_char_array(map->grid))
	//     printf("Could not free map grid\n");
	if (free_char_array(map->f_color))
		printf("Could not free f_color\n");
	if (free_char_array(map->c_color))
		printf("Could not free c_color\n");
	free(map->north_textxure);
	free(map->east_textxure);
	free(map->south_textxure);
	free(map->west_textxure);
	free(map);
}
