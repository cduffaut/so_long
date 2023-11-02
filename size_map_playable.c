/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map_playable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:15:04 by csil              #+#    #+#             */
/*   Updated: 2023/10/31 23:10:24 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/*
	0 pour un emplacement vide,
	1 pour un mur,
	C pour un item à collecter (C pour collectible),
	E pour une sortie (E pour exit),
	P pour la position de départ du personnage.

	• La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ.
*/

// Compte le nombre de P, E, C
void	count_item(t_so_long *stock)
{
	int	i;
	int	j;

	i = 0;
	while (i < stock->y)
	{
		j = 0;
		while (j < stock->x)
		{
			if (stock->map[i][j] == 'P')
				stock->player_nbr++;
			else if (stock->map[i][j] == 'E')
				stock->exit_nbr++;
			else if (stock->map[i][j] == 'C')
				stock->coin_nbr++;
			j++;
		}
		i++;
	}
	if (stock->exit_nbr != 1 || stock->player_nbr != 1 || stock->coin_nbr < 1)
	{
		ft_printf("Erreur\nLe nombre d'items est incohérent\n");
		free_map(stock);
	}
}

// Check si un élément non pris en compte est présent
void	is_an_intruder(t_so_long *stock)
{
	int	j;
	int	i;

	i = 0;
	while (i < stock->y)
	{
		j = 0;
		while (j < stock->x)
		{
			if (stock->map[i][j] != '0' && stock->map[i][j] != '1'
				&& stock->map[i][j] != 'P')
			{
				if (stock->map[i][j] != 'C' && stock->map[i][j] != 'E')
				{
					ft_printf ("Erreur\nLa map est remplie d'autre(s)");
					ft_printf (" élément(s) que ceux autorisés\n");
					free_map(stock);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_x_size(t_so_long *stock)
{
	int	i;

	if (stock->y < 4 && stock->x < 4)
	{
		ft_printf("Erreur\nLa map est trop petite\n");
		free_map(stock);
	}
	i = 0;
	(void) i;
	while (i < stock->y)
	{
		if (((int)ft_strlen(stock->map[i]) - 1) != stock->x)
		{
			ft_printf("Erreur\nLa map est irrègulière\n");
			free_map(stock);
		}
		i++;
	}
}

void	check_y_size(t_so_long *stock)
{
	if (stock->y < 3)
	{
		ft_printf("Erreur\nLa map est trop petite\n");
		free_map(stock);
	}
}

void	main_size_map_playable(t_so_long *stock)
{
	check_y_size(stock);
	check_x_size(stock);
	if (stock->y == stock->x)
	{
		ft_printf ("Erreur\nLa map n'est pas rectangle\n");
		free_map(stock);
	}
	is_an_intruder(stock);
	count_item(stock);
	check_top_bottom_walls(stock);
}
