/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_additional.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:43:17 by crice             #+#    #+#             */
/*   Updated: 2019/01/25 16:43:18 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_get_pos(int *x, int *y, char **figure)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*x = 0;
	*y = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (figure[i][j] == '#')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	jesus(int *x, int *y)
{
	*x = -1;
	*y = 0;
}

int		ft_square(char *buf)
{
	int i;
	int n;
	int sqrt;

	sqrt = 0;
	n = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			n++;
		i++;
	}
	while (sqrt < n)
	{
		if (sqrt * sqrt >= n)
			return (sqrt);
		else
			sqrt++;
	}
	return (sqrt);
}

void	ft_usage(void)
{
	char *s;

	s = "usage: ./fillit target_file\n";
	ft_putstr(s);
	exit(1);
}

int		ft_additional_check(char *buf)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (buf[i] != '\0')
	{
		n++;
		if (buf[i] == '\n')
		{
			if (n != 5)
				return (0);
			else
				n = 0;
		}
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			n = 0;
			i++;
		}
		i++;
	}
	return (1);
}
