#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (ft_strncmp((char *)&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
int main(int argc, char const *argv[])
{
	printf("%s\n", ft_strnstr("0123456789", "345", 6) );
	printf("%s\n", strnstr("0123456789", "345", 6) );
	printf("%s\n", ft_strnstr("", "", 3) );
	printf("%s\n", strnstr("", "", 3) );
	printf("%s\n", ft_strnstr("0123456789", "", 5) );
	printf("%s\n", strnstr("0123456789", "", 5) );
	printf("%s\n", ft_strnstr("0123456789", "101112", 5) );
	printf("%s\n", strnstr("0123456789", "101112", 5) );

	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15));
	return 0;
}