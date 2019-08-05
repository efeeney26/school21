#include "../../libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	ft_putstr("letter");
	printf("\n");
	return 0;
}