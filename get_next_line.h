/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:09:13 by jgravalo          #+#    #+#             */
/*   Updated: 2025/02/06 18:10:22 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t			ft_strlen(char *str);

char			*ft_strchr(char *text, int c);

char			*ft_strjoin(char *s1, char *s2);

char			*maketext(char *text, int fd);

char			*makeline(char *text);

char			*modifytext(char *text);

char			*get_next_line(int fd);

#endif
