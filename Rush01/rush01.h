/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:30:42 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/09/30 19:00:42 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>
# define FIRST(i) (i / 3) * 3
# define SECOND(i) (i / 3) * 3 + 3
# define FT_PUTCHAR(c) write(1, &c, 1)

int		**set_mass(char **argv)
{
	int i;
	int j;
	int **m;

	i = 0;
	m = (int **)malloc(sizeof(int *) * 9);
	while (i < 9)
	{
		m[i] = (int *)malloc(sizeof(int) * 9);
		j = 0;
		while (j < 9)
		{
			if (argv[i + 1][j] == '.')
				m[i][j] = 0;
			else
				m[i][j] = argv[i + 1][j] - 48;
			j++;
		}
		if (argv[i + 1][j] != '\0')
			return (0);
		i++;
	}
	return (m);
}

int		**set_mass_int(int **mass)
{
	int i;
	int j;
	int **m;

	i = 0;
	m = (int **)malloc(sizeof(int *) * 9);
	while (i < 9)
	{
		m[i] = (int *)malloc(sizeof(int) * 9);
		j = 0;
		while (j < 9)
		{
			m[i][j] = mass[i][j];
			j++;
		}
		i++;
	}
	return (m);
}

int		count_elems(int **m)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (m[i][j] != 0)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	out(int **m)
{
	int		i;
	int		j;
	char	c;
	char	p;
	char	q;

	i = 0;
	q = ' ';
	p = '\n';
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = m[i][j] + 48;
			write(1, &c, 1);
			if (j != 8)
				write(1, &q, 1);
			j++;
		}
		write(1, &p, 1);
		i++;
	}
}

void	destroy(int **m)
{
	int i;

	i = 0;
	while (i < 9)
	{
		free(m[i]);
		i++;
	}
	free(m);
}
#endif
