/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info_is_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:27:22 by adrienhors        #+#    #+#             */
/*   Updated: 2024/10/18 17:54:38 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_color_is_valid(char **color_array)
{
	int	i;
	int	color_variable;
	int	colors_array_len;

	i = 0;
	colors_array_len = ft_len_of_chars_double_array(color_array);
	if (ft_colors_has_no_numbers(color_array) || colors_array_len != 3)
	{
		printf("Please make sure to type three colors for rgb to work\n");
		return (1);
	}
	while (i < colors_array_len)
	{
		color_variable = ft_atoi(color_array[i]);
		if (0 > color_variable || color_variable > 255)
		{
			printf("Use values between 0 and 255\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_colors_is_valid(char **f_color, char **c_color)
{
	if (ft_color_is_valid(f_color))
	{
		printf("There was an error in f_colors\n");
		return (1);
	}
	if (ft_color_is_valid(c_color))
	{
		printf("There was an error in c_colors\n");
		return (1);
	}
	return (0);
}

static int	ft_texture_is_valid(t_texture *texture)
{
	int	fd;
	fd = open(texture->filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Texture : %s was not found\n", texture->filename);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_map_info_is_valid(t_map *map)
{
	if (ft_colors_is_valid(map->f_color, map->c_color))
		return (1);
	if (ft_texture_is_valid(map->north))
		return (1);
	if (ft_texture_is_valid(map->east))
		return (1);
	if (ft_texture_is_valid(map->south))
		return (1);
	if (ft_texture_is_valid(map->west))
		return (1);
	return (0);
}
