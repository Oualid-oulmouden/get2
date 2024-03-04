/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulmoud <ooulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:02:40 by ooulmoud          #+#    #+#             */
/*   Updated: 2024/03/04 20:58:35 by ooulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		rd;

	rd = 1;
	buff = malloc(sizeof(char) * ((size_t)(BUFFER_SIZE + 1)));
	if (!buff)
		return (NULL);
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			check1(str, buff);
		buff[rd] = '\0';
		str = ft_strjoin(str,buff);
	}
	free(buff);
	return (str);
}

char	*check1(char *s1, char *s2)
{
	free(s2);
	if (s1)
		free(s1);
	return (NULL);
}

char	*get_next(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[j] = str[i];
		j++;
		i++;
	}
	if(str)
		free(str);
	s[j] = '\0';
	return (s);
}

char	*get_line_befor(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	j = i;
	s = malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!s)
		return (NULL);
	while (i < j)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = get_line_befor(str);
	str = get_next(str);
	return (line);
}

int main()
{
    int fd;
	int i = 0;
	char *line;
	char path[] = "example.txt";

    fd = open(path,O_RDWR);
	while(i <= 6)
	{
		line = get_next_line(fd);
		printf("%s",line);
		free(line);
		i++;
	}
}