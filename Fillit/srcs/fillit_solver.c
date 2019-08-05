/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:25:18 by crice             #+#    #+#             */
/*   Updated: 2019/01/25 15:25:19 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	**ft_placer(char **arr, int *array, char **figure, int number)
{
	int x;
	int y;
	int i;
	int j;

	ft_four_to_zero(&i, &j, &x, &y);
	while (i < 4)
	{
		while (j < 4)
		{
			if (figure[i][j] == '#')
			{
				ft_get_pos(&x, &y, figure);
				ft_double_minus(&x, &y, &j, &i);
				arr[array[0] + y][array[1] + x] = 'A' + number;
			}
			j++;
		}
		ft_next_line_of_array(&i, &j);
	}
	return (arr);
}

char	**ft_remover(char **arr, int *y, int *b, int i)
{
	int		n;
	int		m;
	int		a;

	a = 0;
	n = al(arr) - 1;
	m = n;
	while (n > -1)
	{
		while (m > -1)
		{
			if (arr[n][m] == 'A' + i)
			{
				arr[n][m] = '.';
				a = n;
				*b = m + 1;
			}
			m--;
		}
		m = al(arr) - 1;
		n--;
	}
	(*b > al(arr)) ? (ft_plus_zero(&(*y), &(*b), a)) : (*y = a);
	return (arr);
}

int		*array(int a, int b)
{
	static int dest[2];

	dest[0] = a;
	dest[1] = b;
	return (dest);
}

void	solver(char *buf, char ***arr, int i, int x)
{
	char	**dest;
	int		y;

	dest = set_resultarr(ft_square(buf) - 1);
	dest = shortcut(dest, &x, &y, &i);
	while (i < CFI)
	{
		while (y < al(dest))
		{
			while (x++ < al(dest))
			{
				if (ft_place_checker(dest, y, x - 1, gt(arr, i)))
				{
					dest = ft_placer(dest, array(y, x - 1), gt(arr, i), i);
					(i++ + 1 < CFI) ? (jesus(&x, &y)) : (pa(dest, buf));
				}
			}
			ft_next_line_of_array(&y, &x);
		}
		if (CFI > count_figures_out(dest))
		{
			dest = ft_remover(dest, &y, &x, --i);
			(i < 0) ? (dest = shortcut(dest, &x, &y, &i)) : (dest);
		}
	}
}
