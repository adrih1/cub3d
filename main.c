/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:51 by ahors             #+#    #+#             */
/*   Updated: 2024/09/12 16:30:05 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int  main(int ac, char **av)
{
    if (ac != 2)
        printf("Please give a .cub file for the map\n");
    else
        // MinilibX - Initialisation de la fenetre 
        // Map Init - Parsing
        if(ft_parsing(av[1]))
        {
            // Clean - Exit
            return(1);
        } 
            
            
        // The Game
            //Casting the Rays
            //Rendering the walls
            //Playr Movement
        //Clean
        
    return (0);
}
