#include "../../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;
	char	symbol;

	dest = (char *)dst;
	source = (char *)src;
	symbol = (char)c;
	i = 0;
	while (i < n && (i == 0 || source[i - 1] != symbol))
	{
		dest[i] = source[i];
		i++;
		if (c == 0 && dest[i] == '\0')
			return (&dest[i]);
	}
	if (i > 0 && source[i - 1] == symbol)
		return (&dest[i]);
	else
		return (NULL);
}

int main(int argc, char const *argv[])
{
	char str1[50] = "letter";
	char str2[50] = "number";
	printf("%s\n", str1);
	ft_memccpy(str1, str2, 'm',strlen(str2) + 1);
	printf("%s\n", str1);

	char str3[50] = "letter";
	char str4[50] = "number";
	printf("%s\n", str3);
	memccpy(str3, str4, 'm',strlen(str3) + 1);
	printf("%s\n", str3);

	char str5[50] = "letter";
	char str6[50] = "number";
	printf("%s\n", str5);
	ft_memccpy(str5, str6, 'c',strlen(str6) + 1);
	printf("%s\n", str5);

	char str7[50] = "letter";
	char str8[50] = "number";
	printf("%s\n", str7);
	memccpy(str7, str8, 'c',strlen(str8) + 1);
	printf("%s\n", str7);
	
	char str9[50] = "letter";
	char str10[50] = "number";
	printf("%s\n", ft_memccpy(str9, str10, 'm',strlen(str10) + 1));
	printf("%s\n", ft_memccpy(str9, str10, 'p',strlen(str10) + 1));
	printf("%s\n", memccpy(str9, str10, 'm',strlen(str10) + 1));
	printf("%s\n", memccpy(str9, str10, 'p',strlen(str10) + 1));
	return (0);
}