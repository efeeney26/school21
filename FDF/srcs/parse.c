/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:43:48 by crice             #+#    #+#             */
/*   Updated: 2019/06/30 15:43:49 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	size_of_height(char *file, t_fdf *fdf)
{
	char		*line;
	int			fd;
	int			flag;

	flag = 0;
	!(fd = open(file, O_RDONLY)) ? ft_putendl("read error") : ft_putendl("file not found");
	while ((get_next_line(fd, &line) > 0))
	{
		if (flag == 0)
		{
			fdf->width = count_width(line, ' ');
			flag = 1;
		}
		if (fdf->width != count_width(line, ' '))
		{
			ft_putendl("not valid");
			free(line);
			close(fd);
			exit(0);
		}
		free(line);
		fdf->height++;
	}
	close(fd);
}

static	char	**str_data_to_arr(char *file, t_fdf *fdf)
{
	char		**lines;
	int			fd;
	int			i;

	display_error(!(lines = (char **)ft_memalloc(sizeof(char *)
					* (fdf->height + 1))), "ME");
	display_error(!(fd = open(file, O_RDONLY)), "invalid fd");
	i = 0;
	while ((get_next_line(fd, &lines[i]) > 0))
		i++;
	close(fd);
	return (lines);
}

static	void	allocate(t_fdf *fdf)
{
	int			i;

	i = 0;
	display_error(!(fdf->values_x = (double **)ft_memalloc(sizeof(double *)
					* fdf->height)), "ME");
	display_error(!(fdf->values_y = (double **)ft_memalloc(sizeof(double *)
					* fdf->height)), "ME");
	display_error(!(fdf->values_z = (double **)ft_memalloc(sizeof(double *)
					* fdf->height)), "ME");
	display_error(!(fdf->default_z = (double **)ft_memalloc(sizeof(double *)
					* fdf->height)), "ME");
	while (i < fdf->height)
	{
		display_error(!(fdf->values_x[i] = (double *)ft_memalloc(sizeof(double)
						* fdf->width)), "ME");
		display_error(!(fdf->values_y[i] = (double *)ft_memalloc(sizeof(double)
						* fdf->width)), "ME");
		display_error(!(fdf->values_z[i] = (double *)ft_memalloc(sizeof(double)
						* fdf->width)), "ME");
		display_error(!(fdf->default_z[i] = (double *)ft_memalloc(sizeof(double)
						* fdf->width)), "ME");
		i++;
	}
	fdf->step = 42;
}

static	void	fill_matrix_and_free(t_fdf *fdf,
		char ***no_space, char **space)
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
			fdf->default_z[i][j] = fdf->values_z[i][j];
			fdf->values_x[i][j] = j * fdf->step;
			fdf->values_y[i][j] = i * fdf->step;
			j++;
		}
		i++;
	}
	fresh_mem(no_space, space);
}

void			parse(char *file, t_fdf *fdf)
{
	char		**lines;
	char		***no_space_lines;
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	size_of_height(file, fdf);
	lines = str_data_to_arr(file, fdf);
	display_error(!(no_space_lines = (char ***)ft_memalloc(sizeof(char **)
					* (fdf->height + 1))), "ME");
	allocate(fdf);
	while (i < fdf->height)
	{
		no_space_lines[i] = ft_strsplit(lines[i], ' ');
		j = -1;
		while (no_space_lines[i][++j])
			fdf->values_z[i][j] = (double)(ft_atoi(no_space_lines[i][j])
					* fdf->step);
		i++;
	}
	fill_matrix_and_free(fdf, no_space_lines, lines);
}
