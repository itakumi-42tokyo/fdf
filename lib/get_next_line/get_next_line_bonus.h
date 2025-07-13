/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:00:12 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/14 19:40:43 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef NUMBER_FD
#  define NUMBER_FD 1024
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

char	*move_next(char *res);
char	*extract_line(char *res);
char	*join_and_free(char *res, char *buffer);
char	*read_file(int fd, char **res);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
void	ft_bzero(char *s, size_t n);
char	*ft_calloc(size_t nmnb, size_t size);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif
