#include "../../libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned i;

	if (n < 0)
		ft_putchar('-');
	i = (n < 0) ? (-n) : (n);
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + 48);
}

int main(int argc, char const *argv[])
{
	ft_putnbr(345);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	return 0;
}