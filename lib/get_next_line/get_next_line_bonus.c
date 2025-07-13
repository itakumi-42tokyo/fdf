/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:00:15 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/16 14:57:59 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*move_next(char *stuck)
{
	size_t	i;
	size_t	j;
	char	*next;

	i = 0;
	while (stuck[i] && stuck[i] != '\n')
		i++;
	if (!stuck[i])
	{
		free(stuck);
		return (stuck = NULL, NULL);
	}
	i++;
	next = ft_calloc((ft_strlen(stuck) - i + 1), sizeof(char));
	if (!next)
	{
		free(stuck);
		return (stuck = NULL, NULL);
	}
	j = 0;
	while (stuck[i])
		next[j++] = stuck[i++];
	next[j] = '\0';
	free(stuck);
	return (stuck = NULL, next);
}

char	*extract_line(char *stuck)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stuck[i])
		return (NULL);
	while (stuck[i] && stuck[i] != '\n')
		i++;
	if (stuck[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stuck[i] && stuck[i] != '\n')
	{
		line[i] = stuck[i];
		i++;
	}
	if (stuck[i] && stuck[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*join_and_free(char *stuck, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stuck, buffer);
	free(stuck);
	stuck = NULL;
	return (tmp);
}

char	*read_file(int fd, char **stuck)
{
	char		*buffer;
	ssize_t		read_bytes;

	if (!*stuck)
	{
		*stuck = ft_calloc(1, 1);
		if (!*stuck)
			return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_strchr(buffer, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(*stuck), *stuck = NULL, NULL);
		buffer[read_bytes] = 0;
		*stuck = join_and_free(*stuck, buffer);
		if (!*stuck)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (*stuck);
}

char	*get_next_line(int fd)
{
	static char		*stuck[NUMBER_FD] = {NULL};
	char			*tmp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || NUMBER_FD <= 0)
		return (NULL);
	tmp = read_file(fd, &stuck[fd]);
	if (!tmp || !*tmp)
	{
		free(stuck[fd]);
		stuck[fd] = NULL;
		return (NULL);
	}
	line = extract_line(tmp);
	if (!line)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	stuck[fd] = move_next(tmp);
	return (line);
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int	resume_flag = 0;
// 	char *res = NULL;
// 	int i = 0;
// 	int the_number_of_fd = 6;
// 	int	fd[the_number_of_fd];
// 	fd[0] = open("textsorce/Africa.txt", O_RDONLY);
// 	if (fd[0] == -1)
// 		return (1);
// 	fd[1] = open("textsorce/Asia.txt", O_RDONLY);
// 	if (fd[1] == -1)
// 		return (1);
// 	fd[2] = open("textsorce/Europe.txt", O_RDONLY);
// 	if (fd[2] == -1)
// 		return (1);
// 	fd[3] = open("textsorce/NorthAmerica.txt", O_RDONLY);
// 	if (fd[3] == -1)
// 		return (1);
// 	fd[4] = open("textsorce/Oceania.txt", O_RDONLY);
// 	if (fd[4] == -1)
// 		return (1);
// 	fd[5] = open("textsorce/SouthAmerica.txt", O_RDONLY);
// 	if (fd[5] == -1)
// 		return (1);
// 	while (1)
// 	{
// 		i = 0;
// 		resume_flag = 0;
// 		while (i < the_number_of_fd)
// 		{
// 			res = get_next_line(fd[i]);
// 			if (res)
// 			{
// 				resume_flag = 1;
// 				printf("%s", res);
// 				free(res);
// 			}
// 			i++;
// 		}
// 		if (resume_flag == 0)
// 			break;
// 	}
// 	i = 0;
// 	while (i < the_number_of_fd)
// 	{
// 		close(fd[i]);
// 		i++;
// 	}
// 	return (0);
// }
