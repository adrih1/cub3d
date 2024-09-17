/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_colors_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:40:53 by ahors             #+#    #+#             */
/*   Updated: 2024/09/17 17:41:40 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_clean_id_whitespace_color(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ' && !ft_isalpha(str[i]))
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}