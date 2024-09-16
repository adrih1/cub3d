/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/16 15:51:25 by ahors            ###   ########.fr       */
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
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
-------------------------------------------------------------
|                       STRUCTURES                           |
-------------------------------------------------------------
*/

// Structure pour représenter la map

typedef struct s_render_v
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

typedef struct s_map
{
	int		m_width;
	int		m_height;
	char	**dirty_grid;
	char	**grid;
	int		player_x;
	int		player_y;
	char	*north_textxure;
	char	*east_textxure;
	char	*south_textxure;
	char	*west_textxure;
	char	**f_color;
	char	**c_color;
	t_data	data;
}			t_map;

/*
-------------------------------------------------------------
|                       FONCTIONS                           |
-------------------------------------------------------------
*/

/************ INIT ************/
int			init_mlx(t_data *data);

/************ PARSING ************/
// Debug Display - To Be Deleted
void		ft_display_grid(t_map *map, char *grid_name);
void		ft_display_colors(t_map *map);
int			ft_message_error(char *error);
int			ft_executor(t_map *map);

// Utils
int			ft_open_file(char *filename);
int			ft_find_file_height(int fd);
int			ft_map_copy_lines(int fd, t_map *map);
char		*ft_str_trim(char *str, char c);

// First Step
int			ft_check_trimmed_has_char(char *str);
void		ft_clean_dirty_map(t_map *map);
int			ft_generate_dirty_map_file(int fd, t_map *map, char *filename);
// Second Step - Storing map info in our map structure
int			ft_find_f_color(char *str);
int			ft_find_c_color(char *str);
int			ft_find_colors(t_map *map);
int			ft_find_textures(t_map *map);
int			ft_map_find_info(t_map *map);
// Third Step - Building the actual map grid
int			ft_generate_map_file(t_map *map);
// Fourth Step
int			ft_parsing(t_map *map, char *filename);

/************ EXECUTOR ************/
int			ft_executor(t_map *map);

/************ CLEANING ************/
void		ft_clean(t_map *map);

#endif