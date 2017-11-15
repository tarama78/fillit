/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_annexe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:58:00 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/15 18:48:00 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serge.h>

int			ft_verif_char(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (FAILURE);
		str++;
	}
	return (SUCCESS);
}

int			ft_verif_nb(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < 20)
	{
		if (str[i] == '#')
			count++;
	}
	if (count != 4)
		return (FAILURE);
	return (SUCCESS);
}

int			ft_verif_form(char *str, int x, int y)
{
	int jnct;

	jnct = 0;
	if (y < 3 && str[x * 5 + y + 1] == '#')
		jnct++;
	if (y > 0 && str[x * 5 + y - 1] == '#')
		jnct++;
	if (x < 3 && str[(x + 1) * 5 + y] == '#')
		jnct++;
	if (x > 0 && str[(x - 1) * 5 + y] == '#')
		jnct++;
	return (jnct);
}

int			ft_verif_tetris(char *str)
{
	int		i;
	int		j;
	int		jnct;

	jnct = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (str[i * 5 + j] == '#')
				jnct += ft_verif_form(str, i, j);
		}
	}
	if (jnct == 6 || jnct == 8)
		return (SUCCESS);
	return (FAILURE);
}

int			ft_verif_format(char *str)
{
	int		i;
	int		j;

	while (*str)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (*str++ != '.' && *(str - 1) != '#' && *(str - 1) != '\0')
					return (FAILURE);
			if (*str++ != '\n' && *str != '\0')
				return (FAILURE);
		}
		if (ft_verif_nb(str - 20) == FAILURE)
			return (FAILURE);
		if (ft_verif_tetris(str - 20) == FAILURE)
			return (FAILURE);
		if (*str == '\0')
			return (SUCCESS);
		else if (*str++ != '\n')
			return (FAILURE);
	}
	return (FAILURE);
}
