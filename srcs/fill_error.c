/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:49:58 by lchim             #+#    #+#             */
/*   Updated: 2016/11/19 17:09:31 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

void		fill_tetris_error(char *str)
{
	int		i;
	int		count;
	char	*tmp;

	i = 1;
	count = 0;
	tmp = str;
	while (*str)
	{
		if (i == 21 && (*str != '\n' && *str != '\0'))
			fill_error(3);
		if (i % 5 != 0 && i != 21 && (*str != '.' && *str != '#'))
			fill_error(3);
		if (i % 5 == 0 && *str != '\n')
			fill_error(3);
		if (*str == '#')
			count++;
		i++;
		str++;
	}
	if (count != 4)
		fill_error(3);
	fill_true_tetris(tmp, count);
}

void		fill_true_tetris(char *str, int part)
{
	int		i;
	int		is_col;

	i = -1;
	is_col = 1;
	while (part > 0 && ++i < 21)
	{
		if (str[i] == '#' && part-- > 0)
		{
			is_col = 0;
			if (str[i + 1] == '#')
				is_col = 1;
			if (i < 14)
				if (str[i + 5] == '#')
					is_col = 1;
			if (i - 1 > 0)
				if (str[i - 1] == '#')
					is_col = 1;
			if (i - 5 > 0)
				if (str[i - 5] == '#')
					is_col = 1;
		}
		if (is_col == 0)
			fill_error(3);
	}
}
