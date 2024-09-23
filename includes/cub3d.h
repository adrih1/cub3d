/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/23 14:38:00 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_lib/mlx.h"

/*
-------------------------------------------------------------
|                       BIBLIOTHÈQUES                       |
-------------------------------------------------------------
*/

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
-------------------------------------------------------------
|                       STRUCTURES                           |
-------------------------------------------------------------
*/

// Enumération des types de tokens
typedef enum e_texture_type
{
	NORTH_TEXTURE,
	SOUTH_TEXTURE,
	EAST_TEXTURE,
	WEST_TEXTURE,
}						t_texture_type;

// Structure pour la fenetre de la MLX
typedef struct s_render_v
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					win_width;
	int					win_height;
}						t_data;

// Structure pour stocker les infos des textures
typedef struct s_texture
{
	t_texture_type		texture_id;
	char				*filename;
	void				*img_ptr;
	struct s_texture	*next;
}						t_texture;

// Structure pour représenter le player
typedef struct s_player
{
	double				x;
	double				y;
	double				dirX;
	double				dirY;
	double				planeX;
	double				planeY;
}						t_player;

// Structure pour représenter la map
typedef struct s_map
{
	int					m_width;
	int					m_height;
	int					real_height;
	char				**dirty_grid;
	char				**grid;
	t_texture			*textures;
	char				**f_color;
	char				**c_color;
	t_data				data;
	t_player			*player;
}						t_map;

/*
-------------------------------------------------------------
|                       FONCTIONS                           |
-------------------------------------------------------------
*/

/************ INIT ************/
int						init_mlx(t_data *data);

/************ PARSING ************/
// Debug Display - To Be Deleted
void					ft_display_grid(t_map *map, char *grid_name);
void					ft_display_colors(t_map *map);
void					ft_display_map_info(t_map *map);
void					ft_display_player_info(t_player *player);

// Parsing Utils
int						ft_open_file(char *filename);
int						ft_find_file_height(int fd);
int						ft_map_copy_lines(int fd, t_map *map);
int						ft_check_trimmed_has_char(char *str);
int						ft_find_map_height(t_map *map);

// First Step - Retrieving the file lines
int						ft_generate_dirty_map_file(int fd, t_map *map,
							char *filename);
// Second Step - Storing map info in our map structure
char					*ft_clean_id_whitespace_color(char *str);
char					*skip_whitespaces(char *str);
char					*ft_skip_identifier(char *str);
char					*ft_delete_id_filename(char *str);
int						ft_find_colors(t_map *map);
int						ft_find_textures(t_map *map);
int						ft_map_find_info(t_map *map);

// Third Step - Check Colors and Textures are valid
int						ft_map_info_is_valid(t_map *map);

// Fourht Step - Building the actual map grid
void					ft_generate_map_file_util(t_map *map);
int						ft_generate_map_file(t_map *map);

// Main Function
int						ft_parsing(t_map *map, char *filename);

/************ THE GAME ************/
// Window Init and Game Loop
int						ft_executor(t_map *map);
// Game Logic
int						ft_render_frame(t_map *map);
void					ft_raycasting(t_map *map);

/************ CLEANING ************/
void					ft_clean(t_map *map);
int						ft_message_error(char *error);

#endif