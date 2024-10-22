/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:11:09 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 17:50:43 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_forward(t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = (int)(player->x + player->dirX * MOVE_SPEED);
	new_y = (int)(player->y + player->dirY * MOVE_SPEED);
	if (new_x >= 0 && new_x < (int)map->longest_str && new_y >= 0
		&& new_y < map->real_height)
	{
		if (map->grid[(int)player->y][new_x] == '0')
			player->x += player->dirX * MOVE_SPEED;
		if (map->grid[new_y][(int)player->x] == '0')
			player->y += player->dirY * MOVE_SPEED;
	}
}

static void	ft_move_backward(t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = (int)(player->x - player->dirX * MOVE_SPEED);
	new_y = (int)(player->y - player->dirY * MOVE_SPEED);
	if (new_x >= 0 && new_x < (int)map->longest_str && new_y >= 0
		&& new_y < map->real_height)
	{
		if (map->grid[(int)player->y][new_x] == '0')
			player->x -= player->dirX * MOVE_SPEED;
		if (map->grid[new_y][(int)player->x] == '0')
			player->y -= player->dirY * MOVE_SPEED;
	}
}

static void	ft_move_left(t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = (int)(player->x - player->planeX * MOVE_SPEED);
	new_y = (int)(player->y - player->planeY * MOVE_SPEED);
	if (new_x >= 0 && new_x < (int)map->longest_str && new_y >= 0
		&& new_y < map->real_height)
	{
		if (map->grid[(int)player->y][new_x] == '0')
			player->x -= player->planeX * MOVE_SPEED;
		if (map->grid[new_y][(int)player->x] == '0')
			player->y -= player->planeY * MOVE_SPEED;
	}
}

static void	ft_move_right(t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = (int)(player->x + player->planeX * MOVE_SPEED);
	new_y = (int)(player->y + player->planeY * MOVE_SPEED);
	if (new_x >= 0 && new_x < (int)map->longest_str && new_y >= 0
		&& new_y < map->real_height)
	{
		if (map->grid[(int)player->y][new_x] == '0')
			player->x += player->planeX * MOVE_SPEED;
		if (map->grid[new_y][(int)player->x] == '0')
			player->y += player->planeY * MOVE_SPEED;
	}
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
