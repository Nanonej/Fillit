/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:45:10 by lchim             #+#    #+#             */
/*   Updated: 2016/11/25 12:24:42 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			fill_error(1);
		fill_start(fd);
		close(fd);
	}
	else
	{
		ft_putstr_fd("usage: ./fillit fillit_file\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
