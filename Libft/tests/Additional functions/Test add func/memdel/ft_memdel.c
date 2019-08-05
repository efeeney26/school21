#include "../../libft.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

int main(int argc, char const *argv[])
{
	void *mem;
	mem = malloc(sizeof(mem) * 10);
	ft_memdel(&mem);
	if (!mem)
		printf("%s\n", "NULL");
	else
		printf("%s\n", "NOt NULL");
	return 0;
}