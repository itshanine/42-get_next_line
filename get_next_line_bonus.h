/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjebou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:49:11 by hanjebou          #+#    #+#             */
/*   Updated: 2023/10/14 14:21:42 by hanjebou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

//get_next_line_utils
int		ft_strlen(char *s);
char	*ft_strdup(char *s, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*print_line(char **stash);

//get_next_line
int		check_n(char *s);
char	*get_next_line(int fd);

#endif
