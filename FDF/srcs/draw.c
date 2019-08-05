/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:42:18 by crice             #+#    #+#             */
/*   Updated: 2019/06/30 15:42:20 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ui_draw(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 40, 105, fdf->color, " Zoom in    : +");
	mlx_string_put(fdf->mlx, fdf->win, 40, 130, fdf->color, " Zoom out   : -");
	mlx_string_put(fdf->mlx, fdf->win, 40,
			155, fdf->color, "      	 Move : W A S D");
	mlx_string_put(fdf->mlx, fdf->win, 2100, 105,
			fdf->color, " ISO : 1, Parallel : 2");
	mlx_string_put(fdf->mlx, fdf->win, 2100, 130,
			fdf->color, " ^ v : Rotation by X");
	mlx_string_put(fdf->mlx, fdf->win, 2100, 155,
			fdf->color, " Q E : Rotation by Y");
	mlx_string_put(fdf->mlx, fdf->win, 2100, 180,
			fdf->color, " > < : Rotation by Z");
	mlx_string_put(fdf->mlx, fdf->win, 40, 180,
			fdf->color, " Pulse mode : O");
	mlx_string_put(fdf->mlx, fdf->win, 40, 1095,
			fdf->color, "TAB : R G B");
}

static	void	dy_less(t_fdf *fdf, t_helper *help, t_point *point)
{
	int			i;
	double		x;
	double		y;

	i = 0;
	x = 0;
	y = 0;
	set_pixel(fdf, fdf->centr_x + point->x0,
			fdf->centr_y + point->y0, fdf->color);
	x = point->x0 + help->sx;
	y = point->y0;
	i = 0;
	while (i <= ABS(point->x0 - point->x1))
	{
		if (help->d > 0)
		{
			help->d += help->d2;
			y += help->sy;
		}
		else
			help->d += help->d1;
		set_pixel(fdf, fdf->centr_x + x, fdf->centr_y + y, fdf->color);
		x += help->sx;
		i++;
	}
}

static void		dx_less(t_fdf *fdf, t_helper *help, t_point *point)
{
	int			i;
	double		x;
	double		y;

	i = 0;
	x = 0;
	y = 0;
	set_pixel(fdf, fdf->centr_x + point->x0,
			fdf->centr_y + point->y0, fdf->color);
	x = point->x0;
	y = point->y0;
	while (i <= ABS(point->y0 - point->y1))
	{
		if (help->d > 0)
		{
			help->d += help->d2;
			x += help->sx;
		}
		else
			help->d += help->d1;
		set_pixel(fdf, fdf->centr_x + x, fdf->centr_y + y, fdf->color);
		y += help->sy;
		i++;
	}
}

void			line_draw(t_fdf *fdf, t_point *point)
{
	t_helper	help;

	help.d1 = 0;
	help.d2 = 0;
	help.sx = (point->x1 >= point->x0) ? 1 : -1;
	help.sy = (point->y1 >= point->y0) ? 1 : -1;
	if (ABS(point->y0 - point->y1) < ABS(point->x0 - point->x1))
	{
		help.d = ABS(point->y0 - point->y1) - ABS(point->x0 - point->x1);
		help.d1 = ABS(point->y0 - point->y1) * 2;
		help.d2 = (ABS(point->y0 - point->y1) - ABS(point->x0 - point->x1)) * 2;
		dy_less(fdf, &help, point);
	}
	else
	{
		help.d = ABS(point->x0 - point->x1) - ABS(point->y0 - point->y1);
		help.d1 = ABS(point->x0 - point->x1) * 2;
		help.d2 = (ABS(point->x0 - point->x1) - ABS(point->y0 - point->y1)) * 2;
		dx_less(fdf, &help, point);
	}
}

void			draw_map(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	clear_image(&fdf->img);
	while (i < fdf->height - 1)
	{
		j = 0;
		while (j < fdf->width - 1)
		{
			if (j != 0)
				line_draw(fdf, &((t_point){fdf->values_x[i][j - 1],
							fdf->values_x[i][j], fdf->values_y[i][j - 1],
							fdf->values_y[i][j]}));
			if (i != 0)
				line_draw(fdf, &((t_point){fdf->values_x[i - 1][j],
							fdf->values_x[i][j], fdf->values_y[i - 1][j],
							fdf->values_y[i][j]}));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.image, 0, 0);
	ui_draw(fdf);
}
