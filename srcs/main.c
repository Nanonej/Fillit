/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:45:10 by lchim             #+#    #+#             */
/*   Updated: 2016/11/16 22:26:23 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			fill_error(1);
		fill_read_tetris(fd);
		if (close(fd) == -1)
			fill_error(2);
	}
	else
	{
		ft_putstr_fd("usage: ./fillit file_fillit\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
