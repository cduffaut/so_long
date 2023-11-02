/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:27:35 by csil              #+#    #+#             */
/*   Updated: 2023/11/01 10:45:29 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Add the position of Player and Exit into the struct
void	add_pos(t_so_long *stock)
{
	int	x;
	int	y;

	y = 0;
	while (y < stock->y)
	{
		x = 0;
		while (x < stock->x)
		{
			if (stock->map[y][x] == 'P')
			{
				stock->player_x = x;
				stock->player_y = y;
			}
			if (stock->map[y][x] == 'E')
			{
				stock->exit_x = x;
				stock->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

// Put all of the content of argv[1] into a tab
void	extract_map(char **argv, t_so_long *stock)
{
	int		fd;
	int		i;

	stock->map = ft_calloc(stock->y, sizeof(char *));
	fd = open(argv[1], 0);
	i = 0;
	while (i < stock->y)
	{
		stock->map[i] = get_next_line(fd);
		i++;
	}
	close (fd);
}

// Put all of the content of argv[1] into a copy_tab
void	extract_map_cpy(char **argv, t_so_long *stock)
{
	int		fd;
	int		i;

	stock->map_bis = ft_calloc(stock->y, sizeof(char *));
	fd = open(argv[1], 0);
	i = 0;
	while (i < stock->y)
	{
		stock->map_bis[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

// Check map size
void	check_map_size(char **argv, t_so_long *stock, int i)
{
	char	*tmp;
	int		fd;

	fd = open(argv[1], 0);
	if (fd < 0)
	{
		ft_printf("Erreur\nLa map n'a pas pu être lue\n");
		free_map(stock);
	}
	tmp = get_next_line(fd);
	stock->x = ft_strlen(tmp) - 1;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	stock->y = i - 1;
	close (fd);
	if ((stock->x * SPRITE) > 1920 || (stock->y * SPRITE) > 1080)
	{
		ft_printf("Erreur\nLa map est trop grande\n");
		free_map(stock);
	}
}

// Init the map
void	init_map(char **argv, t_so_long *stock)
{
	int		fd;
	int		count;
	char	*str;

	fd = open(argv[1], 0);
	count = read(fd, &str, 2);
	if (count < 0)
	{
		ft_printf("Erreur\nLa map n'est pas lisible\n");
		close(fd);
		free_map(stock);
	}
	if (count == 0)
	{
		ft_printf("Erreur\nLa map est vide\n");
		close (fd);
		free_map(stock);
	}
	close (fd);
	check_map_size(argv, stock, 1);
	extract_map(argv, stock);
	extract_map_cpy(argv, stock);
	check_top_bottom_walls(stock);
	main_size_map_playable(stock);
	add_pos(stock);
}
