#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *str1, const char *str2)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str1);
	while (str2[i] != '\0')
	{
		str1[i + len] = str2[i];
		i++;
	}
	str1[i + len] = '\0';
	return (str1);
}

int main(int argc, char const *argv[])
{
	char str3[20] = "pop";
	char str4[10] = "lol";
	printf("%s\n", ft_strcat(str3, str4));
	printf("%s\n", strcat(str3, str4));
	return 0;
}