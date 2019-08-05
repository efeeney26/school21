#include "../../libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		if (n)
			i++;
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	char str2[10] = "number";
	printf("%d\n", ft_memcmp(str1, str2, 3));
	printf("%d\n", memcmp(str1, str2, 3));

	char str3[10] = "letterru";
	char str4[10] = "letterry";
	printf("%d\n", ft_memcmp(str3, str4, 7));
	printf("%d\n", memcmp(str3, str4, 7));

	char str5[10] = "";
	char str6[10] = "";
	printf("%d\n", ft_memcmp(str5, str6, 3));
	printf("%d\n", memcmp(str5, str6, 3));
	printf("\n");
	
	printf("%d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("%d\n", memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("\n");

	printf("%d\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	printf("%d\n", memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	printf("\n");

	printf("%d\n", ft_memcmp("atoms\0\0\0\0", "atoms\0abc", 8));
	printf("%d\n", memcmp("atoms\0\0\0\0", "atoms\0abc", 8));

	return 0;
}