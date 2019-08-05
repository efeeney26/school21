#include "../../libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char const *argv[])
{
	ft_putchar('c');
	ft_putchar('\n');

	return 0;
}