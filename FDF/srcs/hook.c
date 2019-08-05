/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:42:44 by crice             #+#    #+#             */
/*   Updated: 2019/06/30 15:42:45 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		increase(t_fdf *fdf, int flag)
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
			if (flag == 1)
				fdf->values_x[i][j] += fdf->step;
			if (flag == -1)
				fdf->values_x[i][j] -= fdf->step;
			if (flag == 2)
				fdf->values_y[i][j] += fdf->step;
			if (flag == -2)
				fdf->values_y[i][j] -= fdf->step;
			j++;
		}
		i++;
	}
}

static	void	pulse(t_fdf *fdf)
{
	if (fdf->color + 16 > 0xFFFFFF)
		fdf->color = 14;
	else
		fdf->color += 14;
}

static void		color_changer(t_fdf *fdf)
{
	if (fdf->color == 0xFFFFFF)
		fdf->color = 0xFF0000;
	else if (fdf->color == 0xFF0000)
		fdf->color = 0x00FF00;
	else if (fdf->color == 0x00FF00)
		fdf->color = 0x0000FF;
	else if (fdf->color == 0x0000FF || fdf->color != 0xFFFFFF)
		fdf->color = 0xFFFFFF;
}

int				key_press(int key, t_fdf *fdf)
{
	key == 53 ? exit(0) : 0;
	key == 24 ? change_scale(fdf, -1) : 0;
	key == 12 ? z_rotation(fdf, -0.0523599) : 0;
	key == 14 ? z_rotation(fdf, 0.0523599) : 0;
	key == 27 ? change_scale(fdf, 1) : 0;
	key == 123 ? y_rotation(fdf, -0.0523599) : 0;
	key == 124 ? y_rotation(fdf, 0.0523599) : 0;
	key == 126 ? x_rotation(fdf, -0.0523599) : 0;
	key == 125 ? x_rotation(fdf, 0.0523599) : 0;
	key == 13 ? increase(fdf, -2) : 0;
	key == 1 ? increase(fdf, 2) : 0;
	key == 2 ? increase(fdf, 1) : 0;
	key == 0 ? increase(fdf, -1) : 0;
	key == 31 ? pulse(fdf) : 0;
	key == 48 ? color_changer(fdf) : 0;
	key_press2(key, fdf);
	draw_map(fdf);
	return (0);
}

int				key_press2(int key, t_fdf *fdf)
{
	if (key == 18 && fdf->projection != 1)
	{
		fdf->projection = 1;
		iso(fdf);
	}
	if (key == 19 && fdf->projection != 0)
	{
		fdf->projection = 0;
		parallel(fdf);
	}
	return (0);
}
