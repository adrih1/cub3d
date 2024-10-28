/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:48:15 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 20:18:12 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*ft_select_texture(t_map *map, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (map->west);
		else
			return (map->east);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (map->north);
		else
			return (map->south);
	}
}

int	ft_calculate_texture_x(t_ray *ray, t_player *player, t_texture *texture)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)(texture->width));
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

int	ft_calculate_texture_y(int y, int line_height, t_texture *texture,
		t_data *data)
{
	int	tex_y;
	int	d;

	d = y * 256 - data->win_height * 128 + line_height * 128;
	tex_y = ((d * texture->height) / line_height) / 256;
	return (tex_y);
}

unsigned int	ft_get_texture_color(t_texture *texture, int texX, int texY)
{
	char			*pixel;
	unsigned int	color;

	pixel = texture->addr + (texY * texture->line_length + texX
			* (texture->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}
