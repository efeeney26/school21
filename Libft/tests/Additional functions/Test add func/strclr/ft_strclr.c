#include "../../libft.h"

void	ft_strclr(char *s)
{
	if (s)
		bzero(s, strlen(s));
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	ft_strclr(str1);
	printf("%zu\n", strlen(str1));
	return 0;
}