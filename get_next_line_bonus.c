/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:39:04 by nkojima           #+#    #+#             */
/*   Updated: 2025/08/03 19:34:07 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * Extract a line that contains a newline character
 *
 * @param stored_data Pointer to the stored data
 * @param newline_pos Position of the newline character
 * @return char* Extracted line (including newline), NULL on error
 */
static char	*extract_line_with_newline(char **stored_data, char *newline_pos)
{
	char	*line;
	char	*temp;
	size_t	line_len;

	line_len = newline_pos - *stored_data + 1;
	line = malloc(line_len + 1);
	if (!line)
		return (free(*stored_data), *stored_data = NULL, NULL);
	ft_memcpy(line, *stored_data, line_len);
	line[line_len] = '\0';
	temp = *stored_data;
	*stored_data = ft_strdup(newline_pos + 1);
	if (!*stored_data)
		return (free(line), free(temp), *stored_data = NULL, NULL);
	free(temp);
	return (line);
}

/**
 * Extract a line from the stored data
 *
 * @param stored_data Pointer to the stored data
 * @return char* Extracted line, NULL if no data or error
 */
static char	*extract_line(char **stored_data)
{
	char	*newline_pos;
	char	*line;

	if (!*stored_data || **stored_data == '\0')
		return (free(*stored_data), *stored_data = NULL, NULL);
	newline_pos = ft_strchr(*stored_data, '\n');
	if (newline_pos)
		return (extract_line_with_newline(stored_data, newline_pos));
	line = ft_strdup(*stored_data);
	return (free(*stored_data), *stored_data = NULL, line);
}

/**
 * Read data from file into buffer and append to stored data
 *
 * @param fd File descriptor
 * @param buffer Buffer for reading
 * @param stored_data Pointer to stored data
 * @return int Read status (negative: error, 0: newline found or EOF,
	positive: continue)
 */
static int	handle_buffer_read(int fd, char *buffer, char **stored_data)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	buffer[bytes_read] = '\0';
	temp = ft_strjoin(*stored_data, buffer);
	if (!temp)
		return (*stored_data = NULL, -1);
	*stored_data = temp;
	if (ft_strchr(*stored_data, '\n'))
		return (0);
	return (1);
}

/**
 * Read from file until a newline is found
 *
 * @param fd File descriptor
 * @param stored_data Stored data
 * @return char* Read data, NULL on error
 */
static char	*read_until_newline(int fd, char *stored_data)
{
	char	*buffer;
	int		read_result;

	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(stored_data), NULL);
	while (1)
	{
		read_result = handle_buffer_read(fd, buffer, &stored_data);
		if (read_result <= 0)
			break ;
	}
	free(buffer);
	if (read_result < 0)
		return (free(stored_data), NULL);
	return (stored_data);
}

/**
 * Get the next line from a file
 *
 * @param fd File descriptor
 * @return char* Next line from file (including newline), NULL on error or EOF
 *
 * This function reads the next line from the specified file descriptor.
 * Lines are delimited by newline characters, which are included in the output.
 */
char	*get_next_line(int fd)
{
	static char	*stored_data[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!stored_data[fd] || !ft_strchr(stored_data[fd], '\n'))
		stored_data[fd] = read_until_newline(fd, stored_data[fd]);
	return (extract_line(&stored_data[fd]));
}

// #include <fcntl.h>
// #include <stdio.h>

// int    main(void)
// {
//     int        fd_sample;
//     int        fd_sam;
//     char    *line;
//     int        i;

//     // fd = 0;
//     fd_sample = open("sample.txt", O_RDONLY);
//     fd_sam = open("sam.txt", O_RDONLY);

//     if (fd_sam == -1 || fd_sample == -1)
//     {
//         perror("open");
//         return (1);
//     }
//     i = 0;
//     printf("%d\n",fd_sample);
//     printf("%d\n",fd_sam);

//     line = get_next_line(fd_sample);
//     printf("sample:%s", line);
//     free(line);

//     line = get_next_line(fd_sample);
//     printf("sample:%s", line);
//     free(line);

//     line = get_next_line(fd_sam);
//     printf("sam   :%s", line);
//     free(line);

//     line = get_next_line(fd_sample);
//     printf("sample:%s", line);
//     free(line);

//     line = get_next_line(fd_sample);
//     printf("sample:%s", line);
//     free(line);

//     line = get_next_line(fd_sam);
//     printf("sam   :%s", line);
//     free(line);

//     line = get_next_line(fd_sample);
//     printf("sample:%s", line);
//     free(line);

//     line = get_next_line(fd_sam);
//     printf("sam   :%s", line);
//     free(line);

//     close(fd_sample);
//     close(fd_sam);
//     return (0);
// }
