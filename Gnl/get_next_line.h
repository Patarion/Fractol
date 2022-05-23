/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:11:34 by jgagnon           #+#    #+#             */
/*   Updated: 2022/03/08 16:34:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_bufdup(const char *s);
int		ft_strlen(const char *str);
char	*ft_strconcatenate(const char *s1, const char *s2);
char	*ft_subbuf(const char *s);
int		ft_findreturn(const char *s);
char	*ft_bufbeg(const char *s, int end);
char	*ft_lecture(int fd, char *buffer);

#endif
