/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:26:06 by crice             #+#    #+#             */
/*   Updated: 2019/01/25 15:29:14 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char const *argv[])
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	***arrfigure;
	char	*s;

	s = "error\n";
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		close(fd);
		arrfigure = set_arrfigure(buf, 0, 0, 0);
		if (!check_all(arrfigure, buf))
			ft_putstr(s);
		else
			solver(buf, arrfigure, 0, 0);
	}
	else
		ft_usage();
	return (0);
}
