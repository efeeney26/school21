#include "../../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str2[i] != '\0' && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	char str2[10] = "number";
	printf("%d\n", ft_strncmp(str1, str2, 3));
	printf("%d\n", strncmp(str1, str2, 3));

	char str3[10] = "letter";
	char str4[10] = "letter";
	printf("%d\n", ft_strncmp(str3, str4, 3));
	printf("%d\n", strncmp(str3, str4, 3));

	char str5[10] = "";
	char str6[10] = "";
	printf("%d\n", ft_strncmp(str5, str6, 3));
	printf("%d\n", strncmp(str5, str6, 3));

	return 0;
}