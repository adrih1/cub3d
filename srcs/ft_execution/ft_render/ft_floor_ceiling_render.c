/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_ceiling_render.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:41:07 by ahors             #+#    #+#             */
/*   Updated: 2024/10/15 17:11:03 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_image_data(void *img, int *bytes_per_pixel, int *size_line,
		int *endian)
{
	char	*data_addr;

	data_addr = mlx_get_data_addr(img, bytes_per_pixel, size_line, endian);
	if (!data_addr)
		ft_message_error("Error getting image data address\n");
	return (data_addr);
}

int	ft_fill_image(t_map *map, void *img, int color_int)
{
	int		y;
	char	*data_addr;
	int		bytes_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		*dst;

	y = 0;
	data_addr = ft_get_image_data(img, &bytes_per_pixel, &size_line, &endian);
	if (!data_addr)
		return (ft_message_error("Error getting image data address\n"));
	while (y < map->data->win_height / 2)
	{
		x = 0;
		while (x < map->data->win_width)
		{
			dst = (int *)(data_addr + (y * size_line) + (x * (bytes_per_pixel
							/ 8)));
			*dst = color_int;
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_create_and_fill_image(t_map *map, int color_int, void **img_ptr)
{
	void	*image;
	int		status;

	image = mlx_new_image(map->data->mlx_ptr, map->data->win_width,
			map->data->win_height / 2);
	*img_ptr = image;
	if (!(*img_ptr))
		return (ft_message_error("Error creating image\n"));
	status = ft_fill_image(map, *img_ptr, color_int);
	if (status)
	{
		mlx_destroy_image(map->data->mlx_ptr, *img_ptr);
		return (1);
	}
	return (0);
}

// void	ft_render_floor_ceiling(t_map *map)
// {
// 	int ceiling_color_int;
// 	int floor_color_int;
// 	void *img_ceiling;
// 	void *img_floor;

// 	ceiling_color_int = rgb_to_int(map->c_color);
// 	floor_color_int = rgb_to_int(map->f_color);

// 	if (ft_create_and_fill_image(map, ceiling_color_int, &img_ceiling))
// 	{
// 		mlx_destroy_image(map->data->mlx_ptr, img_ceiling);
// 		return ;
// 	}
// 	if (ft_create_and_fill_image(map, floor_color_int, &img_floor))
// 	{
// 		mlx_destroy_image(map->data->mlx_ptr, img_floor);
// 		return ;
// 	}
// 	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, img_ceiling,
// 		0, 0);
// 	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, img_floor,
// 		0, map->data->win_height / 2);

// 	mlx_destroy_image(map->data->mlx_ptr, img_ceiling);
// 	mlx_destroy_image(map->data->mlx_ptr, img_floor);
// }

void	ft_render_floor_ceiling(t_map *map)
{
	int ceiling_color_int;
	int floor_color_int;
	int x, y;

	ceiling_color_int = rgb_to_int(map->c_color);
	floor_color_int = rgb_to_int(map->f_color);

	y = 0;
	while (y < map->data->win_height / 2)
	{
		x = 0;
		while (x < map->data->win_width)
		{
			my_mlx_pixel_put(map->main_image, x, y, ceiling_color_int);
			x++;
		}
		y++;
	}
	while (y < map->data->win_height)
	{
		x = 0;
		while (x < map->data->win_width)
		{
			my_mlx_pixel_put(map->main_image, x, y, floor_color_int);
			x++;
		}
		y++;
	}
}
