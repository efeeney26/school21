#include "../../libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int main(int argc, char const *argv[])
{
	printf("%c\n", ft_tolower('A') );
	printf("%c\n", tolower('A') );
	printf("%c\n", ft_tolower('c') );
	printf("%c\n", tolower('c') );
	printf("%c\n", ft_tolower(0) );
	printf("%c\n", tolower(0) );
	printf("%c\n", ft_tolower('Fg') );
	printf("%c\n", tolower('Fg') );
	return 0;
}