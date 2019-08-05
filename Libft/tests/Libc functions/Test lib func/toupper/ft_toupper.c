#include "../../libft.h"

int ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int main(int argc, char const *argv[])
{
	printf("%c\n", ft_toupper('c') );
	printf("%c\n", toupper('c') );
	printf("%c\n", ft_toupper('A') );
	printf("%c\n", ft_toupper('A') );
	printf("%c\n", ft_toupper(0) );
	printf("%c\n", ft_toupper(0) );
	printf("%c\n", ft_toupper('Fg') );
	printf("%c\n", ft_toupper('Fg') );
	return 0;
}