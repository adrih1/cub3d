/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:46:23 by ahors             #+#    #+#             */
/*   Updated: 2024/09/13 15:30:43 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_open_file(char *filename)
{
	int	fd;

	if (!filename)
		exit(1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Probleme pour pour ouvrir le fichier");
		return (-1);
	}
	return (fd);
}

int	ft_find_file_height(int fd)
{
	int		height;
	char	*line;
	char	*temp;

	height = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		temp = line;
		line = get_next_line(fd);
		free(temp);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	ft_map_copy_lines(int fd, t_map *map)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		temp = line;
		map->dirty_grid[i] = ft_strdup(line);
		line = get_next_line(fd);
		free(temp);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}

int	ft_check_trimmed_has_char(char *str)
{
	size_t	i;
	int		has_chars;

	i = 0;
	has_chars = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isalnum(str[i]))
		{
			has_chars = 1;
			return (has_chars);
		}
		i++;
	}
	return (has_chars);
}

char	*ft_str_trim(char *str, char c)
{
	int		len;
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	trimmed = (char *)malloc(len + 1);
	if (!trimmed)
		return (NULL);
	while (i < len)
	{
		if (str[i] != c)
		{
			trimmed[j] = str[i];
			j++;
		}
		i++;
	}
	trimmed[j] = '\0';
	if (ft_check_trimmed_has_char(trimmed))
		return (trimmed);
	else
		return ("");
}
