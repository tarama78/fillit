/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 serge.h											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: tnicolas <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/11/13 17:51:19 by tnicolas		   #+#	  #+#			  */
/*	 Updated: 2017/11/14 19:36:49 by tnicolas		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef SERGE_H
# define SERGE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <structure.h>

# define SUCCESS 0
# define FAILURE 1
# define FAILURE_MSG 2
# define BUFF_SIZE 4
# define SIZE_MAX_FILE 545

int			ft_verif_char(char *str);
int			ft_verif_nb(char *str);
int			ft_verif_form(char *str, int x, int y, int check);
int			ft_verif_tetris(char *str);
int			ft_verif_format(char *str);
int			ft_verif_args(int ac);
int			ft_read_file(char *filename, char **file_content);
int			ft_verif_file(char *str);
int			ft_verif(int ac, char **av, char **file_content);
int			ft_verif(int ac, char **av, char **file_content);
void		ft_fillit(char *str);

#endif
