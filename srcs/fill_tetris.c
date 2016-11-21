/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:45:18 by lchim             #+#    #+#             */
/*   Updated: 2016/11/21 11:51:53 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>



void		fill_get_tetris(int *tetriminos, char *buff)
{
	while (*buff)
	{
		if (*buff == '.')
			*tetriminos = 0;
		if (*buff == '#')
			*tetriminos = 1;
		if (*buff == '\n')
			*tetriminos = -1;
		buff++;
		tetriminos++;
	}
	*tetriminos = -2;
}

void		fill_read_tetris(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		tetriminos[BUFF_SIZE + 1];
	int		i = 0;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	fill_tetris_error(buff);
	fill_get_tetris(tetriminos, buff);
	//test affichage
	while (i < 22)
	{
		printf("%d\n", tetriminos[i]);
		i++;
	}
}
