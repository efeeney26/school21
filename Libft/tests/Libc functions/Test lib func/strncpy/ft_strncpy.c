#include "../../libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	char str2[10] = "number";
	printf("%s\n", ft_strncpy(str1, str2, 4));
	printf("%s\n", strncpy(str1, str2, 4));
	printf("\n");
	char str3[1] = "";
	char str4[10] = "number";
	printf("%s\n", ft_strncpy(str3, str4, 0));
	printf("%s\n", strncpy(str3, str4, 0));
	return 0;
	return 0;
}