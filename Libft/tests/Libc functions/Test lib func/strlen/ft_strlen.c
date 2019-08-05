#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int main(int argc, char const *argv[])
{
	printf("%zu\n", ft_strlen("letter"));
	printf("%zu\n", strlen("letter"));
	printf("\n");
	printf("%zu\n", ft_strlen(""));
	printf("%zu\n", strlen(""));
	return 0;
}