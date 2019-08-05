/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:20:31 by crice             #+#    #+#             */
/*   Updated: 2019/01/25 18:20:32 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# define CFI count_figures_in(buf, 0, 0, 0)
# define BUFF_SIZE 550

int		count_figures_in(char *buf, int i, int n, int t);
void	ft_double_minus(int *x, int *y, int *j, int *i);
int		count_figures_out(char **arr);
void	ft_four_to_zero(int *a, int *b, int *c, int *d);
void	ft_three_to_zero(int *a, int *b, int *c);
void	ft_next_line_of_array(int *i, int *j);
char	***set_arrfigure(char *buf, int i, int j, int k);
char	**set_resultarr(int size);
void	ft_get_pos(int *x, int *y, char **figure);
char	**ft_placer(char **arr, int *array, char **figure, int number);
char	**ft_remover(char **arr, int *a, int *b, int i);
int		ft_place_checker(char **arr, int a, int b, char **figure);
char	**gt(char ***arr, int i);
void	ft_putchar(char c);
void	pa(char **dest, char *buf);
char	**shortcut(char **dest, int *x, int *y, int *i);
void	solver(char *buf, char ***arr, int i, int y);
int		ft_check_friends(char **figure, int y, int x);
int		check_input(char **figure);
int		last_checker(char *buf);
int		check_all(char ***arrfigure, char *buf);
int		check_figures(char ***arrfigure, char *buf);
int		al(char **arr);
void	ft_plus_zero(int *y, int *b, int a);
void	ft_putstr(char *s);
int		*array(int a, int b);
void	jesus(int *x, int *y);
int		ft_square(char *buf);
void	ft_usage(void);
int		ft_additional_check(char *buf);
void	free_mem_th(char ***arr, char *buf);
void	free_mem_tw(char **arr);

#endif
