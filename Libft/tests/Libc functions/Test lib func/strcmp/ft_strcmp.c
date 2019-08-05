#include "../../libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	char str2[10] = "number";
	printf("%d\n", ft_strcmp(str1, str2));
	printf("%d\n", strcmp(str1, str2));

	char str3[10] = "letter";
	char str4[10] = "letter";
	printf("%d\n", ft_strcmp(str3, str4));
	printf("%d\n", strcmp(str3, str4));

	char str5[10] = "";
	char str6[10] = "";
	printf("%d\n", ft_strcmp(str5, str6));
	printf("%d\n", strcmp(str5, str6));


	printf("%d\n", ft_strcmp("test\200", "test\0"));
	printf("%d\n", strcmp("test\200", "test\0"));
	return 0;
}