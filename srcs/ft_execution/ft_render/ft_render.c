/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:16:46 by ahors             #+#    #+#             */
/*   Updated: 2024/10/15 17:07:20 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_column(t_map *map, t_ray *ray, int x)
{
	t_texture		*texture;
	int				text_x;
	int				tex_y;
	int				y;
	unsigned int	color;

	texture = ft_select_texture(map, ray);
	text_x = ft_calculate_texture_x(ray, map->player, texture);
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = ft_calculate_texture_y(y, ray->line_height, texture, map->data);
		color = ft_get_texture_color(texture, text_x, tex_y);
		my_mlx_pixel_put(map->main_image, x, y, color);
		y++;
	}
}

// Fonction pour render l'ecran
void	ft_render_frame(t_map *map)
{
	int		x;
	t_ray	ray;

	ft_render_floor_ceiling(map);
	
	x = 0;
	while (x < map->data->win_width)
	{
		ft_raycasting(map, &ray, x);
		ft_render_column(map, &ray, x);
		x++;
	}
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr,
		map->main_image->img, 0, 0);
}
