/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:18:35 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/16 14:26:51 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serge.h>

int			ft_int_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

int			ft_size_min_square(t_tetris **t)
{
	int size;

	size = ft_int_sqrt(t[0]->nb_form * 4);
	if (size < 4)
		size = 4;
	return (size);
}

int			ft_init_tab(int **tab, int size)
{
	int i;

	free(*tab);
	i = size * size;
	if (!(*tab = (int *)malloc(sizeof(**tab) * i)))
		return (FAILURE);
	while (--i >= 0)
		(*tab)[i] = -1;
	return (SUCCESS);
}

void		ft_reset(t_tetris **t, int *count)
{
	int		i;

	i = -1;
	while (++i < (t[0])->nb_form)
	{
		(t[i])->x = -1;
		(t[i])->y = -1;
	}
	*count = 0;
}
