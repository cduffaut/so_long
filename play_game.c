/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:03:55 by csil              #+#    #+#             */
/*   Updated: 2023/11/01 17:49:18 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// But: assigner les touches a des mouvements
// Write chaque touches pressées avec un décompte

// If we've finished
void	finished(t_so_long *stock)
{
	stock->move_counter++;
	ft_printf ("Félicitations ! Vous avez gagné en ");
	ft_printf ("%d déplacements\n", stock->move_counter);
	free_map (stock);
}

// Moove the image
void	push_next_moove(t_so_long *stock, int next_y, int next_x)
{
	char	next_moove;

	next_moove = stock->map[stock->player_y + next_y][stock->player_x + next_x];
	if (next_moove == 'C' || next_moove == '0' || next_moove == 'P')
	{
		final(stock, stock->floor, stock->player_x * SPRITE, \
			stock->player_y * SPRITE);
		stock->player_x += next_x;
		stock->player_y += next_y;
		final(stock, stock->player, stock->player_x * SPRITE, \
			stock->player_y * SPRITE);
		if (next_moove == 'C')
		{
			stock->map[stock->player_y][stock->player_x] = '0';
			stock->coin_nbr--;
		}
		stock->move_counter++;
		ft_printf ("Vous avez fait %d déplacements\n", stock->move_counter);
	}
	else if (next_moove == 'F')
		finished(stock);
}

// Check wich mouvement do after a new pressing
void	assign_moove_to_key_press(int key_press, t_so_long *stock)
{
	if (key_press == UP_KEY)
		push_next_moove(stock, -1, 0);
	else if (key_press == DOWN_KEY)
		push_next_moove(stock, 1, 0);
	else if (key_press == LEFT_KEY)
		push_next_moove(stock, 0, -1);
	else if (key_press == RIGHT_KEY)
		push_next_moove(stock, 0, 1);
	else if (key_press == ESC)
		free_map(stock);
}

int	main_treat_moove(int key_press, t_so_long *stock)
{
	assign_moove_to_key_press(key_press, stock);
	if (stock->coin_nbr == 0)
	{
		final(stock, stock->final_exit, stock->exit_x * SPRITE, \
			stock->exit_y * SPRITE);
		stock->map[stock->exit_y][stock->exit_x] = 'F';
	}
	return (0);
}
