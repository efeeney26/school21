#include "../../libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (str1[i] != '\0')
		i++;
	j = 0;
	while (str2[j] != '\0' && n > 0)
	{
		str1[i] = str2[j];
		i++;
		j++;
		n--;
	}
	str1[i] = '\0';
	return (str1);
}

int main(int argc, char const *argv[])
{
	char str1[20] = "letter";
	char str2[10] = "lorem";

	printf("%s\n", ft_strncat(str1, str2, 6));
	printf("%s\n", strncat(str1, str2, 6));
	return 0;
}