/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:13:22 by ahors             #+#    #+#             */
/*   Updated: 2024/09/27 17:28:19 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wft_move_player(int keynum, t_map *map)
{
	t_player *player;
    
    player = map->player;
	// Mouvement en avant (W)
	if (keynum == 13 || keynum == 119)
	{
		if (map->grid[(int)(player->x + player->dirX * MOVE_SPEED)][(int)(player->y)] == '0')
			player->x += player->dirX * MOVE_SPEED;
		if (map->grid[(int)(player->x)][(int)(player->y + player->dirY * MOVE_SPEED)] == '0')
			player->y += player->dirY * MOVE_SPEED;
	}
	// Mouvement en arrière (S)
	else if (keynum == 1 || keynum == 115)
	{
		if (map->grid[(int)(player->x - player->dirX * MOVE_SPEED)][(int)(player->y)] == '0')
			player->x -= player->dirX * MOVE_SPEED;
		if (map->grid[(int)(player->x)][(int)(player->y - player->dirY * MOVE_SPEED)] == '0')
			player->y -= player->dirY * MOVE_SPEED;
	}
	// Mouvement à gauche (A)
	else if (keynum == 0 || keynum == 97)
	{
		if (map->grid[(int)(player->x - player->planeX * MOVE_SPEED)][(int)(player->y)] == '0')
			player->x -= player->planeX * MOVE_SPEED;
		if (map->grid[(int)(player->x)][(int)(player->y - player->planeY * MOVE_SPEED)] == '0')
			player->y -= player->planeY * MOVE_SPEED;
	}
	// Mouvement à droite (D)
	else if (keynum == 2 || keynum == 100)
	{
		if (map->grid[(int)(player->x + player->planeX * MOVE_SPEED)][(int)(player->y)] == '0')
			player->x += player->planeX * MOVE_SPEED;
		if (map->grid[(int)(player->x)][(int)(player->y + player->planeY * MOVE_SPEED)] == '0')
			player->y += player->planeY * MOVE_SPEED;
	}
}

void	ft_rotate_camera(int keynum, t_map *map)
{
	t_player *player;
    
    player = map->player;
	// Rotation à gauche (flèche gauche)
	if (keynum == 123 || keynum == 65361) // 123 (MacOS) ou 65361 (Linux) = flèche gauche
	{
		double oldDirX = player->dirX;
		player->dirX = player->dirX * cos(-ROTATION_SPEED) - player->dirY * sin(-ROTATION_SPEED);
		player->dirY = oldDirX * sin(-ROTATION_SPEED) + player->dirY * cos(-ROTATION_SPEED);

		double oldPlaneX = player->planeX;
		player->planeX = player->planeX * cos(-ROTATION_SPEED) - player->planeY * sin(-ROTATION_SPEED);
		player->planeY = oldPlaneX * sin(-ROTATION_SPEED) + player->planeY * cos(-ROTATION_SPEED);
	}
	// Rotation à droite (flèche droite)
	else if (keynum == 124 || keynum == 65363) // 124 (MacOS) ou 65363 (Linux) = flèche droite
	{
		double oldDirX = player->dirX;
		player->dirX = player->dirX * cos(ROTATION_SPEED) - player->dirY * sin(ROTATION_SPEED);
		player->dirY = oldDirX * sin(ROTATION_SPEED) + player->dirY * cos(ROTATION_SPEED);

		double oldPlaneX = player->planeX;
		player->planeX = player->planeX * cos(ROTATION_SPEED) - player->planeY * sin(ROTATION_SPEED);
		player->planeY = oldPlaneX * sin(ROTATION_SPEED) + player->planeY * cos(ROTATION_SPEED);
	}
}
