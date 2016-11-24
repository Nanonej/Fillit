/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:56:16 by lchim             #+#    #+#             */
/*   Updated: 2016/11/24 14:31:08 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void		ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

char		*ft_strnew(size_t size)
{
	char *new;

	if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		fill_error(0);
	return (new);
}

int			ascii_of_tetriminos(int **piece)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] != 0)
				return (piece[i][j]);
			j++;
		}
		i++;
	}
	return (-1);
}
