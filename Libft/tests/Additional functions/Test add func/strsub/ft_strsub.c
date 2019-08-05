#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	bzero(str, size + 1);
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int i;
	char *str;

	i = 0;
	if (!s)
		return (NULL);
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;	
	}
	return (str);
}

int main(int argc, char const *argv[])
{
	printf("%s\n", ft_strsub("letter", 4, 2)); 
	return 0;
}