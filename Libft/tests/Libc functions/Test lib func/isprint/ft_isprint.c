#include "../../libft.h"

int	ft_isprint(int c)
{
	char s;

	s = (char)c;
	if (s >= 32 && s <= 126)
	{
		return (1);
	}
	else
		return (0);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", ft_isprint('c'));
	printf("%d\n", ft_isprint('\v'));
	printf("%d\n", isprint('c'));
	printf("%d\n", isprint('\v'));
	return 0;
}