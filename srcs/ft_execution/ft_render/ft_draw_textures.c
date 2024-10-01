/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:48:15 by ahors             #+#    #+#             */
/*   Updated: 2024/10/01 15:53:00 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Fonction pour choisir une couleur en fonction de la case dans la map
int ft_choose_wall_color(int side, int stepX, int stepY)
{
    // Choix de la couleur en fonction de la direction du mur
    if (side == 0) // Mur est-ouest
    {
        if (stepX > 0)
            return 0xFF0000; // Mur à l'est (rouge)
        else
            return 0x00FF00; // Mur à l'ouest (vert)
    }
    else // Mur nord-sud
    {
        if (stepY > 0)
            return 0x0000FF; // Mur au sud (bleu)
        else
            return 0x800080; // Mur au nord (blanc)
    }
}

void	ft_draw_vertical_line_with_color(void *mlx_ptr, void *win_ptr, int x, int drawStart, int drawEnd, int color)
{
	int y;

	y = drawStart;
	while (y <= drawEnd)
	{
		// Dessine un pixel avec la couleur donnée
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		y++;
	}
}

// Fonction pour selectionner la texture a mettre 
t_img *ft_select_texture(t_map *map, t_ray *ray)
{
    if (ray->side == 0) // Mur Nord-Sud
    {
        if (ray->rayDirX > 0)
            return map->west;  // Si le rayon va vers l'ouest, mur Ouest
        else
            return map->east;  // Si le rayon va vers l'est, mur Est
    }
    else // Mur Est-Ouest
    {
        if (ray->rayDirY > 0)
            return map->north;  // Si le rayon va vers le nord, mur Nord
        else
            return map->south;  // Si le rayon va vers le sud, mur Sud
    }
}

//
int ft_calculate_texture_x(t_ray *ray, t_player *player, t_img *texture)
{
    double wallX;
    int texX;

    // Calcul de la position exacte où le mur a été touché
    if (ray->side == 0)
        wallX = player->y + ray->perpWallDist * ray->rayDirY;
    else
        wallX = player->x + ray->perpWallDist * ray->rayDirX;
    wallX -= floor(wallX);  // Prend uniquement la partie décimale (fractionnaire)

    // Convertit cette position en coordonnée sur la texture
    texX = (int)(wallX * (double)(texture->width));
    
    // Ajuste pour l'orientation du mur
    if (ray->side == 0 && ray->rayDirX > 0)
        texX = texture->width - texX - 1;
    if (ray->side == 1 && ray->rayDirY < 0)
        texX = texture->width - texX - 1;
    return texX;
}

// Étape 3 : Récupération de la couleur depuis la texture
int ft_get_texture_color(t_img *texture, int texture_x, int texture_y)
{
    // Assurez-vous que les coordonnées sont dans les limites de la texture
    if (texture_x < 0 || texture_x >= texture->width ||
        texture_y < 0 || texture_y >= texture->height)
    {
        return (0); // Couleur par défaut (transparent ou noir)
    }

    // Cast de texture->data en int* pour accéder aux couleurs
    int *data = (int *)texture->data;
    // Calcul de l'index
    int index = texture->width * texture_y + texture_x;
    return (data[index]); // Retourne la couleur
}
