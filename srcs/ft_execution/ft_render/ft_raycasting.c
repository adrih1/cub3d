/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:01:37 by adrienhors        #+#    #+#             */
/*   Updated: 2024/10/14 15:21:39 by ahors            ###   ########.fr       */
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

// Initialise le rayon pour une colonne x.
static void	ft_init_ray(t_ray *ray, t_player *player, int x, int screenWidth)
{
	double	cameraX;

	cameraX = 2 * x / (double)screenWidth - 1;
	ray->rayDirX = player->dirX + player->planeX * cameraX;
	ray->rayDirY = player->dirY + player->planeY * cameraX;
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
	while (ray->hit == 0) // Tant que le rayon n'a pas touché un mur
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0; // Rayon touche un mur sur l'axe X
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1; // Rayon touche un mur sur l'axe Y
		}
		// Ici on vérifie si la case dans grid contient un mur
		if (map->grid[ray->mapY][ray->mapX] == '1')
			// Si la case contient un mur ('1')
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
	return (int)(screenHeight / perpWallDist);
}

void	ft_raycasting(t_map *map)
{
	int				x;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	t_ray			ray;
	int				texX;

	x = 0;
	while (x < map->data->win_width)
	{
		ft_init_ray(&ray, map->player, x, map->data->win_width);
		ft_calculate_step_and_side_dist(&ray, map->player);
		ft_perform_dda(&ray, map);
		ray.perpWallDist = ft_calculate_perp_wall_dist(&ray, map->player);
		lineHeight = ft_calculate_line_height(ray.perpWallDist,
				map->data->win_height);
		drawStart = -lineHeight / 2 + map->data->win_height / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + map->data->win_height / 2;
		if (drawEnd >= map->data->win_height)
			drawEnd = map->data->win_height - 1;
		
		
		texX = ft_calculate_texture_x(&ray, map->player, ft_select_texture(map, &ray));		
		x++;
	}
}

// RENDER VISUEL - OLD LINE
// // 7. Choisir la couleur en fonction de la position du mur dans la map
// color = choose_wall_color(map, ray.mapX, ray.mapY);
// // 8. Ajuster la luminosité si on a touché un mur sur un côté Y (side == 1)
// if (ray.side == 1)
// 	color = color / 2; // On divise la couleur par 2 pour assombrir

// // 9. Dessiner la ligne avec la couleur choisie
// draw_vertical_line_with_color(map->data->mlx_ptr, map->data->win_ptr, x,
	// drawStart, drawEnd, color);