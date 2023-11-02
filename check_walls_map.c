/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:52:33 by csil              #+#    #+#             */
/*   Updated: 2023/10/31 22:20:49 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check si on a bien des 1 sur tous les côtés
void	check_sides_walls(t_so_long *stock)
{
	int	i;

	i = 0;
	while (i < stock->y)
	{
		if (stock->map[i][0] != '1' || stock->map[i][(stock->x) - 1] != '1')
		{
			ft_printf("Erreur\nLes murs des côtés ne sont pas complets\n");
			free_map(stock);
		}
		i++;
	}
}

// Check si on a bien des 1 sur tout le haut et le bas
void	check_top_bottom_walls(t_so_long *stock)
{
	int	j;

	j = 0;
	while (j < stock->x)
	{
		if (stock->map[0][j] != '1' || stock->map[(stock->y) - 1][j] != '1')
		{
			ft_printf("Erreur\nLes murs haut ou bas ne sont pas complets\n");
			free_map(stock);
		}
		j++;
	}
	check_sides_walls(stock);
}
