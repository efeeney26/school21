#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 4900


void    ft_print_array(int **str);
void    ft_solver(int **str, char *buffer);

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_count_name (char *str)
{
	int i;
	i = 0;

	while (str[i] != '\n')
		i++;
	return (i++);
}

int ft_count_colomns (char *str)
{
	int i;
	int result;

	i = 0;
	while ((str[i] != '\n') && (str[i]) != '\0')
		i++;
	result = i + 1;
	i = 0;
	while (str[result] != '\n')
	{
		i++;
		result++;
	}
	return (i);
}


int ft_count_rows (char *str)
{
	int i;
	int count_rows;

	i = 0;
	count_rows = 0;

	while (str[i] != '\0')
	{
		if(str[i] == '\n')
			count_rows++;
		i++;
	}
	return (count_rows - 1);
}

int	**ft_form_array(char *str)
{
	int i;
	int j;
	int index;
	int **arr;
	arr = (int **)malloc(sizeof(int *) * ft_count_rows(str));
    i = 0;
    index = ft_count_name(str);
    while (i < ft_count_rows(str))
    {
        arr[i] = (int *)malloc(sizeof(int) * ft_count_colomns(str));
        j = 0;
        while (j < ft_count_colomns(str))
        {
            if(str[index] != '\n')
            {
                arr[i][j] = str[index];
                j++;
            }
            index++;
        }
        i++;
    }
  
	return (arr);
}

int **ft_form_array_input(char *str)
{
    int i;
    int j;
    int index;
    int **arr;
    arr = (int **)malloc(sizeof(int *) * ft_count_rows(str));
    i = 0;
    index = 0;
    while (i < ft_count_rows(str))
    {
        arr[i] = (int *)malloc(sizeof(int) * ft_count_colomns(str));
        j = 0;
        while (j < ft_count_colomns(str))
        {
            if(str[index] != '\n')
            {
                arr[i][j] = str[index];
                j++;
            }
            index++;
        }
        i++;
    }

    return (arr);
}

int     ft_check_square(int **str, int y, int x)
{
    int block;
    int a;
    int b;
    int result;

    a = 0;
    b = 0;
    block = 0;
    while (str[y][x])
    {
        b = 0;
        while (a <= block)
        {
            if (str[y+b][x+a] == 'o')
                return (block);
            a++;
            if (a >= block && b < block)                     //+
            {
                a = 0;
                b++;
            }
		}
		block++;
		a = 0;
		b = 0;
    }
    return (block);
}



int     **ft_print_square(char *str, int y, int x,int square)
{
	int **arr;
    int **temp;
    int i;
    int j;

	arr = ft_form_array(str);

    i = 0;
    temp = (int **)malloc(sizeof(int *) * ft_count_rows(str));
    while ( i < ft_count_rows(str))
    {
        j = 0;
		temp[i] = (int *)malloc(sizeof(int) * ft_count_colomns(str));   //+
        while (j < ft_count_colomns(str))
        {
			temp[i][j] = arr[i][j];
			j++;
        }
        i++;
    }
    i = y;
    j = x;
    while (y < i + square - 1)
    {
		x = j;
        while (x < j + square - 1)
		{
            temp[y][x] = 'X';
			x++;
		}
		y++;
    }
    return (temp);
}

int	ft_str_len(char *str)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


int main(int argc, char **argv)
{
	int fd;
	int ret;
	int **arr;
	int i;
	char buf[BUF_SIZE + 1];
	if (argc == 1)
	{
		fd = 0;
		ret = write(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		arr = ft_form_array_input(buf);
		ft_solver(arr, buf);
	}

	else
	{
	i = 1;
	while (argv[i])
		{
		fd = open(argv[i++], O_RDONLY);
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		arr = ft_form_array(buf);
		ft_solver(arr, buf);
		write(1, "\n", 1);
	}
	}
	return (0);
}
