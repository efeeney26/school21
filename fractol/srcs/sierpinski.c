/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:37:35 by efeeney           #+#    #+#             */
/*   Updated: 2019/08/03 16:37:41 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double		norme_helper(t_screen *screen)
{
	double			dim;
	int				i;

	dim = fabs(1 * screen->scale);
	i = 0;
	while (i < screen->iteration && dim <= HEIGHT)
	{
		dim *= 3;
		i++;
	}
	return (dim);
}

void				sierpinski(t_screen *screen)
{
	int				i;
	int				j;
	int				d;
	double			dim;

	i = 0;
	j = 0;
	dim = norme_helper(screen);
	while (i < HEIGHT && i <= dim)
	{
		j = 0;
		while (j < WIDTH && j <= dim)
		{
			d = round(dim) / 3;
			while (d)
			{
				if ((i % (d * 3) / d == 1) && (j % ((d * 3)) / d == 1))
					set_pixel(screen, i, j, set_color(screen, d));
				d /= 3;
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
