/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:01:37 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/25 11:29:36 by ahors            ###   ########.fr       */
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
void	init_ray(t_ray *ray, t_player *player, int x, int screenWidth)
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

void	calculate_step_and_side_dist(t_ray *ray, t_player *player)
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

void	perform_dda(t_ray *ray, t_map *map)
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

double	calculate_perp_wall_dist(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		return ((ray->mapX - player->x + (1 - ray->stepX) / 2) / ray->rayDirX);
	else
		return ((ray->mapY - player->y + (1 - ray->stepY) / 2) / ray->rayDirY);
}

int	calculate_line_height(double perpWallDist, int screenHeight)
{
	return (int)(screenHeight / perpWallDist);
}

void draw_vertical_line(void *mlx_ptr, void *win_ptr, int x, int drawStart, int drawEnd)
{
    int y;

    y = drawStart;
    while (y <= drawEnd)
    {
        // Dessine un pixel rouge (couleur hexadécimale : 0xFF0000)
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
        y++;
    }
}

void	ft_raycasting(t_map *map)
{
	int	x;
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
	t_ray ray;

	x = 0;
	while (x < map->data.win_width)
	{
		// 1. Initialiser le rayon
		init_ray(&ray, map->player, x, map->data.win_width);
		// 2. Calculer le step et la distance initiale
		calculate_step_and_side_dist(&ray, map->player);
		// 3. Exécuter l'algorithme DDA pour trouver le mur
		perform_dda(&ray, map);
		// 4. Calculer la distance perpendiculaire au mur
		ray.perpWallDist = calculate_perp_wall_dist(&ray, map->player);
		// 5. Calculer la hauteur de la ligne de mur à dessiner
		lineHeight = calculate_line_height(ray.perpWallDist, map->data.win_height);
		// 6. Calculer les points de départ et de fin de la ligne
		drawStart = -lineHeight / 2 + map->data.win_height / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + map->data.win_height / 2;
		if (drawEnd >= map->data.win_height)
			drawEnd = map->data.win_height - 1;
		// 7. Draw Wall Line betweem drawStart and drawEnd for X column
        draw_vertical_line(map->data.mlx_ptr, map->data.win_ptr, x, drawStart, drawEnd);
		x++;
	}
}
