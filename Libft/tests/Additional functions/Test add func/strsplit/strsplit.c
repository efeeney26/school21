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

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = ft_strnew(len);
	if (!str)
	{
		return (NULL);
	}
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static	int			ft_count_words(char const *s, char c)
{
	int		cnt;
	int		subs;

	subs = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (subs == 1 && *s == c)
			subs = 0;
		if (subs == 0 && *s != c)
		{
			subs = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static	int			ft_strclen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_count_words((const char *)s, c);
	dest = (char **)malloc(sizeof(*dest) * (j) + 1);
	if (dest == NULL)
		return (NULL);
	while (j--)
	{
		while (*s == c && *s != '\0')
			s++;
		dest[i] = ft_strsub((const char *)s, 0, ft_strclen((const char *)s, c));
		if (dest[i] == NULL)
			return (NULL);
		s = s + ft_strclen((const char *)s, c);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

int main(int argc, char const *argv[])
{
	char **str1;
	int i;

	i = 0;
	str1 = ft_strsplit("letter\nnumber\njs\nvue\nreact", '\n');
	while (str1[i] != '\0')
	{
		printf("%s\n", str1[i]);
		i++;
	}
	return 0;
}