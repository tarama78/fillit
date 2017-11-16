/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:36:17 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/16 11:40:55 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serge.h>

int				main(int ac, char **av)
{
	char		*file_content;
	int			ret;

	ret = ft_verif(ac, av, &file_content);
	if (ret == FAILURE)
		return (EXIT_FAILURE);
	else if (ret == FAILURE_MSG)
	{
		ft_putstr("error\n");
		return (EXIT_FAILURE);
	}
	ft_fillit(file_content);
	return (EXIT_SUCCESS);
}
