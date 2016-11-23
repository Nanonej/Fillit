/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nutrimatic_dispenser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bj: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:28:06 bj aridolfi          #+#    #+#             */
/*   Updated: 2016/11/22 15:25:44 bj aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	pos_tetriminos(int **piece)
{
	int pos;
	int i;
	int j;

	pos = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j])
				return (pos);
			pos++;
			j++;
		}
		pos++;
		i++;
	}
	return (-1);
}

/*	Faire un struct pour stocker grid avec size_grid */
int			place_tetriminos(int **piece, int **grid, int i_grid, int j_grid)
{
	int	i_pos;
	int j_pos;
	int i_piece;
	int j_piece;

	i_pos = pos_tetriminos(piece) / 4;
	j_pos = pos_tetriminos(piece) % 4;
	i_piece = -1;
	while (++i_piece < 4)
	{
		j_piece = -1;
		while (++j_piece < 4)
			if (piece[i_piece][j_piece] > 0)
			{
				if (I >= /* size_grid */ || J >= /* size_grid */ || grid[I][J] > 0)
				{
				/*	delete_tetri(grid, size_grid, ascii_of_tetri); */
					return (0);
				}
				grid[I][J] = piece[i_piece][j_piece];
			}
	}
	return (1);
}
