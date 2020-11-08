/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:08:51 by itollett          #+#    #+#             */
/*   Updated: 2020/11/08 19:08:47 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		ft_clean(char *str)
{
	int i;

	i = 0;
	if (str[i])
	{
		while(str[i])
			str[i++] = '\0';
	}
}

static int		ft_fulfilling(char **leftover, char **line)
{
	char *pointer;
	char *temp;

	if ((pointer = ft_strchr(*leftover, '\n')))
	{
		*pointer++ = '\0';
		temp = *leftover;
		*line = ft_strdup(*leftover);
		*leftover = ft_strdup(pointer);
		free(temp);
	}
	else
	{
		*line = ft_strdup(*leftover);
		ft_clean(*leftover);
		return (0);
	}
	return (1);
}

static int		ft_check_available(char **leftover, char **line, int available)
{
	if (available < 0)
		return (-1);
	else if (available == 0 && !(*leftover))
	{	
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_fulfilling(leftover, line));
}

int				get_next_line(int fd, char **line)
{
	static char	*leftover[1024];
	char		*buff;
	int			available;
	char		*temp;

	if (!line || fd < 0 || !(buff = (char *)malloc(BUFFER_SIZE + 1))
			|| (read(fd, buff, 0)) < 0)
		return (-1);
	while ((available = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[available] = '\0';
		if (!leftover[fd])
			leftover[fd] = ft_strdup(buff);
		else
		{
			temp = leftover[fd];
			leftover[fd] = ft_strjoin(leftover[fd], buff);
			free(temp);
		}
		if (ft_strchr(leftover[fd], '\n'))
			break ;
	}
	free(buff);
	return (ft_check_available(&leftover[fd], line, available));
}
/*
int main()
{
    int fd1 = open("file", O_RDONLY);
    int fd2 = open("file", O_RDONLY);
    char *line;
    int h;
    int i;
    h = 0;
    while((i = get_next_line(fd1, &line)))
    {
        printf("i = %d %s !!!!!!!!!!!!!!\n\n", i, line);
        free(line);
    }
    printf("i = %d %s &&&&&&\n", i, line);
    free(line);
    while((i = get_next_line(fd2, &line)))
    {
        printf("i = %d %s !!!!!!!!!!!!!!\n\n", i, line);
        free(line);
    }
    printf("i = %d %s &&&&&&\n", i, line);
    free(line);
    return (0);
}*/
