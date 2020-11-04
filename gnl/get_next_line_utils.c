#include "get_next_line.h" 

size_t  ft_strlen(const char *string)
{
    char    *temp;
    size_t  i;

    temp = (char *)string;
    i = 0;
    while (temp[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(const char *s1)
{
    size_t  i;
    char    *str;

    i = 0;
    while (s1[i])
        i++;
    if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (ft_strdup(""));
	i = ft_strlen(s1) + ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char    *ft_strchr(const char *s, int c)
{
    size_t  i;
    char    *str;

    str = (char *)s;
    i = 0;
    while (str[i])
    {
        if (str[i] == (unsigned char)c)
            return (&str[i]);
        i++;
    }
    if ((unsigned char)c == '\0')
        return (&str[i]);
    return (NULL);
}
