/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:42:11 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/16 14:54:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serge.h>

int			ft_verif_args(int ac)
{
	if (ac == 2)
		return (SUCCESS);
	ft_putstr("usage: fillit filename\n");
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
		exit(EXIT_FAILURE);
	(*file_content)[0] = '\0';
	while ((ret_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret_read] = '\0';
		*file_content = ft_realloc(*file_content, ft_strlen(*file_content) + 1,
				ft_strlen(*file_content) + ret_read + 1);
		ft_strncat(*file_content, buf, ret_read);
	}
	close(fd);
	return (SUCCESS);
}

int			ft_verif_file(char *str)
{
	if (ft_strlen(str) > SIZE_MAX_FILE)
		return (FAILURE);
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
