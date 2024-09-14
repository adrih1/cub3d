/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/14 14:25:31 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../mlx_lib/mlx.h"

/*
-------------------------------------------------------------
|                       BIBLIOTHÈQUES                       |
-------------------------------------------------------------
*/

#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/*
-------------------------------------------------------------
|                       STRUCTURES                           |
-------------------------------------------------------------
*/

// Structure pour représenter la map

typedef struct s_render_v
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

typedef struct s_window
{
	int width;
	int height;
} t_window;

typedef struct s_map
{
	int m_width;
	int m_height;
	char **dirty_grid;
	char **grid;
	int player_x;
	int player_y;
	void *north_textxure;
	void *east_textxure;
	void *south_textxure;
	void *west_textxure;
	char **f_color;
	char **c_color;
	t_data data;
	t_window window;
} t_map;

/*
-------------------------------------------------------------
|                       FONCTIONS                           |
-------------------------------------------------------------
*/

/************ WINDOW INIT ************/

/************ PARSING ************/
// Debug Display - To Be Deleted
void ft_display_grid(t_map *map, char *grid_name);

// Utils
int ft_open_file(char *filename);
int ft_find_file_height(int fd);
int ft_map_copy_lines(int fd, t_map *map);
char *ft_str_trim(char *str, char c);

// First Step
void ft_clean_dirty_map(t_map *map);
int ft_generate_dirty_map_file(int fd, t_map *map, char *filename);
// Second Step
int ft_generate_map_file(t_map *map);
// Third Step

int ft_parsing(t_map *map, char *filename);

int ft_message_error(char *error);
int ft_executor(t_map *map);
void *load_texture(void *mlx_ptr, char *path);
int rgb_to_int(char **color);
void ft_render_floor_ceiling(t_map *map);
int ft_mock_data(t_map *map); // Mock Data - To Be Deleted
#endif