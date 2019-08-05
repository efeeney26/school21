#include "../../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	/*for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ft_putstr_fd(&argv[i][j], i);
			printf("\n");
		}
	}*/
	ft_putstr_fd("lorem ipsum dolor sit amet", 2);
}