/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:16:46 by ahors             #+#    #+#             */
/*   Updated: 2024/10/15 15:55:31 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_column(t_map *map, t_ray *ray, int x)
{
	ray->color = ft_choose_wall_color(ray->side, ray->mapX, ray->mapY);
	if (ray->side == 1)
		ray->color = ray->color / 2;
	ft_draw_vertical_line(map->main_image, x, ray->draw_start, ray->draw_end,
		ray->color);
}
// Fonction pour render l'ecran 
void	ft_render_frame(t_map *map)
{
	int x;
	t_ray ray;

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