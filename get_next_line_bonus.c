/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:43:45 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/14 15:31:01 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	if (check_n(stash[fd]))
		return (print_line(&stash[fd]));
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		stash[fd] = ft_strjoin(stash[fd], buffer);
		if (check_n(stash[fd]))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&stash[fd]));
}
