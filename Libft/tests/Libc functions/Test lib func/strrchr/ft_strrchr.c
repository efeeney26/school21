#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *str, int c)
{
	char	s;
	size_t	len;

	s = (char)c;
	len = ft_strlen(str);
	while (len != -1)
	{
		if (str[len] == s)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}

int main(int argc, char const *argv[])
{
	printf("%s\n", ft_strrchr("letter", 'e')); 
	printf("%s\n", ft_strrchr("", '\0'));
	printf("%s\n", ft_strrchr("letter", 'l'));
	printf("\n");
	printf("%s\n", strrchr("letter", 'e')); 
	printf("%s\n", strrchr("", '\0'));
	printf("%s\n", strrchr("letter", 'l'));
	return (0);
}