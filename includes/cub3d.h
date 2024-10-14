/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:18 by ahors             #+#    #+#             */
/*   Updated: 2024/10/14 15:18:44 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ROTATION_SPEED 0.05
# define MOVE_SPEED 0.05

# include "../mlx_lib/mlx.h"
# include "../mlx_lib/mlx_int.h"

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
typedef struct s_data
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
	int					width;
	int					height;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	struct s_texture	*next;
}						t_texture;

// Structure qui represente un rayon
typedef struct s_ray
{
	double				rayDirX;
	double				rayDirY;
	int					mapX;
	int					mapY;
	double				sideDistX;
	double				sideDistY;
	double				deltaDistX;
	double				deltaDistY;
	int					stepX;
	int					stepY;
	int					hit;
	int					side;
	double				perpWallDist;
}						t_ray;

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
	t_data				*data;
	t_player			*player;
	t_texture			*north;
	t_texture			*east;
	t_texture			*south;
	t_texture			*west;
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
char					*ft_skip_whitespaces(char *str);
char					*ft_skip_identifier(char *str);
char					*ft_delete_id_filename(char *str);
void					*ft_load_image(void *mlx_ptr, char *file_path,
							int *width, int *height);
int						ft_find_colors(t_map *map);
int						ft_find_textures(t_map *map);
int						ft_map_find_info(t_map *map);

// Third Step - Check Colors and Textures are valid
int						ft_len_of_chars_double_array(char **array);
int						ft_color_has_no_numbers(char *str);
int						ft_colors_has_no_numbers(char **colors);
int						ft_map_info_is_valid(t_map *map);

// Fourht Step - Building the actual map grid
int						ft_find_map_beginning(char **dirty_grid);
char					*ft_find_player(char *str);
int						ft_generate_map_grid_util(t_map *map);
int						ft_generate_map_grid(t_map *map);

// Fith Step - Check Map Grid
int						ft_map_grid_is_valid(t_map *map, char **grid);
// Main Function
int						ft_parsing(t_map *map, char *filename);

/************ RENDER ************/
// Fonction a supprimer plus tard - Dessine les murs de differentes couleurs
int						ft_choose_wall_color(int side, int stepX, int stepY);
void					ft_draw_vertical_line_with_color(void *mlx_ptr,
							void *win_ptr, int x, int drawStart, int drawEnd,
							int color);

void					my_mlx_pixel_put(t_texture *texture, int x, int y,
							int color);

// Textures
t_texture				*ft_select_texture(t_map *map, t_ray *ray);
int						ft_calculate_texture_x(t_ray *ray, t_player *player,
							t_texture *texture);
int						ft_calculate_texture_y(int y, int line_height,
							t_texture *texture, t_data *data);
unsigned int			ft_get_texture_color(t_texture *texture, int texX,
							int texY);
int						ft_load_textures(t_map *map);

// Wall / Ceilling
int						rgb_to_int(char **color);
void					ft_render_floor_ceiling(t_map *map);

// Main Functions
void					ft_raycasting(t_map *map);
int						ft_render_frame(t_map *map);

/************ MOVEMENT ************/
void					ft_move_player(int keynum, t_map *map);
void					ft_rotate_camera(int keynum, t_map *map);

/************ WINDOOW INIT + GAME LOOP ************/
int						ft_executor(t_map *map);

/************ CLEANING ************/
void					ft_clean(t_map *map);
int						ft_message_error(char *error);

#endif