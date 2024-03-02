/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:32:22 by thelmy            #+#    #+#             */
/*   Updated: 2024/03/02 16:02:41 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #ifndef BUFFER 
# define BUFFER 16
// #endif

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
	return (str);
}

// char	*ft_strncpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i] && i < dstsize - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }
char *get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;
	char		*tmp;
	int			i;
	
	if (!buffer)
		buffer = malloc(sizeof(char ) * (BUFFER + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	if (buffer[0] == '\0')
	{
		str = malloc(sizeof(char) * (BUFFER + 1));
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
			str[i++] = '\n';
		str[i] = '\0';
		i = 0;
		while (buffer[i] != '\n')
			i++;
		ft_memmove(buffer,buffer + i + 1, ft_strlen(buffer + i + 1) + 1);
	}
	
// 	if (buffer && buffer[0] != '\0')
// 	{
// 		tmp = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
// 		if(!tmp)
// 			return(NULL);
// 		while (buffer[i] )
// 		{
// 			tmp[i] = buffer[i];
// 			i++;
// 		}
// 		buffer[0] = '\0';
// 		i = 0;
// 		read(fd, buffer, BUFFER);
// 		str = ft_strjoin(tmp,buffer);
// 		while (buffer[i] != '\n')
// 			i++;
// 		ft_memmove(buffer,buffer + i + 1, ft_strlen(buffer + i + 1) + 1);
// 	}
 	return (str);
}
int main()
{
	int fd = open("text.txt", O_RDWR | O_CREAT, 777);
	printf("%s",get_next_line(fd));
}

