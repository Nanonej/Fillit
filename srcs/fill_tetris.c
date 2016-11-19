/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:45:18 by lchim             #+#    #+#             */
/*   Updated: 2016/11/19 10:48:59 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		fill_read_tetris(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	if ((ret = read(fd, buff, BUFF_SIZE)) == 0)
		return ;
	// return char * = NULL
	buff[ret] = '\0';
	fill_tetris_error(buff);
	ft_putstr_fd(buff, 1);
}
