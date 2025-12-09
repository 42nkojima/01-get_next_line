/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:56:30 by nkojima           #+#    #+#             */
/*   Updated: 2025/12/09 22:59:55 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total_len;
	char	*joined;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	joined = malloc(sizeof(*joined) * (total_len + 1));
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, len1);
	ft_memcpy(joined + len1, s2, len2);
	joined[total_len] = '\0';
	return (joined);
}

/**
 * Copy memory area
 *
 * @param dst Destination memory area
 * @param src Source memory area
 * @param n Number of bytes to copy
 * @return void* Pointer to destination
 */
void	*ft_memcpy(void *dst, const void *src, size_t cpy_size)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (cpy_size == 0 || dst == src)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	while (cpy_size--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
