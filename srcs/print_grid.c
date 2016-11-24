/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:37:33 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/25 00:04:24 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_grid(t_list *s_grid, int *trigger)
{
	char	*tmp;
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	tmp = ft_strnew((s_grid->size_grid + 1) * s_grid->size_grid);
	while (y < s_grid->size_grid)
	{
		x = 0;
		while (x < s_grid->size_grid)
		{
			if (s_grid->grid[y][x] == 0)
				tmp[i++] = '.';
			else if (s_grid->grid[y][x] >= 1)
				tmp[i++] = s_grid->grid[y][x] + 64;
			x++;
		}
		tmp[i++] = '\n';
		y++;
	}
	tmp[i] = '\0';
	ft_putstr_fd(tmp, 1);
	*trigger = 1;
	return (1);
}
