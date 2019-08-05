/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:15:40 by crice             #+#    #+#             */
/*   Updated: 2018/10/10 21:09:06 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_count_colomns(char *str);
int ft_count_rows (char *str);
int     **ft_print_square(char *str, int y, int x,int square);
int     ft_check_square(int **str, int y, int x);
void  ft_putchar(char c);

/*
void	ft_print_array(int **str)
{
	int i;
	int j;

	while (str[i][j])
	{
		while(str[i][j])
		{
			ft_putchar(str[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
*/


void	ft_solver(int **str, char *buffer)
{
	int square;
	int **dest;
	int i;
	int j;
	int block;

	block = 0;
	i = 0;
	j = 0;
	square = 0;
	while (i < ft_count_rows(buffer) - square)
	{
		while (j < ft_count_colomns(buffer) - square)
		{
			if (str[i][j] != 'o')
			{
				block = ft_check_square(str, i, j);
				if (square < block)
				{
					square = block;
					dest = ft_print_square(buffer, i, j, square);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
	for(int k = 0; k < ft_count_rows(buffer); k++)                                                              
    {                                                                                                        
        for(int h = 0; h < ft_count_colomns(buffer); h++)                                                       
        {                                                                                                    
            printf("%c", dest[k][h]);                                                                        
        }                                                                                                    
        printf("\n"); 
	}
}



