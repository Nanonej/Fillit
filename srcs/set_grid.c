/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:47:52 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/24 14:31:29 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_grid(t_list *s_grid)
{
	int y;
	int x;

	y = 0;
	while (y < s_grid->size_grid)
	{
		x = 0;
		while (x < s_grid->size_grid)
		{
			s_grid->grid[y][x] = 0;
			x++;
		}
		s_grid->grid[y][x] = -2;
		y++;
	}
}

void		set_grid(t_list *s_grid)
{
	int n;

	n = 0;
	if (!(s_grid->grid = (int**)malloc(sizeof(int*) * (s_grid->size_grid))))
		fill_error(0);
	while (n < s_grid->size_grid)
	{
		if (!(s_grid->grid[n] = (int*)malloc(sizeof(int) * \
											(s_grid->size_grid + 1))))
			fill_error(0);
		n++;
	}
	init_grid(s_grid);
}
