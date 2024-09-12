/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/12 17:02:46 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
typedef struct s_map
{
	int		m_width;
	int		m_height;
	char	**dirty_grid;
	char	**grid;
	int		player_x;
	int		player_y;
	void	*north_textxure;
	void	*east_textxure;
	void	*south_textxure;
	void	*west_textxure;
	char	**f_color;
	char	**c_color;

}			t_map;

/*
-------------------------------------------------------------
|                       FONCTIONS                           |
-------------------------------------------------------------
*/

/************ WINDOW INIT ************/

/************ PARSING ************/
//Debug Display - To Be Deleted
void    ft_display_grid(t_map *map, char *grid_name); 
void    ft_display_colors(t_map *map); 


// Utils
int			ft_open_file(char *filename);
int			ft_find_file_height(int fd);
int			ft_map_copy_lines(int fd, t_map *map);
char		*ft_str_trim(char *str, char c);

// First Step
void		ft_clean_dirty_map(t_map *map); 
int			ft_generate_dirty_map_file(int fd, t_map *map, char *filename);
// Second Step
int			ft_find_f_color(char *str); 
int			ft_find_c_color(char *str); 
int 		ft_find_colors(t_map *map); 
int			ft_map_find_info(t_map *map); 

// Third Step
int			ft_generate_map_file(t_map *map);
// Fourth Step

int			ft_parsing(char *filename);

#endif