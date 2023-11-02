/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:17:01 by csil              #+#    #+#             */
/*   Updated: 2023/11/01 17:47:52 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"

# ifndef SPRITE
#  define SPRITE 	64
# endif

# define UP_KEY		13
# define DOWN_KEY	1
# define LEFT_KEY	0
# define RIGHT_KEY	2
# define ESC		53

// x for the char nbr
// y for the str nbr
typedef struct s_so_long
{
	char	**map;
	char	**map_bis;
	int		x;
	int		y;
	int		coin_nbr;
	int		exit_nbr;
	int		player_nbr;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	void	*mlx_initialisation;
	void	*mlx_window;
	void	*collectible;
	void	*wall;
	void	*floor;
	void	*final_exit;
	void	*player;
	void	*exit_tmp;
	int		img_x;
	int		img_y;
	int		move_counter;
}			t_so_long;

// main of so_long

int		main(int argc, char **argv);

// check errors map

void	check_error_input(int argc, char **argv, t_so_long *stock);
int		extension_map(char *str);
void	main_size_map_playable(t_so_long *stock);
void	check_y_size(t_so_long *stock);
void	check_x_size(t_so_long *stock);
void	place_exit_player(t_so_long *stock);
void	check_top_bottom_walls(t_so_long *stock);
void	check_sides_walls(t_so_long *stock);
void	place_exit_player(t_so_long *stock);
void	init_map(char **argv, t_so_long *stock);

// parsing

void	main_is_map_doable(t_so_long *stock);
int		take_all_path_possible(t_so_long *stock);
int		do_path(t_so_long *stock, int i, int j, int checker);
int		do_map(t_so_long *stock);

// screen launching

void	push_img(t_so_long *stock);
void	set_img(t_so_long *stock);
void	exit_push_img(t_so_long *stock);
void	final(t_so_long *stock, void *item, int x, int y);

// game program

int		main_treat_moove(int key_press, t_so_long *stock);
void	assign_moove_to_key_press(int key_press, t_so_long *stock);
void	push_next_moove(t_so_long *stock, int next_y, int next_x);
void	finished(t_so_long *stock);

// free and exit 

int		free_map(t_so_long *stock);
void	free_before_exit(t_so_long *stock);
void	destroy_img(t_so_long *stock);

#endif
