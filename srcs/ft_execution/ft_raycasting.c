/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:01:37 by adrienhors        #+#    #+#             */
/*   Updated: 2024/10/28 08:46:40 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #include <SDL2/SDL.h>

static void ft_calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

static void ft_perform_dda(t_ray *ray, t_map *map)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static double ft_calculate_perp_wall_dist(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		return ((ray->map_x - player->x + (1 - ray->step_x) / 2) / ray->ray_dir_x);
	else
		return ((ray->map_y - player->y + (1 - ray->step_y) / 2) / ray->ray_dir_y);
}

static int ft_calculate_line_height(double perp_wall_dist, int screenHeight)
{
	return ((int)(screenHeight / perp_wall_dist));
}

void ft_raycasting(t_map *map, t_ray *ray, int x)
{
	ft_init_ray(ray, map->player, x, map->data->win_width);
	ft_calculate_step_and_side_dist(ray, map->player);
	ft_perform_dda(ray, map);
	ray->perp_wall_dist = ft_calculate_perp_wall_dist(ray, map->player);
	ray->line_height = ft_calculate_line_height(ray->perp_wall_dist,
															  map->data->win_height);
	ray->draw_start = -ray->line_height / 2 + map->data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + map->data->win_height / 2;
	if (ray->draw_end >= map->data->win_height)
		ray->draw_end = map->data->win_height - 1;
}
