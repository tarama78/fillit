/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serge.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:51:19 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/13 19:33:37 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERGE_H
# define SERGE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define SUCCESS 1
# define FAILURE 0
# define BUFF_SIZE 2048

int			ft_verif_args(int ac);
int			ft_readfile(char *filename, char **file_content);
int			ft_verif(int ac, char **av, char **file_content);

#endif
