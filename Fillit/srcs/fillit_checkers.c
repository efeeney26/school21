/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:25:30 by crice             #+#    #+#             */
/*   Updated: 2019/01/25 15:25:31 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_figures(char ***arrfigure, char *buf)
{
	int		i;
	char	**figure;

	i = 0;
	while (i < CFI)
	{
		figure = gt(arrfigure, i);
		if (!check_input(figure))
			return (0);
		else
			i++;
	}
	return (1);
}

int		ft_check_friends(char **figure, int y, int x)
{
	int n;

	n = 0;
	if (x != 0 && figure[y][x - 1] == '#')
		n++;
	if (x != 3 && figure[y][x + 1] == '#')
		n++;
	if (y != 0 && figure[y - 1][x] == '#')
		n++;
	if (y != 3 && figure[y + 1][x] == '#')
		n++;
	return (n);
}

int		check_all(char ***arrfigure, char *buf)
{
	if (!check_figures(arrfigure, buf)
		|| !CFI || !last_checker(buf)
		|| !ft_additional_check(buf))
		return (0);
	else
		return (1);
}

int		last_checker(char *buf)
{
	int i;
	int t;
	int n;
	int sharp;

	ft_four_to_zero(&t, &n, &i, &sharp);
	while (buf[i] != '\0')
	{
		if (buf[i] == '.')
			t++;
		if (buf[i] == '#')
			sharp++;
		if (buf[i] == '\n')
			n++;
		if (n == 4)
		{
			n = 0;
			if (sharp != 4 || t != 12)
				return (0);
			ft_next_line_of_array(&i, &sharp);
			t = 0;
		}
		i++;
	}
	return (1);
}

int		check_input(char **figure)
{
	int		x;
	int		y;
	int		counter;
	int		con;

	ft_three_to_zero(&counter, &y, &x);
	while (y < 4)
	{
		while (x < 4)
		{
			con = ft_check_friends(figure, y, x);
			if (figure[y][x] == '#' && con == 0)
				return (0);
			if (figure[y][x] == '#')
				counter += con;
			x++;
		}
		ft_next_line_of_array(&y, &x);
	}
	if (counter < 6)
		return (0);
	return (1);
}
