/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:10:03 by ahors             #+#    #+#             */
/*   Updated: 2024/10/01 11:57:43 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	ft_load_north_texture(t_map *map, t_texture *texture, int width, int height)
{
	map->north = malloc(sizeof(t_img));
	if (!map->north)
	{
		printf("Failed to allocate memory for North texture\n");
		return (1);
	}
	map->north->image = mlx_xpm_file_to_image(map->data->mlx_ptr,
		texture->filename, &width, &height);
	if (!map->north->image)
	{
		printf("Failed to load North texture: %s\n", texture->filename);
		free(map->north);
		return (1);
	}
	map->north->width = width;
	map->north->height = height;
	return(0);
}
int	ft_load_east_texture(t_map *map, t_texture *texture, int width, int height)
{
	
	map->east = malloc(sizeof(t_img));
	if (!map->east)
	{
		printf("Failed to allocate memory for East texture\n");
		return (1);
	}
	map->east->image = mlx_xpm_file_to_image(map->data->mlx_ptr,
		texture->filename, &width, &height);
	if (!map->east->image)
	{
		printf("Failed to load East texture: %s\n", texture->filename);
		free(map->east);
		return (1);
	}
	map->east->width = width;
	map->east->height = height;
	return(0);
}

int	ft_load_south_texture(t_map *map, t_texture *texture, int width, int height)
{
    map->south = malloc(sizeof(t_img));
    if (!map->south)
    {
        printf("Failed to allocate memory for South texture\n");
        return (1);
    }
    map->south->image = mlx_xpm_file_to_image(map->data->mlx_ptr,
        texture->filename, &width, &height);
    if (!map->south->image)
    {
        printf("Failed to load South texture: %s\n", texture->filename);
        free(map->south);
        return (1);
    }
    map->south->width = width;
    map->south->height = height;
    return (0);
}

int	ft_load_west_texture(t_map *map, t_texture *texture, int width, int height)
{
    
    map->west = malloc(sizeof(t_img));
    if (!map->west)
    {
        printf("Failed to allocate memory for West texture\n");
        return (1);
    }
    map->west->image = mlx_xpm_file_to_image(map->data->mlx_ptr,
        texture->filename, &width, &height);
    if (!map->west->image)
    {
        printf("Failed to load West texture: %s\n", texture->filename);
        free(map->west);
        return (1);
    }
    map->west->width = width;
    map->west->height = height;
    return (0);

}


int	ft_load_textures(t_texture *textures, t_map *map)
{
	int			width=1000;
	int			height=1000;
	t_texture	*current_texture;

	map->north = NULL;
	map->east = NULL;
	map->south = NULL;
	map->west = NULL;
	current_texture = textures;
	if (!textures)
	{
		printf("List of textures does not exists\n");
		return (1);
	}
	while (current_texture)
	{
		if (current_texture->texture_id == NORTH_TEXTURE)
			ft_load_north_texture(map, current_texture, width, height);
		else if (current_texture->texture_id == EAST_TEXTURE)
			ft_load_east_texture(map, current_texture, width, height);
		else if (current_texture->texture_id == SOUTH_TEXTURE)
			ft_load_south_texture(map, current_texture, width, height);
		else if (current_texture->texture_id == WEST_TEXTURE)
            ft_load_west_texture(map, current_texture, width, height);
		current_texture = current_texture->next;
	}
	return (0);
}
