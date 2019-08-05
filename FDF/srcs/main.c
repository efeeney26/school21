/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:43:32 by crice             #+#    #+#             */
/*   Updated: 2019/06/30 15:43:32 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		change_scale(t_fdf *fdf, int flag)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (flag == -1)
				multiply_to_fdf(fdf, flag, i, j);
			if (flag == 1)
				multiply_to_fdf(fdf, flag, i, j);
			j++;
		}
		i++;
	}
}

void		multiply_to_fdf(t_fdf *fdf, int flag, int i, int j)
{
	if (flag == -1)
	{
		fdf->values_x[i][j] *= 1.2;
		fdf->values_y[i][j] *= 1.2;
		fdf->values_z[i][j] *= 1.2;
	}
	else
	{
		fdf->values_x[i][j] /= 1.2;
		fdf->values_y[i][j] /= 1.2;
		fdf->values_z[i][j] /= 1.2;
	}
}

void		fresh_mem(char ***str1, char **str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		j = 0;
		while (str1[i][j] || str2[j])
		{
			ft_strdel(&str1[i][j]);
			ft_strdel(&str2[j]);
		}
		free(str1[i]);
		i++;
	}
	free(str1);
	free(str2);
}

void		display_error(int cond, char *str)
{
	if (cond)
	{
		ft_putendl(str);
		exit(0);
	}
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	errno = 0;
	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (argc == 2)
	{
		parse(argv[1], fdf);
		init(fdf);
		draw_map(fdf);
		mlx_hook(fdf->win, 2, 0, key_press, fdf);
		mlx_loop(fdf->mlx);
		return (0);
	}
	else
	{
		ft_putendl("Usage: ./fdf MAP_FILE");
	}
}
