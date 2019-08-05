#include "../../libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		symbol;
	unsigned const char	*str;

	i = 0;
	str = (unsigned const char *)s;
	symbol = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == symbol)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	char str2[10] = "number";
	printf("%s\n", (char *)ft_memchr(str1, 't', 6));
	printf("%s\n", (char *)memchr(str1, 't', 6));
	printf("%s\n", (char *)ft_memchr(str2, 't', 6));
	printf("%s\n", (char *)memchr(str2, 't', 6));
	printf("%s\n", (char *)ft_memchr(str1, 't', 0));
	printf("%s\n", (char *)memchr(str1, 't', 0));
	printf("\n");

	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	printf("%s\n", (char *)memchr(tab, -1, 7));

	printf("%s\n", (char *)ft_memchr("/|\x12\xff\x09\0\x42\042\0\42|\\", '\0', 12));
	printf("%s\n", (char *)memchr("/|\x12\xff\x09\0\x42\042\0\42|\\", '\0', 12));
	//printf("%s\n", ft_memchr(NULL, 0, 0));
	//printf("%s\n", (char *)memchr(NULL, 1, 2));
	return 0;
}