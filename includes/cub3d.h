/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:18 by ahors             #+#    #+#             */
/*   Updated: 2024/09/11 17:43:30 by ahors            ###   ########.fr       */
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
// Utils
int			ft_open_file(char *filename);
int			ft_find_map_height(int fd);
int			ft_map_copy_lines(int fd, t_map *map);
char		*ft_str_trim(char *str, char c);

// First Step
int			ft_generate_dirty_map_file(int fd, t_map *map, char *filename);
// Second Step
int			ft_generate_map_file(t_map *map);
// Third Step

int			ft_parsing(char *filename);

#endif