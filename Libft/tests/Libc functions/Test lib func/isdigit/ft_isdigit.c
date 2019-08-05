#include "../../libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int main(int argc, char const *argv[])
	{
		printf("%d\n", ft_isdigit('B'));
		printf("%d\n", isdigit('B'));
		printf("%d\n", ft_isdigit('4'));
		printf("%d\n", isdigit('4'));
		return 0;
	}	