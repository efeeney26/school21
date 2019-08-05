#include "../../libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
		return (0);
}

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

int main(int argc, char const *argv[])
{
	printf("%d\n", ft_isalnum('c'));
	printf("%d\n", ft_isalnum('\n'));
	printf("%d\n", isalnum('c'));
	printf("%d\n", isalnum('\n'));
	return 0;
}