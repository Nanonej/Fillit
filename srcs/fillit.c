/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:18:45 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/23 21:03:24 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	lsq(int npieces)
{
	if (npieces == 1)
		return (2);
	else if (npieces == 2)
		return (3);
	else if (npieces >= 3 && npieces <= 4)
		return (4);
	else if (npieces >= 5 && npieces <= 6)
		return (5);
	else if (npieces >= 7 && npieces <= 9)
		return (6);
	else if (npieces >= 10 && npieces <= 12)
		return (7);
	else if (npieces >= 13 && npieces <= 16)
		return (8);
	else if (npieces >= 17 && npieces <= 20)
		return (9);
	else if (npieces >= 21 && npieces <= 25)
		return (10);
	else if (npieces == 26)
		return (11);
	return (0);
}

static void	backtracking(int ***pieces, t_list *s_grid, int npieces, int i)
{
	int			x;
	int			y;

	set_grid(s_grid);
	y = 0;
	while (y < s_grid->size_grid)
	{
		x = 0;
		while (x < s_grid->size_grid)
		{
			if (place_tetriminos())
			{
				if ((i + 1) != npieces)
					backtracking(pieces, size_grid, npieces, (i + 1));
				else
					print_grid(grid, size_grid);
			}
			x++;
		}
		y++;
	}
}

void		fill_grid(int ***pieces, int npieces)
{
	t_list *s_grid;

	if (!(s_grid = (t_list*)malloc(sizeof(t_list))) == NULL)
		fill_error(0);
	s_grid->size_grid = lsq(npieces) - 1;
	while (s_grid->size_grid = s_grid->size_grid + 1)
		backtracking(pieces, s_grid, npieces, 0);
}
