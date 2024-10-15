/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:48:15 by ahors             #+#    #+#             */
/*   Updated: 2024/10/15 11:03:18 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Fonction pour choisir une couleur en fonction de la case dans la map
int	ft_choose_wall_color(int side, int stepX, int stepY)
{
	// Choix de la couleur en fonction de la direction du mur
	if (side == 0) // Mur est-ouest
	{
		if (stepX > 0)
			return (0xFF0000); // Mur à l'est (rouge)
		else
			return (0x00FF00); // Mur à l'ouest (vert)
	}
	else // Mur nord-sud
	{
		if (stepY > 0)
			return (0x0000FF); // Mur au sud (bleu)
		else
			return (0x800080); // Mur au nord (blanc)
	}
}

void	ft_draw_vertical_line_with_color(void *mlx_ptr, void *win_ptr, int x,
		int drawStart, int drawEnd, int color)
{
	int	y;

	y = drawStart;
	while (y <= drawEnd)
	{
		// Dessine un pixel avec la couleur donnée
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		y++;
	}
}

t_texture	*ft_select_texture(t_map *map, t_ray *ray)
{
	if (ray->side == 0) // Mur Nord-Sud
	{
		if (ray->rayDirX > 0)
			return (map->west); // Si le rayon va vers l'ouest, mur Ouest
		else
			return (map->east); // Si le rayon va vers l'est, mur Est
	}
	else // Mur Est-Ouest
	{
		if (ray->rayDirY > 0)
			return (map->north); // Si le rayon va vers le nord, mur Nord
		else
			return (map->south); // Si le rayon va vers le sud, mur Sud
	}
}

int	ft_calculate_texture_x(t_ray *ray, t_player *player, t_texture *texture)
{
	double	wallX;
	int		texX;

	// Calcul de la position exacte où le mur a été touché
	if (ray->side == 0)
		wallX = player->y + ray->perpWallDist * ray->rayDirY;
	else
		wallX = player->x + ray->perpWallDist * ray->rayDirX;
	wallX -= floor(wallX);
	// Prend uniquement la partie décimale (fractionnaire)
	// Convertit cette position en coordonnée sur la texture
	texX = (int)(wallX * (double)(texture->width));
	// Ajuste pour l'orientation du mur
	if (ray->side == 0 && ray->rayDirX > 0)
		texX = texture->width - texX - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		texX = texture->width - texX - 1;
	// Debug : affichage de texX
	// printf("TexX calculated: %d\n", texX);
	return (texX);
}

int	ft_calculate_texture_y(int y, int line_height, t_texture *texture,
		t_data *data)
{
	int	texY;
	int	d;

	// Calcul de la position du pixel en Y dans la texture
	d = y * 256 - data->win_height * 128 + line_height * 128;
	texY = ((d * texture->height) / line_height) / 256;
	// Debug : affichage de texY
	printf("TexY calculated: %d\n", texY);
	return (texY);
}

unsigned int	ft_get_texture_color(t_texture *texture, int texX, int texY)
{
	char			*pixel;
	unsigned int	color;

	// Récupération de l'adresse du pixel dans la texture
	pixel = texture->addr + (texY * texture->line_length + texX
			* (texture->bits_per_pixel / 8));
	// Conversion de l'adresse en couleur (unsigned int)
	color = *(unsigned int *)pixel;
	// Debug : affichage de la couleur
	printf("Texture Color at (texX: %d, texY: %d): %u\n", texX, texY, color);
	return (color);
}

void	ft_draw_texture(t_data *data, t_texture *texture, int x, int y_start,
		int y_end, int texX, int line_height)
{
	int y = y_start;
	unsigned int color;

	while (y < y_end)
	{
		int texY = ft_calculate_texture_y(y, line_height, texture, data);

		color = ft_get_texture_color(texture, texX, texY);

		// Affichage du pixel sur l'écran
		my_mlx_pixel_put(texture, x, y, color);

		y++;
	}
}