/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:43:01 by crice             #+#    #+#             */
/*   Updated: 2019/06/30 15:43:02 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_image(t_fdf *fdf)
{
	fdf->img.image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.ptr = mlx_get_data_addr(fdf->img.image, &fdf->img.bpp,
			&fdf->img.size_line, &fdf->img.endian);
	fdf->img.bpp /= 8;
}

void	set_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	((int*)(fdf->img.ptr))[y * WIDTH + x] = color;
}

void	clear_image(t_img *img)
{
	ft_bzero(img->ptr, WIDTH * HEIGHT * img->bpp);
}
