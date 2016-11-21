/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:47:52 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/21 14:52:28 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_grid(int **grid, int size)
{
	int y;
	int x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			grid[y][x] = 0;
			x++;
		}
		grid[y][x] = -2;
		y++;
	}
}

int			**set_grid(int size)
{
	int **grid;
	int n;

	n = 0;
	if (!(grid = (int**)malloc(sizeof(int*) * size)))
		fill_tetris_error(0);
	while (n < size)
	{
		if (!(grid[n] = (int*)malloc(sizeof(int) * (size + 1))))
			fill_tetris_error(0);
		n++;
	}
	init_grid(grid, size);
	return (grid);
}
