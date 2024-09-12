/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:25:37 by edouard           #+#    #+#             */
/*   Updated: 2024/09/12 19:36:48 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_message_error(char *error)
{
	perror(error);
	return 1;
}

void ft_exit_error(char *error)
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
