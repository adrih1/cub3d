/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:51 by ahors             #+#    #+#             */
/*   Updated: 2024/10/01 12:24:15 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_init_map(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
	{
		printf("Error during malloc for map\n");
		return (1);
	}
	(*map)->m_width = 0;
	(*map)->m_height = 0;
	(*map)->real_height = 0;
	(*map)->dirty_grid = NULL;
	(*map)->grid = NULL;
	(*map)->textures = NULL;  
	(*map)->f_color = NULL;
	(*map)->c_color = NULL;
	(*map)->player = NULL;
	return (0);
}


int	ft_verify_extension(char *str)
{
	int i;
	int last_dot_found;

	i = 0;
	last_dot_found = 0;
	while(str[i])
	{
		if(str[i] == '.')
			last_dot_found = i;
		i++;
	}
	last_dot_found++;
	if(str[last_dot_found] == 'c' && str[last_dot_found + 1] == 'u' && str[last_dot_found + 2] == 'b')
		return (0);
	else 
		return (1);
}

int main(int ac, char **av)
{
	t_map *map;

	if (ac != 2)
	{
		printf("Please give a .cub file for the map\n");
		return (1);		
	}
	if (ft_verify_extension(av[1]))
	{
		printf("Please make sure the file extension is '.cub'\n");		
		return (1);
	}
	if (ft_init_map(&map))
	{
		printf("Probleme pour init map\n");
		ft_clean(map);
		return (1);		
	}
	else
		if (ft_parsing(map, av[1]))
		{
			ft_clean(map);
			return (1);
		}
	// MinilibX - Initialisation de la fenetre
	ft_executor(map);
	// The Game
		// Casting the Rays
		// Rendering the walls
		// Player Movement
	// Clean
	ft_clean(map);
	return (0);
}
