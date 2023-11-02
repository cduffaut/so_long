/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_img_to_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:34:52 by csil              #+#    #+#             */
/*   Updated: 2023/10/31 22:28:58 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Final_push_to_screen
void	final(t_so_long *stock, void *item, int x, int y)
{	
	mlx_put_image_to_window(stock->mlx_initialisation, \
		stock->mlx_window, item, x, y);
}

// Exit (1) if error
void	exit_push_img(t_so_long *stock)
{
	ft_printf ("Erreur\nLes images n'ont pas pu être chargées\n");
	free_map(stock);
}

// Charge img into the program
void	set_img(t_so_long *stock)
{
	stock->collectible = mlx_xpm_file_to_image(stock->mlx_initialisation, \
		"./xpm/axe.xpm", &stock->img_x, &stock->img_y);
	if (!stock->collectible)
		exit_push_img(stock);
	stock->floor = mlx_xpm_file_to_image(stock->mlx_initialisation, \
		"./xpm/floor_street.xpm", &stock->img_x, &stock->img_y);
	if (!stock->floor)
		exit_push_img(stock);
	stock->wall = mlx_xpm_file_to_image(stock->mlx_initialisation, \
		"./xpm/brick_wall.xpm", &stock->img_x, &stock->img_y);
	if (!stock->wall)
		exit_push_img(stock);
	stock->player = mlx_xpm_file_to_image(stock->mlx_initialisation, \
		"./xpm/scream.xpm", &stock->img_x, &stock->img_y);
	if (!stock->player)
		exit_push_img(stock);
	stock->exit_tmp = mlx_xpm_file_to_image(stock->mlx_initialisation, \
		"./xpm/question_mark.xpm", &stock->img_x, &stock->img_y);
	if (!stock->exit_tmp)
		exit_push_img(stock);
	stock->final_exit = mlx_xpm_file_to_image(stock->mlx_initialisation, \
		"./xpm/house.xpm", &stock->img_x, &stock->img_y);
	if (!stock->final_exit)
		exit_push_img(stock);
}

// Push img to the screen
void	push_img(t_so_long *stock)
{
	int	i;
	int	j;

	set_img(stock);
	i = 0;
	while (i < stock->y)
	{
		j = 0;
		while (j < stock->x)
		{
			if (stock->map[i][j] == '0')
				final(stock, stock->floor, j * SPRITE, i * SPRITE);
			else if (stock->map[i][j] == '1')
				final(stock, stock->wall, j * SPRITE, i * SPRITE);
			else if (stock->map[i][j] == 'C')
				final(stock, stock->collectible, j * SPRITE, i * SPRITE);
			else if (stock->map[i][j] == 'E')
				final(stock, stock->exit_tmp, j * SPRITE, i * SPRITE);
			else if (stock->map[i][j] == 'P')
				final(stock, stock->player, j * SPRITE, i * SPRITE);
			j++;
		}
		i++;
	}		
}
