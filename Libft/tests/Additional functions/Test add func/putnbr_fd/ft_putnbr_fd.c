#include "../../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned i;

	if (n < 0)
		ft_putchar_fd('-', fd);
	i = (n < 0) ? (-n) : (n);
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
		ft_putchar_fd(i + 48, fd);
}

int main(int argc, char const *argv[])
{
	ft_putnbr_fd(345, 1);
	return 0;
}