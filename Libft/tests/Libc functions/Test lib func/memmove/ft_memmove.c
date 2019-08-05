#include "../../libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	/*size_t	i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	while (i < len && source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);*/
	char	*source;
	char	*dest;
	size_t	i;

	i = -1;
	source = (char *)src;
	dest = (char *)dst;
	if (source < dest)
		while ((int)(--len) >= 0)
			*(dest + len) = *(source + len);
	else
		while (++i < len)
			*(dest + i) = *(source + i);
	return (dst);
}

int main()
{
	char str5[7] = "le";
	char str6[7] = "number";
	printf("%s\n", memmove(str5, str6, 4));
	printf("%s\n\n", ft_memmove(str5, str6, 4));

	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	dest = src + 1;
	printf("%s\n", ft_memmove(dest, "consectetur", 5));
	printf("%s\n", memmove(dest, "consectetur", 5));
	printf("\n");
	printf("%s\n", ft_memmove(dest, "con\0sec\0\0te\0tur", 10));
	printf("%s\n", memmove(dest, "con\0sec\0\0te\0tur", 10));
	printf("\n");
	printf("%s\n", ft_memmove(dest, src, 8));
	printf("%s\n", memmove(dest, src, 8));
	printf("\n");
	printf("%s\n", ft_memmove(src, dest, 8));
	printf("%s\n", memmove(src, dest, 8));
	printf("\n");
	printf("%s\n", ft_memmove(src, dest, 0));
	printf("%s\n", memmove(src, dest, 0));

	//printf("%s\n", ft_memmove(NULL, NULL, 1));
	printf("%s\n", memmove(NULL, NULL, 1));
	return 0;
}
