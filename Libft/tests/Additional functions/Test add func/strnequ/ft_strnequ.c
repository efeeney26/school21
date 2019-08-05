#include "../../libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && i < n)
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

int main(int argc, char const *argv[])
{
	char str1[10] = "letter";
	char str2[10] = "number";
	printf("%d\n", ft_strnequ(str1, str2, 3));
	

	char str3[10] = "letter";
	char str4[10] = "letter";
	printf("%d\n", ft_strnequ(str3, str4, 3));
	

	char str5[10] = "";
	char str6[10] = "";
	printf("%d\n", ft_strnequ(str5, str6, 3));
	
	return 0;
}