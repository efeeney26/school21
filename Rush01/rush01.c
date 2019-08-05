/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 18:28:10 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/09/30 19:04:50 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

int generation(int **m, int i, int j);
int g_count;
int g_success_count;
int **g_save;

int		check(int i, int j, int num, int **m)
{
	int k;
	int count_num;
	int s;

	k = 0;
	count_num = 0;
	while (k < 9)
	{
		if (m[i][k] == num)
			count_num++;
		if (m[k++][j] == num)
			count_num++;
	}
	k = FIRST(i);
	while (k < SECOND(i))
	{
		s = FIRST(j);
		while (s < SECOND(j))
			if (m[k][s++] == num)
				count_num++;
		k++;
	}
	if (count_num == 3)
		return (1);
	return (0);
}

int		set_number(int **m, int i, int j)
{
	int number;

	number = 1;
	while (number <= 9)
	{
		m[i][j] = number;
		if (check(i, j, number, m))
		{
			g_count++;
			if (!generation(m, 0, 0))
			{
				m[i][j] = 0;
				g_count--;
			}
			else
				return (0);
		}
		else
			m[i][j] = 0;
		number++;
	}
	return (0);
}

int		generation(int **m, int i, int j)
{
	i = 0;
	if (g_count == 81)
	{
		g_save = set_mass_int(m);
		g_success_count++;
		return (0);
	}
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (m[i][j] == 0)
			{
				if (set_number(m, i, j))
					return (1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int **m;

	m = 0;
	g_save = 0;
	g_success_count = 0;
	if (argc == 10)
	{
		m = set_mass(argv);
		if (m)
		{
			g_count = count_elems(m);
			generation(m, 0, 0);
		}
	}
	if (g_success_count == 1 && argc == 10 && m && g_save)
	{
		out(g_save);
	}
	else
		write(1, "ERROR\n", 6);
	if (m)
		destroy(m);
	if (g_save)
		destroy(g_save);
	return (0);
}
