/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_annexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:42:51 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/16 14:42:54 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serge.h>

int			ft_count_form(char *str)
{
	int		count;

	count = 1;
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
			count++;
		str++;
	}
	return (count);
}

void		ft_left_one(t_tetris *t)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			t->form[i][j] = t->form[i][j + 1];
	}
	i = -1;
	while (++i < 4)
		t->form[i][3] = 0;
}

void		ft_up_one(t_tetris *t)
{
	int i;
	int j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 4)
			t->form[i][j] = t->form[i + 1][j];
	}
	j = -1;
	while (++j < 4)
		t->form[3][j] = 0;
}

t_tetris	*ft_init_struct(char *str, int nb_form)
{
	t_tetris	*t;
	int			i;
	int			j;

	if (!(t = (t_tetris*)malloc(sizeof(*t))))
		return (NULL);
	t->nb_form = nb_form;
	t->x = -1;
	t->y = -1;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (str[i * 5 + j] == '.')
				t->form[i][j] = 0;
			else if (str[i * 5 + j] == '#')
				t->form[i][j] = 1;
		}
	}
	ft_form_top_left(t);
	return (t);
}
