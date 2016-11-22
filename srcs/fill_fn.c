/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:56:16 by lchim             #+#    #+#             */
/*   Updated: 2016/11/22 10:11:47 by lchim            ###   ########.fr       */
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
