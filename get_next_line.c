/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:32:22 by thelmy            #+#    #+#             */
/*   Updated: 2024/03/13 16:26:47 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			i;
	int 		bytes;

	i = 0;
	bytes = 1;
	str = NULL;
	if (fd < 0)
		return (NULL);
	while (!ft_strchr(str , '\n') && bytes > 0)
	{
		if (buffer[0] != '\0')
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
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes == -1)
			{
				// free(buffer);
				if (str)
					free(str);
				return NULL;
			}
			if (bytes == 0)
				return (str);
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

// int main()
// {
// 	char *s = NULL;
// 	int fd = open("text.txt", O_RDONLY);
// 	// while (1)
// 	// {
// 	// 	s = get_next_line(fd);
// 	// 	if (s)
// 	// 	{
// 	// 		printf("%s", s);
// 	// 		free(s);
// 	// 	}
// 	// 	else if (!s)
// 	// 		break ;
// 	// }
// 	int i = 0;
// 	while (i < 15)
// 	{
// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		if (s)
// 			free(s);
// 		i++;
// 	}
// 	// s = get_next_line(fd);
// 	// printf("%p", s);
// }

// int main(int ac, char **av)
// {
// 	int fd = open(av[1], O_RDONLY);
// 	char *str;
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	(void)ac;
// }