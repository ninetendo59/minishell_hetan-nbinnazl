/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:53:34 by hetan             #+#    #+#             */
/*   Updated: 2024/01/03 02:59:20 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	free_storage()
	purpose: to free the memory for unused memory
	
	implementation reasoning:
	1. Safe way to free memory that has been allocated dynamically.
	2. Could avoid dangling pointer.
*/
char	*free_storage(char **storage)
{
	free(*storage);
	*storage = NULL;
	return (NULL);
}

/*
	ft_store_data()
	purpose: to do some cleanup after the get_line used the storage to gnl

	implementation reasoning:
	let's say we have these strings "abc\ndef", from the ft_get_line already
	read the string "abc\n", this function is to exclude the "abc\n" and hence
	will return "def" by using ft_substr. the reason why i don't use ft_strtrim
	is because it might cause buffer overflow and exceed the line based on
	norm v4 rule.
	Moreover, substr is way more easier than using ft_strtrim and make the code
	looks mere cleaner.
*/
char	*ft_store_data(char *storage)
{
	char	*new;
	char	*strchr_nl;
	size_t	line_len;
	size_t	stor_len;

	strchr_nl = gnl_strchr(storage, '\n');
	if (!strchr_nl)
	{
		new = NULL;
		return (free_storage(&storage));
	}
	else
		line_len = (size_t)(strchr_nl - storage) + 1;
	if (!*(storage + line_len))
		return (free_storage (&storage));
	stor_len = ft_strlen(storage) - line_len;
	new = gnl_substr(storage, line_len, stor_len);
	free_storage(&storage);
	if (!new)
		return (NULL);
	return (new);
}

/*
	ft_get_line
	purpose: to get the fd until the next line

	reasoning implementation:
	after read the fd in ft_get_fd, there might have chance that there might
	have \n in the storage. basically ft_strchr does not store any data,
	instead it will return the mem address and points the last mem position of
	the storage at \n, which gaining the exact number of character need to be
	extracted from storage include the \n and terminate 0 when finished.
	that's where substr came handy :D
*/
char	*ft_get_line(char *storage)
{
	char	*line;
	char	*strchr_nl;
	size_t	line_len;

	strchr_nl = gnl_strchr(storage, '\n');
	line_len = (size_t)(strchr_nl - storage) + 1;
	line = gnl_substr(storage, 0, line_len);
	if (!line)
		return (NULL);
	return (line);
}

/*
	ft_get_fd()
	purpose: to read the fd that has been opened until \n is met in
			 the buffer
	
	implementation reasoning:
	I bet everyone implement almost the same. but mine slightly different.
	as you can see i strchr on buffer instead of storage because there is
	possibilities that the storage is not initialise and might poses
	undefined behavior such as uninitialised/ invalid error from valgrind.
	why i free storage when rd is < 0 because to handle any read errors 
	that occur after it starts reading from a valid fd.
*/
char	*ft_get_fd(char *storage, int fd)
{
	char	*buffer;
	int		rd;

	buffer = malloc (sizeof(*buffer) * ((long int)BUFFER_SIZE + 1));
	if (!buffer)
		return (free_storage (&storage));
	*buffer = '\0';
	rd = 1;
	while (rd > 0 && !(gnl_strchr(buffer, '\n')))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd > 0)
		{
			*(buffer + rd) = '\0';
			storage = gnl_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (rd < 0)
		return (free_storage (&storage));
	return (storage);
}

/*
	get_next_line
	purpose: the main purpose of the function which reads the fd
			 before it reaches the new line or \0 and return
			 as string.

	Implementation reasoning:
	the line assigned ft_get_fd into storage, basically it ensures 
	there must be no '\n in storage even in our function already
	made the storage should not contain \n initially in ft_store_data
	if the line is NULL, then it will clear the storage as it might
	contain some values in there and ensures all possible leaks
	has been free and no dangling pointers exists.
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage[MAX_FD];

	if (fd < 0)
		return (NULL);
	if (!storage[fd] || (storage[fd] && !ft_strchr (storage[fd], '\n')))
		storage[fd] = ft_get_fd(storage[fd], fd);
	if (!storage[fd])
		return (NULL);
	line = ft_get_line (storage[fd]);
	if (!line)
		return (free_storage (&storage[fd]));
	storage[fd] = ft_store_data (storage[fd]);
	return (line);
}
