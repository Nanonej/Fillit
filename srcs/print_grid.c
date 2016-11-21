/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:37:33 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/21 15:17:33 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grid(int **grid, int size)
{
	char	*tmp;
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	if (!(tmp = ft_strnew((size + 1) * size)))
		fill_error(0);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (grid[y][x] == 0)
				tmp[i++] = '.';
			else (grid[y][x] >= 1)
				tmp[i++] = grid[y][x] + 64;
			x++;
		}
		tmp[i++] = '\n';
		y++;
	}
	tmp[i] = '\0';
	ft_putstr_fd(tmp, 1);
}
