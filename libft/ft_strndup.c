/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:07:14 by edouard           #+#    #+#             */
/*   Updated: 2024/09/04 13:44:51 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(str);
	if (n > len)
		n = len;
	copy = (char *)malloc((n + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strncpy(copy, str, n);
	copy[n] = '\0';
	return (copy);
}
