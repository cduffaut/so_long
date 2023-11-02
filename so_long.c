/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:25:25 by csil              #+#    #+#             */
/*   Updated: 2023/11/01 17:40:58 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_so_long	stock;

	stock = (t_so_long){};
	check_error_input(argc, argv, &stock);
	init_map(argv, &stock);
	main_is_map_doable(&stock);
	stock.mlx_initialisation = mlx_init();
	stock.mlx_window = mlx_new_window(stock.mlx_initialisation, \
		stock.x * SPRITE, stock.y * SPRITE, "so_long");
	push_img(&stock);
	mlx_key_hook(stock.mlx_window, main_treat_moove, &stock);
	mlx_hook(stock.mlx_window, 17, 1L << 0, free_map, &stock);
	mlx_loop(stock.mlx_initialisation);
	return (0);
}
