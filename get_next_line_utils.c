/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:02:13 by lrandria          #+#    #+#             */
/*   Updated: 2021/06/23 20:26:29 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strclen(char *buf, char c)
{
	size_t	i;

	i = 0;
	while (buf[i] != 0 && buf[i] != c)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const	char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, s, s_len + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	size;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == 0)
		return (NULL);
	i = 0;
	if (start < size)
	{
		while (s[i + start] && i < len)
		{
			new_str[i] = s[i + start];
			i++;
		}
	}
	new_str[i] = 0;
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_s == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_s[i] = ((char *)s1)[i];
		i++;
	}
	while (*s2)
	{
		new_s[i] = *s2;
		i++;
		s2++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
