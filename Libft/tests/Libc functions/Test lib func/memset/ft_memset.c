#include "../../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	s;
	char	*str;

	str = (char *)b;
	s = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = s;
		i++;
	}
	return (str);
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	char str2[10] = "number";
	char sym = 'c';
	printf("%s\n", ft_memset(str1, sym, 3));
	printf("%s\n", ft_memset(str2, sym, 11));
	printf("%s\n", memset(str1, sym, 3));
	printf("%s\n", memset(str2, sym, 11));
	return 0;
}