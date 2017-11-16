/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:29:43 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/16 14:30:56 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serge.h>

int			ft_is_possible(t_tetris **t, int *tab, int count, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((j + (t[count])->y >= size && (t[count])->form[i][j] == 1) ||
					((t[count])->form[i][j] == 1 &&
					tab[((t[count])->x + i) * size + (t[count])->y + j] != -1))
				return (FAILURE);
		}
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (t[count]->form[i][j] == 1)
				tab[((t[count])->x + i) * size + (t[count])->y + j] = count;
	}
	return (SUCCESS);
}

int			ft_put_top_left(t_tetris **t, int *tab, int count, int size)
{
	int		i;
	int		j;
	int		last_x;

	last_x = (t[count])->x;
	i = (last_x == -1) ? -1 : last_x - 1;
	while (++i < size)
	{
		j = (i == last_x) ? (t[count])->y - 1 : -1;
		while (++j < size)
		{
			(t[count])->x = i;
			(t[count])->y = j;
			if (ft_is_possible(t, tab, count, size) == SUCCESS)
				return (SUCCESS);
		}
	}
	(t[count])->x = -1;
	(t[count])->y = -1;
	return (FAILURE);
}

void		ft_print(int *tab, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tab[i * size + j] == -1)
				ft_putchar('.');
			else
			{
				printf("\x1b[%dm%c"NORMAL, tab[i * size + j] % 6 + 31,
						tab[i * size + j] + 'A');///////////////////////////////
				fflush(stdout);/////////////////////////////////////////////////
				//ft_putchar(tab[i * size + j] + 'A');
			}
		}
		ft_putchar('\n');
	}
}

void		ft_rekt_form(t_tetris **t, int *tab, int count, int size)
{
	int		i;
	int		sq;

	if (count < 0)
		return ;
	i = -1;
	sq = size * size;
	while (++i < sq)
	{
		if (tab[i] == count)
			tab[i] = -1;
	}
	if ((t[count])->y == size - 1)
	{
		(t[count])->x++;
		(t[count])->y = 0;
	}
	else
		(t[count])->y++;
}

void		ft_resolve(t_tetris **t)
{
	int		size;
	int		*tab;
	int		count;

	tab = NULL;
	count = 0;
	size = ft_size_min_square(t);
	while (count < (t[0])->nb_form)
	{
		ft_reset(t, &count);
		if (ft_init_tab(&tab, size) == FAILURE)
			return ;
		while (count < (t[0])->nb_form)
		{
			if (ft_put_top_left(t, tab, count, size) == SUCCESS)
				count++;
			else
				ft_rekt_form(t, tab, --count, size);
			if (count < 0 && size++)
				break ;
		}
	}
	ft_print(tab, size);
}
