/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:45:18 by lchim             #+#    #+#             */
/*   Updated: 2016/11/25 11:27:00 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_tetriminos(char *buff)
{
	int		i;
	int		count;
	int		nb_part;

	i = 0;
	count = 0;
	nb_part = 0;
	while (*buff && i++ != 546)
	{
		if (*buff == '#')
			nb_part++;
		if (*buff != '#' && *buff != '.' && *buff != '\n')
			fill_error(3);
		if (*buff == '\n' && *(buff + 1) == '\n' && *(buff + 2) == '\n')
			fill_error(3);
		if (*buff++ == '\n')
			count++;
	}
	if ((((i - count) / 16) * 4) != nb_part)
		fill_error(3);
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

void		fill_tetris(int ***tetris, int nb_tetris, char *buff)
{
	int		i;
	int		j;
	int		k;
	int		char_part;

	i = -1;
	char_part = 1;
	while (++i < nb_tetris)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				while (*buff == '\n' && *buff)
					buff++;
				tetris[i][j][k] = (*buff == '.' ? 0 : char_part);
				buff++;
			}
		}
		fill_true_tetris(tetris[i], char_part);
		char_part++;
	}
}

void		free_tetris(int ***tetris, int nb_tetris)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_tetris)
	{
		j = 0;
		while (j < 4)
		{
			free(tetris[i][j]);
			j++;
		}
		free(tetris[i]);
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
	check_char(buff);
	tetris = (int ***)malloc(sizeof(int **) * (count_tetriminos(buff)));
	if (tetris == NULL)
		fill_error(0);
	malloc_tetris(tetris, count_tetriminos(buff));
	fill_tetris(tetris, count_tetriminos(buff), buff);
	fill_grid(tetris, count_tetriminos(buff));
	free_tetris(tetris, count_tetriminos(buff));
	free(tetris);
}
