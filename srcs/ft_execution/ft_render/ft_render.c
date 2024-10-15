/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:16:46 by ahors             #+#    #+#             */
/*   Updated: 2024/10/15 16:01:36 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_column(t_map *map, t_ray *ray, int x)
{
    t_texture		*texture;
    int				texX;
	int				texY;
	int				y;
	unsigned int	color;


	texture = ft_select_texture(map, ray);
    texX = ft_calculate_texture_x(ray, map->player, texture);
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		// Calcul de la coordonnée Y dans la texture pour chaque pixel en Y
		texY = ft_calculate_texture_y(y, ray->line_height, texture, map->data);

		// Récupération de la couleur du pixel (texX, texY) dans la texture
		color = ft_get_texture_color(texture, texX, texY);

		// Affichage du pixel avec la couleur de la texture
		my_mlx_pixel_put(map->main_image, x, y, color);

		y++;
	}
}
// Fonction pour render l'ecran 
void	ft_render_frame(t_map *map)
{
	int x;
	t_ray ray;

	x = 0;
	while (x < map->data->win_width)
	{
		ft_raycasting(map, &ray, x);
		ft_render_column(map, &ray, x);
		x++;
	}
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr,
		map->main_image->img, 0, 0);
}