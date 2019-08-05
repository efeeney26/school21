#include "../../libft.h"

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int main(int argc, char const *argv[])
{
	char *str;
	str = (char *)malloc(sizeof(str) * 10);
	ft_strdel(&str);
	if (!str)
		printf("%s\n", "NULL");
	else
		printf("%s\n", "NOt NULL");
	return 0;
}