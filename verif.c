/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:49:10 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/13 19:33:19 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <serge.h>

int			ft_verif_args(int ac)
{
	if (ac == 2)
		return (SUCCESS);
	ft_putstr("explication");//
	return (FAILURE);
}

int			ft_readfile(char *filename, char **file_content)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (FAILURE);
	if (!(*file_content = malloc(sizeof(**file_content))))
		return (FAILURE);
	(*file_content)[0] = '\0';
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		ft_realloc(*file_content, ft_strlen(*file_content),
				ft_strlen(*file_content) + ft_strlen(buf) + 1);
		ft_strncat(*file_content, buf, ft_strlen(buf));
	}
	return (SUCCESS);	
}

int			ft_verif(int ac, char **av, char **file_content)
{
	if (ft_verif_args(ac) == FAILURE)
		return (FAILURE);
	if (ft_readfile(av[1], file_content) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
