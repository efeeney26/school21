#include "../../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int main(int argc, char const *argv[])
{
	printf("%s\n", ft_strstr("0123456789", "345") );
	printf("%s\n", strstr("0123456789", "345") );
	printf("%s\n", ft_strstr("", "") );
	printf("%s\n", strstr("", "") );
	printf("%s\n", ft_strstr("0123456789", "") );
	printf("%s\n", strstr("0123456789", "") );
	printf("%s\n", ft_strstr("0123456789", "101112") );
	printf("%s\n", strstr("0123456789", "101112") );
	return 0;
}