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

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

static	int		ft_intlen(int n, int min)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i + min);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		l;
	int		min;
	int		digit;

	min = (n < 0) ? 1 : 0;
	l = ft_intlen(n, min);
	if ((dest = ft_strnew(l)))
	{
		dest[l--] = '\0';
		while (l >= min)
		{
			digit = n % 10;
			digit = (digit < 0) ? (-digit) : (digit);
			dest[l] = digit + 48;
			l--;
			n = n / 10;
		}
		if (min)
			dest[0] = '-';
	}
	return (dest);
}

int main(int argc, char const *argv[])
{
	int number1 = 345;
	printf("%s\n", ft_itoa(number1));
	int number2 = 0;
	printf("%s\n", ft_itoa(number2));
	int number3 = -2147483648;
	printf("%s\n", ft_itoa(number3));

	return 0;
}