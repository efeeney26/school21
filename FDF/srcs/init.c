/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:41:48 by crice             #+#    #+#             */
/*   Updated: 2019/06/30 15:41:52 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	fdf->centr_x = WIDTH / fdf->width * (fdf->width / 2);
	fdf->centr_y = HEIGHT / fdf->height * (fdf->height / 2);
	fdf->color = 0xFFFFFF;
	fdf->projection = 0;
	init_image(fdf);
}
