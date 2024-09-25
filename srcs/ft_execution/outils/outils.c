/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:25:37 by edouard           #+#    #+#             */
/*   Updated: 2024/09/25 10:46:09 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_message_error(char *error)
{
	perror(error);
	return (1);
}

void	ft_exit_error(char *error)
{
	perror(error);
	exit(1);
}

void *load_texture(void *mlx_ptr, char *path)
{
	int width;
	int height;

	void *texture = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);

	if (!texture)
	{
		printf("Error loading texture: %s\n", path);
		return NULL;
	}
	return texture;
}

int rgb_to_int(char **color)
{
	int r = atoi(color[0]);
	int g = atoi(color[1]);
	int b = atoi(color[2]);
	return (r << 16) | (g << 8) | b;
}