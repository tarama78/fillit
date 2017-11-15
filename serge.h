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
#include <stdio.h>//////////////////////////////////////////////////////////////

# define SUCCESS 0
# define FAILURE 1
# define FAILURE_MSG 2
# define BUFF_SIZE 4
# define SIZE_MAX_FILE 545

int			ft_verif_char(char *str);
int			ft_verif_nb(char *str);
int			ft_verif_form(char *str, int x, int y);
int			ft_verif_tetris(char *str);
int			ft_verif_format(char *str);
int			ft_verif_args(int ac);
int			ft_read_file(char *filename, char **file_content);
int			ft_verif_file(char *str);
int			ft_verif(int ac, char **av, char **file_content);
int			ft_verif(int ac, char **av, char **file_content);
int			ft_count_form(char *str);
void		ft_left_one(t_tetris *t);
void		ft_up_one(t_tetris *t);
void		ft_form_top_left(t_tetris *t);
t_tetris	*ft_init_struct(char *str, int nb_form);
t_tetris	**ft_create_tetris(char *str);
void		ft_fruit(t_tetris **t);
void		ft_fillit(char *str);
void		ft_resolve(t_tetris **t);

#endif
