/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:32:22 by thelmy            #+#    #+#             */
/*   Updated: 2024/03/04 21:05:24 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #ifndef BUFFER 
# define BUFFER 2
// #endif

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if(!s)
		return NULL;
	while (s[i] || (unsigned char)c == '\0')
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*destin;
	char const	*sourc;

	if (!dst && !src)
		return (NULL);
	destin = (char *)dst;
	sourc = (char *)src;
	i = 0;
	while (i < n)
	{
		destin[i] = sourc[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst > src)
	{
		while (len--)
			d[len] = s[len];
	}
	else
		ft_memcpy (dst, src, len);
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
		return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	if(s1)
		free(s1);
	return (str);
}

char *get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;
	int			i;
	int 		bytes;
	
	i = 0;
	bytes = 1;
	if (!buffer)
		buffer = malloc(sizeof(char ) * (BUFFER + 1));
	if (!buffer)
		return (NULL);
	str = NULL;
	while (!ft_strchr(str , '\n') && bytes > 0)
	{
		if (buffer && buffer[0] != '\0')
		{
			str = ft_strjoin(str,buffer);
		while (buffer[i] && buffer[i] != '\n')
			i++;
			if (buffer[i] == '\n')
				ft_memmove(buffer,buffer + i + 1, ft_strlen(buffer + i + 1) + 1);
			else
				buffer[0] = '\0';
		}
		else if (buffer[0] == '\0')
		{
			i = 0;
			bytes = read(fd, buffer, BUFFER);
			if (bytes == -1)
			{
				free(buffer);
				if (!str)
					free(str);
				return NULL;
			}
			buffer[bytes] = '\0';
			str = ft_strjoin(str,buffer);
			i = 0;
			while (buffer[i] && buffer[i] != '\n')
				i++;
			if (buffer[i] == '\n')
				ft_memmove(buffer,buffer + i + 1, ft_strlen(buffer + i + 1) + 1);
			else
				buffer[0] = '\0';
	}
}
 	return (str);
}

	


