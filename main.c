/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:36:17 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/13 20:21:24 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <serge.h>

int				main(int ac, char **av)
{
	char		*file_content;
	if (ft_verif(ac, av, &file_content) == FAILURE)
		return (EXIT_FAILURE);
	ft_putstr(file_content);
	return (EXIT_SUCCESS);
}
