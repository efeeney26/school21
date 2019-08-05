#include "../../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

int main(int argc, char const *argv[])
{
	void *mem;

	char str1[50] = "letter";
	char str2[50] = "number";
	printf("%s\n", str1);
	memcpy(str1, str2, strlen(str2) + 1);
	printf("%s\n", str1);

	char str3[50] = "JavaScript";
	char str4[50] = "Python";
	printf("%s\n", str3);
	ft_memcpy(str3, str4, strlen(str4) + 1);
	printf("%s\n", str3);

	char str5[7] = "letter";
	char str6[7] = "number";
	printf("%s\n", (char *)ft_memcpy(str5, str6, 3));
	printf("%s\n", (char *)memcpy(str5, str6, 3));
	
	/*printf("\n");
	mem = (char *)malloc(sizeof(mem) * 30);
	printf("%s\n", (char *)ft_memcpy(mem, "zyxwvutst", 0));
	printf("%s\n", (char *)memcpy(mem, "zyxwvutst", 0));
	printf("\n");
	printf("%s\n", (char *)ft_memcpy(NULL, "segfaulter tu dois", 17));
	printf("%s\n", memcpy(NULL, "segfaulter tu dois", 17));
	printf("%s\n", (char *)ft_memcpy("            ", NULL, 17));*/

	return (0);
}