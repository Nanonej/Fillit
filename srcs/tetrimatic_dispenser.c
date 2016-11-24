/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimatic_dispenser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:28:06 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/24 14:33:54 by lchim            ###   ########.fr       */
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

void		delete_tetriminos(int ascii_of_tetri, t_list *s_grid)
{
	int		y;
	int		x;

	y = 0;
	while (y < s_grid->size_grid)
	{
		x = 0;
		while (x < s_grid->size_grid)
		{
			if (s_grid->grid[y][x] == ascii_of_tetri)
				s_grid->grid[y][x] = 0;
			x++;
		}
		y++;
	}
}

int			place_tetriminos(int **piece, t_list *s_grid, int i_grid, \
															int j_grid)
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
				if (I >= s_grid->size_grid || J >= s_grid->size_grid \
					|| s_grid->grid[I][J] > 0)
				{
					delete_tetriminos(ascii_of_tetriminos(piece), s_grid);
					return (0);
				}
				s_grid->grid[I][J] = piece[i_piece][j_piece];
			}
	}
	return (1);
}
