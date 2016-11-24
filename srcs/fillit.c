/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:18:45 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/24 16:25:13 by lchim            ###   ########.fr       */
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

static int	backtracking(int ***pieces, t_list *s_grid, int npieces, int x)
{
	int			i;
	int			j;
	int			test = 0;

	if (x == 0)
		set_grid(s_grid);
	i = 0;
	while (i < s_grid->size_grid)
	{
		j = 0;
		while (j < s_grid->size_grid)
		{
			if (place_tetriminos(pieces[x], s_grid, i, j))
			{
				if ((x + 1) != npieces)
					test = backtracking(pieces, s_grid, npieces, (x + 1));
				if ((x + 1) == npieces)
					return (print_grid(s_grid));
				else
					delete_tetriminos(ascii_of_tetriminos(pieces[x]), s_grid);
				return (test);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void		fill_grid(int ***pieces, int npieces)
{
	t_list *s_grid;

	if (!(s_grid = (t_list*)malloc(sizeof(t_list))))
		fill_error(0);
	s_grid->size_grid = lsq(npieces) - 1;
	while ((s_grid->size_grid = s_grid->size_grid + 1))
	{
		if (backtracking(pieces, s_grid, npieces, 0) == 1)
			return ;
	}
}
