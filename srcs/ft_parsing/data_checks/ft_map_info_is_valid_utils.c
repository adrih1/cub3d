/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info_is_valid_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:38:58 by ahors             #+#    #+#             */
/*   Updated: 2024/09/24 13:53:29 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_len_of_chars_double_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return(i);
}

int	ft_color_has_no_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_colors_has_no_numbers(char **colors)
{
    int i;

    i = 0;
    while (colors[i])
    {
        if(ft_color_has_no_numbers(colors[i]))
            return (1);
        i++;
    }    
    return (0);
}