/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:01:37 by adrienhors        #+#    #+#             */
/*   Updated: 2024/10/22 17:48:56 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <SDL2/SDL.h>

static double	ft_fabs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_init_ray(t_ray *ray, t_player *player, int x, int screenWidth)
{
	double	camera_x;

	camera_x = 2 * x / (double)screenWidth - 1;
	ray->rayDirX = player->dirX + player->planeX * camera_x;
	ray->rayDirY = player->dirY + player->planeY * camera_x;
	ray->mapX = (int)player->x;
	ray->mapY = (int)player->y;
	ray->deltaDistX = ft_fabs(1 / ray->rayDirX);
	ray->deltaDistY = ft_fabs(1 / ray->rayDirY);
	ray->hit = 0;
}

static void	ft_calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player->x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - player->x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player->y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - player->y) * ray->deltaDistY;
	}
}

static void	ft_perform_dda(t_ray *ray, t_map *map)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (map->grid[ray->mapY][ray->mapX] == '1')
			ray->hit = 1;
	}
}

static double	ft_calculate_perp_wall_dist(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		return ((ray->mapX - player->x + (1 - ray->stepX) / 2) / ray->rayDirX);
	else
		return ((ray->mapY - player->y + (1 - ray->stepY) / 2) / ray->rayDirY);
}

static int	ft_calculate_line_height(double perpWallDist, int screenHeight)
{
	return ((int)(screenHeight / perpWallDist));
}

void	ft_raycasting(t_map *map, t_ray *ray, int x)
{
	ft_init_ray(ray, map->player, x, map->data->win_width);
	ft_calculate_step_and_side_dist(ray, map->player);
	ft_perform_dda(ray, map);
	ray->perpWallDist = ft_calculate_perp_wall_dist(ray, map->player);
	ray->line_height = ft_calculate_line_height(ray->perpWallDist,
			map->data->win_height);
	ray->draw_start = -ray->line_height / 2 + map->data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + map->data->win_height / 2;
	if (ray->draw_end >= map->data->win_height)
		ray->draw_end = map->data->win_height - 1;
}
