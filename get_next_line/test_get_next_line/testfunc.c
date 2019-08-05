#include "libft.h"
#include <fcntl.h>


# define BUFF_SIZE 1
int		get_next_line(const int fd, char **line);

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

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, src));
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*dest;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(*dest) * (len1 + len2 + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (i < len1)
		dest[j++] = s1[i++];
	i = 0;
	while (i < len2)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	s;

	s = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == s)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == s)
		return ((char *)&str[i]);
	else
		return (NULL);
}



void	swap_new(char **arr, int fd, int len)
{
	char *temp;

	temp = ft_strdup(&arr[fd][len + 1]);
	free(arr[fd]);
	arr[fd] = temp;
}

void	swap_next(char **arr, int fd, char *buf)
{
	char *temp;

	temp = ft_strjoin(arr[fd], buf);
	free(arr[fd]);
	arr[fd] = temp;
}

int		check_error(int ret, char **arr, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (arr[fd] == NULL || arr[fd][0] == '\0'))
		return (0);
	else
		return (1);
}

int		get_newline(char **arr, char **line, int fd)
{
	int		len;

	len = 0;
	while (arr[fd][len] != '\n' && arr[fd][len] != '\0')
		len++;
	if (arr[fd][len] == '\n')
	{
		*line = ft_strsub(arr[fd], 0, len);
		swap_new(arr, fd, len);
	}
	else if (arr[fd][len] == '\0')
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*arr[10000000000000];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			err;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strnew(1);
		swap_next(arr, fd, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	err = check_error(ret, arr, fd);
	if (err < 0)
		return (-1);
	else if (!err)
		return (0);
	return (get_newline(arr, line, fd));
}


int main(int argc, char const *argv[])
{
	char *line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	fd = open(argv[2], O_RDONLY);
	fd = open(argv[3], O_RDONLY);
	get_next_line(3, &line);
	printf("%s\n", line);
	get_next_line(4, &line);
	printf("%s\n", line);
	get_next_line(5, &line);
	printf("%s\n", line);
	get_next_line(4, &line);
	printf("%s\n", line);
	get_next_line(5, &line);
	printf("%s\n", line);
	get_next_line(3, &line);
	printf("%s\n\n", line);

	while (get_next_line(3, &line) == 1)
		printf("%s\n", line);
	if (argc == 2)
		close(fd);
	fd = open(argv[1], O_RDONLY);
	get_next_line(3, &line);

}