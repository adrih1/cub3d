/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:11:09 by ahors             #+#    #+#             */
/*   Updated: 2024/10/15 16:21:05 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_forward(t_player *player, t_map *map)
{
	if (map->grid[(int)(player->x + player->dirX
			* MOVE_SPEED)][(int)(player->y)] == '0')
		player->x += player->dirX * MOVE_SPEED;
	if (map->grid[(int)(player->x)][(int)(player->y + player->dirY
			* MOVE_SPEED)] == '0')
		player->y += player->dirY * MOVE_SPEED;
}

static void	ft_move_backward(t_player *player, t_map *map)
{
	if (map->grid[(int)(player->x - player->dirX
			* MOVE_SPEED)][(int)(player->y)] == '0')
		player->x -= player->dirX * MOVE_SPEED;
	if (map->grid[(int)(player->x)][(int)(player->y - player->dirY
			* MOVE_SPEED)] == '0')
		player->y -= player->dirY * MOVE_SPEED;
}

static void	ft_move_left(t_player *player, t_map *map)
{
	if (map->grid[(int)(player->x - player->planeX
			* MOVE_SPEED)][(int)(player->y)] == '0')
		player->x -= player->planeX * MOVE_SPEED;
	if (map->grid[(int)(player->x)][(int)(player->y - player->planeY
			* MOVE_SPEED)] == '0')
		player->y -= player->planeY * MOVE_SPEED;
}

static void	ft_move_right(t_player *player, t_map *map)
{
	if (map->grid[(int)(player->x + player->planeX
			* MOVE_SPEED)][(int)(player->y)] == '0')
		player->x += player->planeX * MOVE_SPEED;
	if (map->grid[(int)(player->x)][(int)(player->y + player->planeY
			* MOVE_SPEED)] == '0')
		player->y += player->planeY * MOVE_SPEED;
}

void	ft_move_player(int keynum, t_map *map)
{
	t_player	*player;

	player = map->player;
	if (keynum == 13 || keynum == 119)
		ft_move_forward(player, map);
	else if (keynum == 1 || keynum == 115)
		ft_move_backward(player, map);
	else if (keynum == 0 || keynum == 97)
		ft_move_left(player, map);
	else if (keynum == 2 || keynum == 100)
		ft_move_right(player, map);
}
