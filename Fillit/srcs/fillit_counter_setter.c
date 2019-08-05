/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_counter_setter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:25:42 by crice             #+#    #+#             */
/*   Updated: 2019/01/25 15:25:42 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***set_arrfigure(char *buf, int i, int j, int k)
{
	char	***arrfigure;
	int		m;

	ft_four_to_zero(&i, &m, &j, &k);
	arrfigure = (char ***)malloc(sizeof(char **) * CFI);
	(!arrfigure) ? exit(1) : arrfigure;
	while (i < CFI)
	{
		arrfigure[i] = (char **)malloc(sizeof(char *) * 4);
		(!arrfigure[i]) ? free_mem_th(arrfigure, buf) : arrfigure[i];
		while (j < 4)
		{
			arrfigure[i][j] = (char *)malloc(sizeof(char) * 4);
			(!arrfigure[i][j]) ? free_mem_th(arrfigure, buf) : arrfigure[i][j];
			while (k < 4)
			{
				if (buf[m++] != '\n')
					arrfigure[i][j][k++] = buf[m - 1];
			}
			ft_next_line_of_array(&j, &k);
		}
		ft_next_line_of_array(&i, &j);
	}
	return (arrfigure);
}

char	**set_resultarr(int size)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * size);
	(!arr) ? exit(1) : arr;
	while (i < size)
	{
		arr[i] = (char *)malloc(sizeof(char) * size + 1);
		(!arr[i]) ? free_mem_tw(arr) : arr[i];
		j = 0;
		while (j < size)
		{
			arr[i][j] = '.';
			j++;
		}
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}

int		count_figures_in(char *buf, int i, int n, int t)
{
	int count_sharps;
	int count_in;

	count_sharps = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			count_sharps++;
		else if (buf[i] == '\n')
			n++;
		else if (buf[i] == '.')
			t++;
		else
			t = -100;
		i++;
	}
	count_in = count_sharps / 4;
	if (n != count_in * 5 - 1 || t != count_in * 12 || count_in > 26)
		return (0);
	return (count_in);
}

int		count_figures_out(char **arr)
{
	int i;
	int j;
	int count_sharps;
	int count_out;

	i = 0;
	count_sharps = 0;
	while (i < al(arr) - 1)
	{
		j = 0;
		while (j < al(arr) - 1)
		{
			if (arr[i][j] == '#')
				count_sharps++;
			j++;
		}
		i++;
	}
	count_out = count_sharps / 4;
	return (count_out);
}

char	**gt(char ***arr, int i)
{
	int		j;
	int		k;
	char	**tetrino;

	tetrino = (char **)malloc(sizeof(char *) * 4);
	(!tetrino) ? exit(1) : tetrino;
	j = 0;
	while (j < 4)
	{
		tetrino[j] = (char *)malloc(sizeof(char) * 4);
		(!tetrino[j]) ? free_mem_tw(tetrino) : tetrino[j];
		k = 0;
		while (k < 4)
		{
			tetrino[j][k] = arr[i][j][k];
			k++;
		}
		j++;
	}
	return (tetrino);
}
