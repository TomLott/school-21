#include "get_next_line.h"

char *ft_read(char *buff, char *leftover)
{
	char *line;
	int i;
	int len;

	i = 0;
	len = 0;
	printf("ft_read: beg\n");
	while (buff[len] != '\n' && buff[len] != '\0')
		len++;
	printf("%d len \n", len);
	line = (char *)malloc(sizeof(char) * (len + 1));
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	printf("%s line\n", line);
	leftover = (char *)malloc(sizeof(char) * (ft_strlen(buff) - len - 1));
	printf("%lu for malloc\n", ft_strlen(buff) - len - 1);
	len = 0;
	while (buff[++i] != '\0')
	{
		printf("%d inside \n", i);
		printf("%c buff[i] \n", buff[i]);
		leftover[len] = buff[i];
		len++;
	}
	printf("%d on the end\n", (len));
	printf("%s leftover\n", leftover);
	leftover[len] = '\0';
	return (line);
}

int	ft_find(char *str, char c)
{
	if (!str)
		return (0);
	while(*str)
	{
		if(*str == c)
			return (1);
		str++;
	}
	if (*str == c)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *leftover;
	char *buff;
	char *temp;
	int available;

	available = 0;
	printf("KIRA LOH\n");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (ft_find(leftover, '\n'))
	{
		write(1, "FFFFF\n", 6);
		*line = ft_read(leftover, leftover);
		return (1);
	}
	while ((available = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		printf("%d avail\n", available);
		buff[available] = '\0';
		if (leftover != NULL)
			temp = ft_strdup(leftover);
		if (ft_find(leftover, '\n') != 0)
		{
			*line = ft_read(temp, leftover);
			return (1);
		}
		else if(ft_find(buff, '\n') != 0)
		{
			if (temp)
				*line = ft_strjoin(temp, ft_read(buff, leftover));
			else
				*line = ft_read(buff, leftover);
			printf("%s\n", *line);
			return (1);
		}
		else
		{
			leftover = ft_strjoin(leftover, buff);
			return(1);

		}
	}
	return (0);
}

int main()
{
	int fd = open("file", O_RDONLY);
	char *line;
	int i;
	while((i = get_next_line(fd, &line)))
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
	return (0);
}
	
