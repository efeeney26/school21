#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*dest;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(*dest) * (len1 + len2 + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (i < len1)
		dest[j++] = s1[i++];
	i = 0;
	while (i < len2)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

int main(int argc, char const *argv[])
{
	char str1[20] = "letter";
	char str2[10] = "number";
	printf("%s\n", ft_strjoin(str1, str2));
	printf("\n");
	char *str3 = '\0';
	char str4[10] = "number";
	printf("%s\n", ft_strjoin(str3, str4));
	return 0;
}