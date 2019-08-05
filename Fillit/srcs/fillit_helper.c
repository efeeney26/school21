/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:25:07 by crice             #+#    #+#             */
/*   Updated: 2019/01/25 15:25:08 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	pa(char **dest, char *buf)
{
	int i;
	int j;

	i = 0;
	while (i < al(dest))
	{
		j = 0;
		while (j < al(dest))
		{
			ft_putchar(dest[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	i = 0;
	while (buf[i] != '\0')
	{
		buf[i] = '\0';
		i++;
	}
	free_mem_tw(dest);
	exit(0);
}

char	**shortcut(char **dest, int *x, int *y, int *i)
{
	int		n;
	char	**new;
	int		l;

	l = 0;
	n = al(dest);
	while (l < n)
		free(dest[l++]);
	free(dest);
	*x = 0;
	*y = 0;
	*i = 0;
	new = set_resultarr(n + 1);
	return (new);
}

int		al(char **arr)
{
	int j;

	j = 0;
	while (arr[0][j] != '\0')
		j++;
	return (j);
}

int		ft_place_checker(char **arr, int a, int b, char **figure)
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
				if (!(a + y <= al(arr) && b + x <= al(arr)))
					return (0);
				else if (((a + y) < 0 || (b + x < 0) || (a + y) > (al(arr) - 1)
					|| (b + x > (al(arr) - 1))) || (arr[a + y][b + x] != '.'))
					return (0);
			}
			j++;
		}
		ft_next_line_of_array(&i, &j);
	}
	return (1);
}
