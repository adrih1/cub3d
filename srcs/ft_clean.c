/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:14:30 by ahors             #+#    #+#             */
/*   Updated: 2024/09/16 15:12:43 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"


// Fonction pour libérer un tableau de chaînes de caractères
int free_char_array(char **array)
{
    int i = 0;

    if (!array)
        return (1);
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
    return (0);
}

// Fonction pour libérer toute la structure t_map
void ft_clean(t_map *map)
{
    if (!map)
        return;

    // Libérer le tableau dirty_grid
    if(free_char_array(map->dirty_grid))
        printf("Could not free map dirty grid\n");

    // Libérer le tableau grid
    // if(free_char_array(map->grid))
    //     printf("Could not free map grid\n");


    // Libérer les couleurs de f_color et c_color si elles existent
    // if(free_char_array(map->f_color))
        // printf("Could not free f_color\n");        
    // if(free_char_array(map->c_color))
        // printf("Could not free c_color\n");        


    // Libérer les textures si elles ont été allouées dynamiquement
    // free(map->north_textxure);
    // free(map->east_textxure);
    // free(map->south_textxure);
    // free(map->west_textxure);

    // Libérer d'autres éléments si nécessaire, par exemple si `t_data` contient
    // des allocations dynamiques, elles doivent également être libérées ici
    // free(map->data.some_allocated_pointer);  <-- exemple

    // Enfin, libérer la structure elle-même
    free(map);
}
