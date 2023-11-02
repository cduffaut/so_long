/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_doable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:27:25 by csil              #+#    #+#             */
/*   Updated: 2023/10/31 23:06:04 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_map(t_so_long *stock)
{
	int	i;
	int	j;

	i = 0;
	while (i < stock->y)
	{
		j = 0;
		while (j < stock->x)
		{
			if (stock->map_bis[i][j] == 'C' || stock->map_bis[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	do_path(t_so_long *stock, int i, int j, int checker)
{
	if (stock->map_bis[i - 1][j] == 'C' || stock->map_bis[i - 1][j] == 'E'
		|| stock->map_bis[i - 1][j] == '0')
	{
		stock->map_bis[i - 1][j] = 'P';
		checker++;
	}
	if (stock->map_bis[i + 1][j] == 'C' || stock->map_bis[i + 1][j] == 'E'
		|| stock->map_bis[i + 1][j] == '0')
	{
		stock->map_bis[i + 1][j] = 'P';
		checker++;
	}
	if (stock->map_bis[i][j - 1] == 'C' || stock->map_bis[i][j - 1] == 'E'
		|| stock->map_bis[i][j - 1] == '0')
	{
		stock->map_bis[i][j - 1] = 'P';
		checker++;
	}
	if (stock->map_bis[i][j + 1] == 'C' || stock->map_bis[i][j + 1] == 'E'
		|| stock->map_bis[i][j + 1] == '0')
	{
		stock->map_bis[i][j + 1] = 'P';
		checker++;
	}
	return (checker);
}

// Fonction qui change tous les items "parcourables" en P
int	take_all_path_possible(t_so_long *stock)
{
	int	i;
	int	j;
	int	checker;

	i = 0;
	checker = 0;
	while (i < stock->y)
	{
		j = 0;
		while (j < stock->x)
		{
			if (stock->map_bis[i][j] == 'P')
			{
				checker += do_path(stock, i, j, 0);
			}
			j++;
		}
		i++;
	}
	return (checker);
}

void	main_is_map_doable(t_so_long *stock)
{
	int	checker;

	checker = 1;
	while (checker > 0)
		checker = take_all_path_possible(stock);
	if (do_map(stock) == 1)
	{
		ft_printf ("Erreur\nLa map n'est pas faisable\n");
		free_map(stock);
	}
}
