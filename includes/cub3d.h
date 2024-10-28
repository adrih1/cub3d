/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:18 by ahors             #+#    #+#             */
/*   Updated: 2024/10/28 08:42:23 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#define ROTATION_SPEED 0.05
#define MOVE_SPEED 0.05

#include "../mlx_lib/mlx.h"
#include "../mlx_lib/mlx_int.h"

/*
-------------------------------------------------------------
|                       BIBLIOTHÈQUES                       |
-------------------------------------------------------------
*/

#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
} t_texture_type;

// Structure pour la fenetre de la MLX
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	int win_width;
	int win_height;
} t_data;

typedef struct s_window
{
	int width;
	int height;
} t_window;

typedef struct s_raycasting
{
	double pos_x;	 // Position de player
	double pos_y;	 // Position de player
	double dir_x;	 // Direction de player
	double dir_y;	 // Direction de player
	double plane_x; // Direction de la camera
	double plane_y; // Direction de la camera
} t_raycasting;

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
	t_raycasting raycasting;
} t_map;
// Structure pour stocker les infos des textures
typedef struct s_texture
{
	t_texture_type texture_id;
	char *filename;
	int width;
	int height;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_texture;

// Structure qui represente un rayon
typedef struct s_ray
{
	double ray_dir_x;
	double ray_dir_y;
	int map_x;
	int map_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	int step_x;
	int step_y;
	int hit;
	int side;
	double perp_wall_dist;
	int line_height;
	int draw_start;
	int draw_end;
	int color;
} t_ray;

// Structure pour représenter le player
typedef struct s_player
{
	double x;
	double y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
} t_player;

// Structure pour représenter la map
typedef struct s_map
{
	int last_info_found;
	int nb_textures;
	int textures_found;
	int nb_players;
	int m_width;
	int m_height;
	int begin;
	int end;
	size_t longest_str;
	int real_height;
	char **dirty_grid;
	char **grid;
	char **f_color;
	char **c_color;
	t_data *data;
	t_player *player;
	t_texture *north;
	t_texture *east;
	t_texture *south;
	t_texture *west;
	t_texture *main_image;
} t_map;

/*
-------------------------------------------------------------
|                       FONCTIONS                           |
-------------------------------------------------------------
*/

/************ INIT ************/
int init_mlx(t_data *data);

/************ PARSING ************/
// Debug Display - To Be Deleted
void ft_display_grid(t_map *map, char *grid_name);
void ft_display_colors(t_map *map);
void ft_display_map_info(t_map *map);
void ft_display_player_info(t_player *player);

// Parsing Utils
int ft_open_file(char *filename);
int ft_find_file_height(int fd);
int ft_map_copy_lines(int fd, t_map *map);
int ft_check_trimmed_has_char(char *str);
int ft_find_map_height(t_map *map);

// First Step - Retrieving the file lines
int ft_generate_dirty_map_file(int fd, t_map *map,
										 char *filename);
// Second Step - Storing map info in our map structure
char *ft_clean_id_whitespace_color(char *str);
char *ft_skip_whitespaces(char *str);
char *ft_skip_identifier(char *str);
char *ft_delete_id_filename(char *str);
void *ft_load_image(void *mlx_ptr, char *file_path, int *width,
						  int *height);
int ft_find_colors(t_map *map);
int ft_find_textures(t_map *map);
int ft_map_find_info(t_map *map);

// Third Step - Check Colors and Textures are valid
int ft_len_of_chars_double_array(char **array);
int ft_color_has_no_numbers(char *str);
int ft_colors_has_no_numbers(char **colors);
int ft_map_info_is_valid(t_map *map);
void ft_last_info_found(t_map *map, int new_index_last_info);

// Fourht Step - Building the actual map grid
int ft_find_map_beginning(char **dirty_grid);
int ft_find_map_end(t_map *map);
int ft_find_map_longest_str(t_map *map);
int ft_init_player(t_map *map, char *str, int y);
int ft_find_player(t_map *map);
int ft_generate_map_grid_util(t_map *map);
int ft_generate_map_grid(t_map *map);

// Fith Step - Check Map Grid
int ft_map_has_one_player_is_valid(t_map *map);
int ft_check_unvalid_chars(char c);
int ft_check_player_can_exit_map(t_map *map);
int ft_check_has_only_walls_spaces(char *str);
int ft_check_ones_end_begin(char *str);

int ft_map_grid_is_valid(t_map *map);
// Main Function
int ft_parsing(t_map *map, char *filename);

/************ RENDER ************/
// Init
int ft_init_mlx(t_data *data);
int ft_init_main_image(t_data *data, t_texture *texture);

// Outils
void ft_clear_window(t_data *data, t_texture *texture);
void my_mlx_pixel_put(t_texture *texture, int x, int y,
							 int color);

// Textures
t_texture *ft_select_texture(t_map *map, t_ray *ray);
int ft_calculate_texture_x(t_ray *ray, t_player *player,
									t_texture *texture);
int ft_calculate_texture_y(int y, int line_height,
									t_texture *texture, t_data *data);
unsigned int ft_get_texture_color(t_texture *texture, int texX,
											 int texY);
int ft_load_textures(t_map *map);

// Wall / Ceilling
int rgb_to_int(char **color);
void ft_render_floor_ceiling(t_map *map);

// Utils for raycasting
double ft_fabs(double n);
void ft_init_ray(t_ray *ray, t_player *player, int x,
					  int screenWidth);
// Main Functions
void ft_render_column(t_map *map, t_ray *ray, int x);

void ft_raycasting(t_map *map, t_ray *ray, int x);
void ft_render_frame(t_map *map);

/************ MOVEMENT ************/
void ft_move_player(int keynum, t_map *map);
void ft_move_camera(int keynum, t_map *map);

/************ WINDOOW INIT + GAME LOOP ************/
int ft_executor(t_map *map);

/************ CLEANING ************/
int free_char_array(char **array);
void ft_clean(t_map *map);
int ft_message_error(char *error);

#endif