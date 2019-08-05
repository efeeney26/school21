#include "../../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(i, &(s[i]));
			i++;
		}
	}
}

void	iter(unsigned int i, char *c)
{
	printf("%d\n", i);
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	ft_striteri(str1, &iter);
	printf("%s\n", str1);
	printf("\n");
	char str2[10] = "";
	ft_striteri(str2, &iter);
	printf("%s\n", str2);
	return 0;
}