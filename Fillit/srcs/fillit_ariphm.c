/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_ariphm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:25:53 by crice             #+#    #+#             */
/*   Updated: 2019/01/25 15:25:54 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_four_to_zero(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

void	ft_three_to_zero(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

void	ft_next_line_of_array(int *i, int *j)
{
	*i = *i + 1;
	*j = 0;
}

void	ft_double_minus(int *x, int *y, int *j, int *i)
{
	*x = *j - *x;
	*y = *i - *y;
}

void	ft_plus_zero(int *y, int *b, int a)
{
	*y += a;
	*b = 0;
}
