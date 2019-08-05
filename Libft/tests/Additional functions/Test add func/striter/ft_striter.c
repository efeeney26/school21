#include "../../libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(&(s[i]));
			i++;
		}
	}
}

void	iter(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	ft_striter(str1, &iter);
	printf("%s\n", str1);
	printf("\n");
	char str2[1] = "";
	ft_striter(str2, &iter);
	printf("%s\n", str2);
	return 0;
}