#include "../../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main(int argc, char const *argv[])
{
	/*for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ft_putchar_fd(argv[i][j], i);
			printf("\n");
		}
	}*/

	ft_putchar_fd('c', 1);
	return 0;
}