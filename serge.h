/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serge.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:16:38 by tnicolas          #+#    #+#             */
/*   Updated: 2017/11/16 17:57:51 by tnicolas         ###   ########.fr       */
/*                                                                            */
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
# include <stdio.h>/////////////////////////////////////////////////////////////

# define NORMAL	"\x1B[0m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

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
int			ft_int_sqrt(int n);
int			ft_size_min_square(t_tetris **t);
int			ft_init_tab(int **tab, int size);
void		ft_reset(t_tetris **t, int *count);
int			ft_int_sqrt(int n);
int			ft_is_possible(t_tetris **t, int *tab, int count, int size);
int			ft_put_top_left(t_tetris **t, int *tab, int count, int size);
void		ft_print(int *tab, int size);
void		ft_resolve(t_tetris **t);

#endif
