/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:13:41 by crice             #+#    #+#             */
/*   Updated: 2019/02/01 16:13:43 by crice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_mem_th(char ***arr, char *buf)
{
	int i;
	int j;

	i = CFI;
	while (i >= 0)
	{
		j = 3;
		while (j >= 0)
		{
			free(arr[i][j]);
			j--;
		}
		i--;
	}
	i = CFI;
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}

void	free_mem_tw(char **arr)
{
	int i;

	i = al(arr);
	i--;
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}
