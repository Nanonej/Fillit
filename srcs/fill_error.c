/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchim <lchim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:49:58 by lchim             #+#    #+#             */
/*   Updated: 2016/11/22 10:06:03 by lchim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fill_error(int index)
{
	if (index == 0)
		ft_putstr_fd("Memory allocation failed\n", 2);
	else if (index == 1)
		ft_putstr_fd("open() error\n", 2);
	else if (index == 2)
		ft_putstr_fd("close() error\n", 2);
	else if (index == 3)
		ft_putstr_fd("error\n", 2);
	exit(EXIT_FAILURE);
}
