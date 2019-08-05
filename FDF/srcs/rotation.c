/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:43:59 by crice             #+#    #+#             */
/*   Updated: 2019/06/30 15:44:00 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		x_rotation(t_fdf *fdf, double angle)
{
	int		i;
	int		j;
	double	cache_y;

	i = 0;
	j = 0;
	cache_y = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			cache_y = fdf->values_y[i][j];
			fdf->values_y[i][j] = cache_y * cos(angle)
				+ fdf->values_z[i][j] * sin(angle);
			fdf->values_z[i][j] = -cache_y * sin(angle)
				+ fdf->values_z[i][j] * cos(angle);
			j++;
		}
		i++;
	}
}

void		y_rotation(t_fdf *fdf, double angle)
{
	int		i;
	int		j;
	double	cache_x;

	i = 0;
	j = 0;
	cache_x = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			cache_x = fdf->values_x[i][j];
			fdf->values_x[i][j] = cache_x * cos(angle)
				+ fdf->values_z[i][j] * sin(angle);
			fdf->values_z[i][j] = -cache_x * sin(angle)
				+ fdf->values_z[i][j] * cos(angle);
			j++;
		}
		i++;
	}
}

void		z_rotation(t_fdf *fdf, double angle)
{
	int		i;
	int		j;
	double	cache_x;
	double	cache_y;

	i = 0;
	j = 0;
	cache_x = 0;
	cache_y = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			cache_x = fdf->values_x[i][j];
			cache_y = fdf->values_y[i][j];
			fdf->values_x[i][j] = cache_x * cos(angle)
				- cache_y * sin(angle);
			fdf->values_y[i][j] = cache_x * sin(angle)
				+ cache_y * cos(angle);
			j++;
		}
		i++;
	}
}

void		iso(t_fdf *fdf)
{
	int		i;
	int		j;
	double	cache_y;
	double	cache_x;

	i = 0;
	j = 0;
	cache_y = 0;
	cache_x = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			cache_x = fdf->values_x[i][j];
			cache_y = fdf->values_y[i][j];
			fdf->values_x[i][j] = (cache_x - cache_y) * cos(0.523599);
			fdf->values_y[i][j] = -1.0 * fdf->default_z[i][j]
				+ (cache_x + cache_y) * sin(0.523599);
			j++;
		}
		i++;
	}
}

void		parallel(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->values_x[i][j] = j * fdf->step;
			fdf->values_z[i][j] = fdf->default_z[i][j];
			fdf->values_y[i][j] = i * fdf->step;
			j++;
		}
		i++;
	}
}
