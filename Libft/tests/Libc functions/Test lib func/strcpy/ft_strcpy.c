#include "../../libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	char str2[10] = "number";
	printf("%s\n", ft_strcpy(str1, str2));
	printf("%s\n", strcpy(str1, str2));
	printf("\n");
	char str3[1] = "";
	char str4[10] = "number";
	printf("%s\n", ft_strcpy(str3, str4));
	printf("%s\n", strcpy(str3, str4));
	return 0;
}