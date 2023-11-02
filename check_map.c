/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:02:53 by csil              #+#    #+#             */
/*   Updated: 2023/10/31 22:50:18 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_map(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r')
		return (1);
	else if (str[i - 1] != 'e')
		return (1);
	else if (str[i - 2] != 'b')
		return (1);
	else if (str[i - 3] != '.')
		return (1);
	return (0);
}

void	check_error_input(int argc, char **argv, t_so_long *stock)
{
	if (argc != 2)
	{
		ft_printf ("Erreur\nVeuillez rentrer un nombre d'argument valide\n");
		free_map(stock);
	}
	if (extension_map(argv[1]) == 1)
	{
		ft_printf ("Erreur\nL'extension n'est pas prise en charge\n");
		free_map(stock);
	}
}
