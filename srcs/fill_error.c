/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:49:58 by lchim             #+#    #+#             */
/*   Updated: 2016/11/23 13:57:16 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fill_error(int index)
{
	if (index == 0)
		ft_putstr_fd("Memory allocation failed\n", 2);
	else if (index == 1)
		ft_putstr_fd("open() error\n", 2);
	else if (index == 2)
		ft_putstr_fd("close() error\n", 2);
	else if (index == 3)
		ft_putstr_fd("error\n", 2);
	exit(EXIT_FAILURE);
}

void		fill_test_trimino(int *tmp, int char_part)
{
	int		i;
	int		count;
	int		nb_part;

	count = 0;
	nb_part = 1;
	i = 0;
	while (i < 16)
	{
		while (tmp[i] != char_part && count == 0)
			i++;
		i++;
		count++;
		if (tmp[i] == char_part && nb_part != 4)
		{
			count *= 10;
			nb_part++;
		}
	}
}

void		fill_true_tetris(int **tetrimino, int char_part)
{
	int		i;
	int		j;
	int		tmp[16];
	int		index;

	index = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp[index] = tetrimino[i][j];
			index++;
			j++;
		}
		i++;
	}
	fill_test_trimino(tmp, char_part);
}
