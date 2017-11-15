/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:20:54 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/15 18:50:22 by pmilan           ###   ########.fr       */
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

void		ft_form_top_left(t_tetris *t)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		if (t->form[i][0] == 1)
			break;
	}
	if (i == 4)
		ft_left_one(t);
	j = -1;
	while (++j < 4)
	{
		if (t->form[0][j] == 1)
			break;
	}
	if (j == 4)
		ft_up_one(t);
	if (i == 4 || j == 4)
		ft_form_top_left(t);
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
	//////////
/*
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			printf("%d ", t->form[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//////////////////
	*/
	return (t);
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
	int i;
	int nb_form;

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
