/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:48:05 by ahors             #+#    #+#             */
/*   Updated: 2024/09/27 16:23:12 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_find_player(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'O')
			return (str);
		i++;
	}
	return (NULL);
}

int ft_check_is_grid_beginning(char *str)
{
    int i;
	int count_one;

    i = 0;
	count_one = 0;
    while (str[i])
    {
		if (str[i] == '1')
		{
			count_one++;
			i++;
		}
		else if (str[i] == '\n' ||str[i] == ' ')	
			i++;
		else 
			return (0);
    }
	if(count_one >= 3)
    	return (1);
	return(0);
}


int	ft_find_map_beginning(char **dirty_grid)
{
	int i;
	int j;
	char **temp;

	i = 0;
	temp = dirty_grid;
	while (temp[i])
	{
		j = 0;
		while(temp[i][j] == ' ')
			j++;
		if (ft_check_is_grid_beginning(temp[i]))
			return (i);
		i++;
	}
	free(temp);
	return (0);
}