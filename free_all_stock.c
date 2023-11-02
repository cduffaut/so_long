/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:48:00 by csil              #+#    #+#             */
/*   Updated: 2023/11/01 17:49:55 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_so_long *stock)
{
	if (stock->collectible)
		mlx_destroy_image(stock->mlx_initialisation, stock->collectible);
	if (stock->wall)
		mlx_destroy_image(stock->mlx_initialisation, stock->wall);
	if (stock->floor)
		mlx_destroy_image(stock->mlx_initialisation, stock->floor);
	if (stock->final_exit)
		mlx_destroy_image(stock->mlx_initialisation, stock->final_exit);
	if (stock->player)
		mlx_destroy_image(stock->mlx_initialisation, stock->player);
	if (stock->exit_tmp)
		mlx_destroy_image(stock->mlx_initialisation, stock->exit_tmp);
}

void	free_before_exit(t_so_long *stock)
{
	int		i;

	i = 0;
	while (i < stock->y)
	{
		free(stock->map[i]);
		free(stock->map_bis[i]);
		i++;
	}
	free(stock->map);
	free(stock->map_bis);
}

int	free_map(t_so_long *stock)
{
	if (stock->mlx_window && stock->mlx_initialisation)
		mlx_destroy_window(stock->mlx_initialisation, stock->mlx_window);
	destroy_img(stock);
	if (stock->map)
		free_before_exit(stock);
	exit(0);
}
