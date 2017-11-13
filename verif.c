/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 verif.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: tnicolas <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/11/13 18:49:10 by tnicolas		   #+#	  #+#			  */
/*	 Updated: 2017/11/13 21:52:05 by tnicolas		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft/libft.h"
#include <serge.h>

int			ft_verif_args(int ac)
{
	if (ac == 2)
		return (SUCCESS);
	ft_putstr("explication\n");//
	return (FAILURE);
}

int			ft_read_file(char *filename, char **file_content)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret_read;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (FAILURE);
	if (!(*file_content = malloc(sizeof(**file_content))))
		return (FAILURE);
	(*file_content)[0] = '\0';
	while ((ret_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret_read] = '\0';
		*file_content = ft_realloc(*file_content, ft_strlen(*file_content) + 1,
				ft_strlen(*file_content) + ret_read + 1);
		ft_strncat(*file_content, buf, ret_read);
	}
	return (SUCCESS);
}

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

int			ft_verif_tetris(char *str)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
		}
	}
	return (SUCCESS);
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
		if (ft_verif_nb(str - 21))
			return (FAILURE);
		//if (ft_verif_tetris(str - 19))
		//	return (FAILURE);
		if (*str == '\0')
			return (SUCCESS);
		else if (*str++ != '\n')
			return (FAILURE);
	}
	return (FAILURE);
}

int			ft_verif_file(char *str)
{
	if (ft_verif_char(str) == FAILURE)
		return (FAILURE);
	if (ft_verif_format(str) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int			ft_verif(int ac, char **av, char **file_content)
{
	if (ft_verif_args(ac) == FAILURE)
		return (FAILURE);
	if (ft_read_file(av[1], file_content) == FAILURE)
		return (FAILURE_MSG);
	if (ft_verif_file(*file_content) == FAILURE)
		return (FAILURE_MSG);
	return (SUCCESS);
}
