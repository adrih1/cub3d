/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:12:25 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 17:50:34 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_rotate_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dirX;
	player->dirX = player->dirX * cos(-ROTATION_SPEED) - player->dirY
		* sin(-ROTATION_SPEED);
	player->dirY = old_dir_x * sin(-ROTATION_SPEED) + player->dirY
		* cos(-ROTATION_SPEED);
	old_plane_x = player->planeX;
	player->planeX = player->planeX * cos(-ROTATION_SPEED) - player->planeY
		* sin(-ROTATION_SPEED);
	player->planeY = old_plane_x * sin(-ROTATION_SPEED) + player->planeY
		* cos(-ROTATION_SPEED);
}

static void	ft_rotate_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dirX;
	player->dirX = player->dirX * cos(ROTATION_SPEED) - player->dirY
		* sin(ROTATION_SPEED);
	player->dirY = old_dir_x * sin(ROTATION_SPEED) + player->dirY
		* cos(ROTATION_SPEED);
	old_plane_x = player->planeX;
	player->planeX = player->planeX * cos(ROTATION_SPEED) - player->planeY
		* sin(ROTATION_SPEED);
	player->planeY = old_plane_x * sin(ROTATION_SPEED) + player->planeY
		* cos(ROTATION_SPEED);
}

void	ft_move_camera(int keynum, t_map *map)
{
	t_player	*player;

	player = map->player;
	if (keynum == 123 || keynum == 65361)
		ft_rotate_left(player);
	else if (keynum == 124 || keynum == 65363)
		ft_rotate_right(player);
}
