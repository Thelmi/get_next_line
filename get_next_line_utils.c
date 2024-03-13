#include "get_next_line.h"

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
	int k = 0;
	while (s2[k] && s2[k] != '\n')
		k++;
	if (s2[k] == '\n')
		k++;
	str = malloc(sizeof(char) * (ft_strlen(s1) + k + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
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
