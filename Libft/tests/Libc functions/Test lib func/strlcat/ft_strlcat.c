#include "../../libft.h"

size_t	ft_strlcat(char *dst, const char * src, size_t size)
{

	int 		i;
	int			j;
	size_t		dstLen;
	size_t		srcLen;

	i = 0;
	dstLen = strlen(dst);
	srcLen = strlen(src);
	if (size <= dstLen)
		return (srcLen + size);
	while ((dst[i] != '\0') && i < (size - 1))
		i++;
	j = 0;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstLen + srcLen);
}

int main(int argc, char const *argv[])
{
	char str1[20] = "letter";
	char str2[10] = "number";
	printf("%zu\n", ft_strlcat(str1, str2, 2));
	printf("%zu\n", strlcat(str1, str2, 2));
	printf("%zu\n", ft_strlcat(str1, str2, 6));
	printf("%zu\n", strlcat(str1, str2, 6));
	return 0;
}