/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:43:45 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/13 15:21:04 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*buffer;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	if (check_n(stash))
		return (print_line(&stash));
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		stash = ft_strjoin_free(stash, buffer);
		if (check_n(stash))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&stash));
}
