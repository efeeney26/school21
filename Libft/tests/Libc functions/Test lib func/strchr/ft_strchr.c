#include "../../libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	s;

	s = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == s)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == s)
		return ((char *)&str[i]);
	else
		return (NULL);
}

int main(int argc, char const *argv[])
{
	printf("%s\n", ft_strchr("letter", 't'));
	printf("%s\n", strchr("letter", 't'));
	
	char	str2[] = "bonjour";
	printf("%s\n", ft_strchr(str2, '\0'));

	return 0;
}