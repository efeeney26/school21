#include "../../libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
		return (0);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", ft_isalpha('c'));
	printf("%d\n", ft_isalpha('\n'));
	printf("%d\n", isalpha('c'));
	printf("%d\n", isalpha('\n'));
	return 0;
}