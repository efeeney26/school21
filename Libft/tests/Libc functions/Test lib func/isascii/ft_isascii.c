#include "../../libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", ft_isascii('i'));
	printf("%d\n", isascii('i'));
	return 0;
}