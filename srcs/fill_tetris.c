/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:45:18 by lchim             #+#    #+#             */
/*   Updated: 2016/11/22 10:09:00 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_tetriminos(char *buff)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*buff)
	{
		if (*buff == '\n')
			count++;
		i++;
		buff++;
	}
	if ((i - count) % 16 != 0)
		fill_error(3);
	if ((((i - count) / 16) * 5 - 1) != count)
		fill_error(3);
	return ((i - count) / 16);
}

void		malloc_tetris(int ***tetris, int nb_tetris)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_tetris)
	{
		if ((tetris[i] = (int **)malloc(sizeof(int *) * 4)) == NULL)
			fill_error(0);
		j = 0;
		while (j < 4)
		{
			if ((tetris[i][j] = (int *)malloc(sizeof(int) * 4)) == NULL)
				fill_error(0);
			j++;
		}
		i++;
	}
}

void		fill_start(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		***tetris;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	printf("%d\n", count_tetriminos(buff));
	tetris = (int ***)malloc(sizeof(int **) * (count_tetriminos(buff) + 1));
	if (tetris == NULL)
		fill_error(0);
	tetris[count_tetriminos(buff)] = NULL;
	fill_tetris(tetris, count_tetriminos(buff));
}
