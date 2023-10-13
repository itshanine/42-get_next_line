/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:44:05 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/13 15:21:21 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s, int len)
{
	char	*s_dup;
	int		count;

	if (!s || !len)
		return (NULL);
	s_dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!s_dup)
		return (NULL);
	count = -1;
	while (++count < len)
		s_dup[count] = s[count];
	s_dup[count] = '\0';
	return (s_dup);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*s_join;

	i = 0;
	len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2, len));
	len = len + ft_strlen(s1);
	s_join = (char *)malloc(sizeof(char) * (len + 1));
	if (!s_join)
		return (NULL);
	len = 0;
	while (s1[i])
		s_join[len++] = s1[i++];
	i = 0;
	while (s2[i])
		s_join[len++] = s2[i++];
	s_join[len] = '\0';
	free(s1);
	return (s_join);
}

char	*print_line(char **stash)
{
	int		n_pos;
	char	*line;
	char	*s;

	if (!*stash)
		return (NULL);
	s = *stash;
	n_pos = 0;
	while (s[n_pos] && s[n_pos] != '\n')
		n_pos++;
	if (s[n_pos] == '\n')
		n_pos++;
	line = ft_strdup(s, n_pos);
	*stash = ft_strdup(s + n_pos, ft_strlen(s + n_pos));
	if (s)
		free(s);
	s = NULL;
	return (line);
}
