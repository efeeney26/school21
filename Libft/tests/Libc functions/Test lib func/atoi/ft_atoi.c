#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


int	ft_atoi(const char *str)
{
int i;
	int result;
	int sign;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_strlen(str) > 19 && ft_strlen(str) == 0)
		return (-1);
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		while ((str[i] >= 48 && str[i] <= 57))
			result = (result * 10) + str[i++] - '0';
		break ;
	}
	return (result * sign);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", ft_atoi("-5"));
	printf("%d\n", atoi("-5"));
	printf("%d\n", ft_atoi("+5"));
	printf("%d\n", atoi("+5"));
	printf("%d\n", ft_atoi("456BC"));
	printf("%d\n", atoi("456BC"));
	printf("%d\n", ft_atoi("BFG444"));
	printf("%d\n", atoi("BFG444"));
	printf("%d\n", ft_atoi("\n\t\r\v\f "));
	printf("%d\n", atoi("\n\t\r\v\f "));
	printf("%d\n", ft_atoi("-+48"));
	printf("%d\n", atoi("-+48"));
	printf("%d\n", ft_atoi("+-54"));
	printf("%d\n", atoi("+-54"));
	printf("%d\n", ft_atoi("99999999999999999999999999"));
	printf("%d\n", atoi("99999999999999999999999999"));
	printf("%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
	printf("%d\n", atoi("\t\n\r\v\f  469 \n"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", atoi("-2147483648"));
}