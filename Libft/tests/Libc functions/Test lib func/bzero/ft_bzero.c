#include "../../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

int main(int argc, char const *argv[])
{
	/*void *mem;
	void *set;

	mem = (char *)malloc(sizeof(mem) * 5);
	set = (char *)malloc(sizeof(set) * 5);*/
	char str1[50] = "letter";
	bzero(str1, 6);
	printf("%s\n", str1);
	printf("%zu\n", strlen(str1));

	char str2[50] = "number";
	ft_bzero(str2, 6);
	printf("%s\n", str2);
	printf("%zu\n", strlen(str2));
	return 0;

	char str3[50] = "JavaScript";
	bzero(str3, 0);
	printf("%s\n", str3);
	printf("%zu\n", strlen(str3));

	char str4[50] = "Python";
	ft_bzero(str4, 0);
	printf("%s\n", str4);
	printf("%zu\n", strlen(str4));

	/*memset(mem, 'e', 5);
	ft_bzero(mem, 5);
	write(1, mem, 5);
	
	write(1, "\n", 1);
	
	memset(mem, 'e', 5);
	bzero(mem, 5);
	write(1, mem, 5);*/
	return 0;
}