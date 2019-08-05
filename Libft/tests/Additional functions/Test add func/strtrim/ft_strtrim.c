#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dest;
	int		a;

	a = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = ft_strlen(s) - 1;
	while (j >= i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	dest = ft_strnew(j - i);
	if (dest == NULL)
		return (NULL);
	while (i <= j)
		dest[a++] = s[i++];
	dest[a] = '\0';
	return (dest);
}

int main(int argc, char const *argv[])
{
	char str1[20] = "    letter			";
	printf("%s\n", ft_strtrim(str1));
	char *str2 = '\0';
	printf("%s\n", ft_strtrim(str2));
	return 0;
}