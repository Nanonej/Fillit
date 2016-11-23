/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:49:58 by lchim             #+#    #+#             */
/*   Updated: 2016/11/23 15:11:54 by lchim            ###   ########.fr       */
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

int			fill_is_tetrimino(int count)
{
	if (count >= 111 && count <= 114)
		return (1);
	if (count == 121 || count == 131 || count == 134 || count == 141)
		return (1);
	if (count == 144 || count == 211 || count ==  311 || count == 313)
		return (1);
	if (count == 314 || count == 411 || count == 413 || count == 414)
		return (1);
	if (count == 431 || count == 441 || count == 444)
		return (1);
	return (0);
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
		if (nb_part != 4)
			count++;
		if (count % 10 == 9)
			fill_error(3);
		if (tmp[i] == char_part && nb_part != 4)
		{
			count *= 10;
			nb_part++;
		}
	}
	if (fill_is_tetrimino(count / 10) == 0)
		fill_error(3);
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
