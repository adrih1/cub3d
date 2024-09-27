/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:25:37 by edouard           #+#    #+#             */
/*   Updated: 2024/09/27 18:54:14 by ahors            ###   ########.fr       */
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

int	ft_load_textures(t_texture *textures, t_data *data)
{
	int			i;
	t_texture	*current_texture;

	current_texture = textures;
	i = 0;
	if (!textures)
	{
		printf("List of textures does not exists\n");
		return (1);
	}
	while (current_texture)
	{
		current_texture->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				current_texture->filename, &current_texture->width, &current_texture->height);
		current_texture = current_texture->next;
	}
	return (0);
}

int	rgb_to_int(char **color)
{
	int r = atoi(color[0]);
	int g = atoi(color[1]);
	int b = atoi(color[2]);
	return ((r << 16) | (g << 8) | b);
}