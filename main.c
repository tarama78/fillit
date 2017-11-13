/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:36:17 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/13 19:33:09 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <serge.h>

int				main(int ac, char **av)
{
	char		*file_content;
	ft_verif(ac, av, &file_content);
	ft_putstr(file_content);
	return (0);
}
