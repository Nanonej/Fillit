/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:37:33 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/20 09:40:39 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_fill(int *grid, int n)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_strnew(n - 1)))
		fill_error(0);
	while (n--)
	{
		if (*grid == 0)
			tmp[i] = *grid;
		else if (*grid >= 1)
			tmp[i] = *grid + 64;
		else if (*grid == -1)
			tmp[i] = '\n';
		else if (*grid == -2)
			tmp[i] = '\0';
		grid++;
		i++;
	}
	ft_putstr_fd(tmp, 1);
	free(grid);
	free(tmp);
}
/*
int		main(void)
{
	print_fill();
	return (0);
}
*/
