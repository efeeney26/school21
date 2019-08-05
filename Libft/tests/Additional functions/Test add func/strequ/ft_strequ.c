#include "../../libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	return (strcmp(s1, s2)) ? 0 : 1;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", ft_strequ("letter", "lette"));
	printf("%d\n", ft_strequ("letter", "letter"));
	return 0;
}