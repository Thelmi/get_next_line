/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:32:22 by thelmy            #+#    #+#             */
/*   Updated: 2024/02/28 10:02:32 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# define BUFFER 11

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t i;
	
	if (!str)
		return (0);
	i = 0;
	while (str)
	{
		i++;
	}
		return (i);
}
char	*ft_strncpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
char *get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;
	char		*tmp;
	int			i;

	buffer = malloc(sizeof(char ) * BUFFER + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	if (buffer[0] == '\0')
	{
		str = malloc(sizeof(char) * BUFFER + 1);
		if (!str)
			return (NULL);
		read(fd, buffer, BUFFER);
		buffer[BUFFER] = '\0';
		while (buffer[i] != '\n')
		{
			str[i] = buffer[i];
			i++;
		}
		if (buffer[i] == '\n')
			str[i] = '\n';
		return (str);
	}
	if (buffer)
	{
		tmp = malloc(sizeof(char) * ft_strlen(buffer) + 1);
		while (buffer[i])
		{
			tmp[i] = buffer[i];
			i++;
		}
		buffer[0] = '\0';
		read(fd, buffer, BUFFER);
		ft_strjoin(tmp,buffer);
		
	}
	return (NULL);
}
int main()
{
	int fd = open("text.txt", O_RDWR | O_CREAT, 777);
	printf("%s\n",get_next_line(fd));
}