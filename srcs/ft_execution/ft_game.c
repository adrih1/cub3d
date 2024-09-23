/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:00:02 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/22 16:44:28 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void ft_init_player(t_player *player)
{
    player->x = 2.5; // Colonne 2, case du joueur 'P'
    player->y = 1.5; // Ligne 1, case du joueur 'P'
    player->dirX = -1; // Direction vers le Nord
    player->dirY = 0; // Pas de composante sur Y
    player->planeX = 0; // Plan de la caméra perpendiculaire à dirX et dirY
    player->planeY = 0.66; // Le facteur 0.66 correspond à un champ de vue de 66 degrés (standard dans Wolfenstein/Doom)
}
