/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:59:19 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/17 21:35:41 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "macro.h"
#include "libft.h"
#include "utils.h"
#include <fcntl.h>
#include <stddef.h>

//　改行ごとにチェックする関数にするべきか？
int	parse_token(t_point **map, char **tokens, int y)
{
	int	i;

	if (map == NULL || tokens == NULL)
		return (-1);
	i = 0;
	while (tokens[i] != NULL)
	{
		map[i] = malloc(sizeof(t_point));
		if (map[i] == NULL)
		{
			free_2d((void **)map);
			return (-1);
		}
		map[y][i]->x = i;
	}
}

t_control *parse_map(int fd)
{
	t_point	**map;
	char 	**tokens;
	char	*line;
	int		y;

	map = malloc(sizeof(t_point *) * MAP_SIZE_Y);
	if (map == NULL)
		return (NULL);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		// ここでlineを解析して、必要な情報を抽出する
		// 例えば、空白で区切られた整数を取得するなど
		tokens = ft_split(line, ' ');
		if (tokens == NULL)
			return (free(line), free_2d((void **)map), NULL);
		if (parse_tokens(map, tokens, y) == -1)
			return (free(line), free_2d((void **)tokens), free_2d((void **)map), NULL);
		// 解析後はlineを解放する
		free_2d((void **)tokens);
		free(line);
		y++;
	}
	return (map);
}

t_control	*read_map(char *file_path)
{
	t_point	**map;
	int		fd;


	if (file_path == NULL)
		return (-1);
	fd = open(file_path, O_RDONLY | __O_CLOEXEC);
	if (fd == -1)
	{
		perror(file_path);
		return (-1);
	}
	map = parse_map(fd);
	if (map == NULL)
	{
		close(fd);
		return (-1);
	}
}
