/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:34:05 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 19:53:12 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_fabs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_init_ray(t_ray *ray, t_player *player, int x, int screenWidth)
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
