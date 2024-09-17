/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_textures_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:05:54 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/17 17:48:39 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <ctype.h>

char *ft_skip_whitespaces(char *str)
{
	int i; 

	i = 0;
    while (str[i] && isspace(str[i]))
        i++;
    return (str + i);
}
char *ft_skip_identifier(char *str) 
{
    if (!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) || 
        !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2)) 
        return str + 2;
    return (str);
}

char *ft_delete_id_filename(char *str) {
    char *start;
    char *end;
    int length;
    char *filename;

    str = ft_skip_whitespaces(str);
    str = ft_skip_identifier(str);
    str = ft_skip_whitespaces(str);
    start = str;
    while (*str && !isspace((unsigned char)*str))
        str++;
    end = str;
    length = end - start;
    filename = (char *)malloc((length + 1) * sizeof(char));
    if (!filename)
        return NULL;
    ft_strncpy(filename, start, length);
    filename[length] = '\0'; 
    return (filename);
}