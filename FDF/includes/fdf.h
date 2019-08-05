/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:48:30 by efeeney           #+#    #+#             */
/*   Updated: 2019/06/30 15:48:51 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ABS(Value) (Value < 0 ? -(Value) : (Value))

# define WIDTH 2400
# define HEIGHT 1300
# define UNIQ_BPP 4

# include "libft.h"
# include "mlx.h"
# include "math.h"
# include <errno.h>

typedef	struct	s_helper
{
	double			d;
	double			d1;
	double			d2;
	double			sx;
	double			sy;
}				t_helper;

typedef	struct	s_point
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
}				t_point;

typedef	struct	s_img
{
	void				*image;
	char				*ptr;
	int					bpp;
	int					size_line;
	int					endian;
}				t_img;

typedef struct	s_fdf
{
	double			**values_x;
	double			**values_y;
	double			**values_z;
	double			**default_z;
	int				width;
	int				height;
	void			*mlx;
	void			*win;
	int				centr_x;
	int				centr_y;
	int				step;
	int				color;
	int				projection;
	t_img			img;
}				t_fdf;

void			change_scale(t_fdf *fdf, int flag);
void			multiply_to_fdf(t_fdf *fdf, int flag, int x, int y);
void			fresh_mem(char ***str1, char **str2);
void			display_error(int cond, char *str);

void			parse(char *file, t_fdf *fdf);
int				key_press(int key, t_fdf *fdf);
int				key_press2(int key, t_fdf *fdf);
int				mouse_move(int move, int x, int y, void *param);
void			ui_draw(t_fdf *fdf);
void			line_draw(t_fdf *fdf, t_point *point);
void			draw_map(t_fdf *fdf);

void			init(t_fdf *fdf);

void			x_rotation(t_fdf *fdf, double angle);
void			y_rotation(t_fdf *fdf, double angle);
void			z_rotation(t_fdf *fdf, double angle);
void			iso(t_fdf *fdf);
void			parallel(t_fdf *fdf);

void			init_image(t_fdf *fdf);
void			set_pixel(t_fdf	*fdf, int x, int y, int color);
void			clear_image(t_img	*img);
int				count_width(const char *str, char symbol);

#endif
