/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:34:05 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 20:18:58 by ahors            ###   ########.fr       */
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
	ray->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = ft_fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = ft_fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}
