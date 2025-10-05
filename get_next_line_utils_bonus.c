/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:39:09 by nkojima           #+#    #+#             */
/*   Updated: 2025/08/03 19:24:15 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * Calculate the length of a string
 *
 * @param str String to measure
 * @return size_t Length of the string (0 if NULL)
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

/**
 * Find the first occurrence of a character in a string
 *
 * @param str String to search
 * @param c Character to find
 * @return char* Pointer to the found character, NULL if not found
 */
char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

/**
 * Duplicate a string
 *
 * @param s1 String to duplicate
 * @return char* Newly allocated copy of the string, NULL on error
 */
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	dup = malloc(sizeof(*dup) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

/**
 * Join two strings together
 *
 * @param s1 First string (will be freed within this function)
 * @param s2 Second string
 * @return char* Newly allocated joined string, NULL on error
 *
 * Note: This function frees the first argument
 */
char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*joined;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = malloc(sizeof(*joined) * (len1 + len2 + 1));
	if (!joined)
		return (free(s1), NULL);
	i = 0;
	while (s1 && i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && i < len2)
	{
		joined[len1 + i] = s2[i];
		i++;
	}
	joined[len1 + len2] = '\0';
	return (free(s1), joined);
}

/**
 * Copy memory area
 *
 * @param dst Destination memory area
 * @param src Source memory area
 * @param n Number of bytes to copy
 * @return void* Pointer to destination
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
