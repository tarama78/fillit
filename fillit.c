/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:42:36 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/16 14:42:37 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serge.h>

void		ft_form_top_left(t_tetris *t)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		if (t->form[i][0] == 1)
			break ;
	}
	if (i == 4)
		ft_left_one(t);
	j = -1;
	while (++j < 4)
	{
		if (t->form[0][j] == 1)
			break ;
	}
	if (j == 4)
		ft_up_one(t);
	if (i == 4 || j == 4)
		ft_form_top_left(t);
}

t_tetris	**ft_create_tetris(char *str)
{
	t_tetris	**t;
	int			nb_form;
	int			i;

	nb_form = ft_count_form(str);
	if (!(t = (t_tetris**)malloc(sizeof(*t) * nb_form)))
		return (NULL);
	i = -1;
	while (++i < nb_form)
	{
		if (!(t[i] = ft_init_struct(str + 21 * i, nb_form)))
			return (NULL);
	}
	return (t);
}

void		ft_fruit(t_tetris **t)
{
	int		i;
	int		nb_form;

	i = -1;
	nb_form = t[0]->nb_form;
	while (++i < nb_form)
		free(t[i]);
	free(t);
}

void		ft_fillit(char *str)
{
	t_tetris	**t;

	if (!(t = ft_create_tetris(str)))
		return ;
	ft_resolve(t);
	ft_fruit(t);
}
