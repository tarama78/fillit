/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serge.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:51:19 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/13 20:23:12 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERGE_H
# define SERGE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>//

# define SUCCESS 0
# define FAILURE 1
# define BUFF_SIZE 4 

int			ft_verif_args(int ac);
int			ft_readfile(char *filename, char **file_content);
int			ft_verif(int ac, char **av, char **file_content);

#endif
