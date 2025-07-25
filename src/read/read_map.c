/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:59:19 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/23 14:21:07 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <fcntl.h>
#include <stddef.h>
#include "get_next_line.h"
#include "struct.h"
#include "macro.h"
#include "utils.h"


// 16進数にも対応させないといけない
//　改行ごとにチェックする関数にするべきか？
int	parse_tokens(t_point **map, char **tokens, const int y, const int width)
{
	int		i;
	bool	error;

	if (map == NULL || tokens == NULL)
		return (-1);
	map[y] = malloc(sizeof(t_point) * (width));
	if (map[y] == NULL)
		return (-1);
	error = false;
	i = 0;
	int count = 0;
	while (tokens[i] != NULL)
	{
		(map[y][i]).x = i;
		(map[y][i]).y = y;
		(map[y][i]).z = ut_atoi_with_error(tokens[i], &error);
		if (error == true)
			return (-1);
		i++;
	}
	return (0);
}
// 整数はどの型までを許容するか？　整数で来ない場合もあるのかな？
// ut_atoi_with_errorは、数字以外が入力されているときも反応する。


// ここでlineを解析して、必要な情報を抽出する
// 例えば、空白で区切られた整数を取得するなど
// 解析後はlineを解放する
// width + 1 にしなくてもよいのかな？
t_point **parse_map(int fd, int width, int height)
{
	t_point	**map;
	char 	**tokens;
	char	*line;
	int		y;

	map = malloc(sizeof(t_point *) * (height + 1));
	if (map == NULL)
		return (NULL);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		tokens = ut_split(line, SEP);
		if (tokens == NULL)
			return (free(line), free_2d((void **)map), NULL);
		if (parse_tokens(map, tokens, y, width) == -1)
			return (free(line), free_2d((void **)tokens), free_2d((void **)map), NULL);
		(free(line), free_2d((void **)tokens));
		y++;
	}
	map[y] = NULL;
	return (map);
}

// TODO
// FIXME
// XXX
// 改行の数で、heightを決定してもよいのだろうか？
// lseekを使用しない限り、openは２回必要になると思われる.
int	calc_map_size(t_control *control, char *file_path)
{
	int		fd;
	char	*line;
	char	buffer[BUFFER_SIZE];
	ssize_t	read_bytes;

	if (control == NULL || file_path == NULL)
		return (-1);
	fd = open(file_path, O_RDONLY | __O_CLOEXEC);
	if (fd == -1)
		return (perror(file_path), -1);
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), -1);
	control->map_width = ut_count_words(line);
	control->map_height += 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
		control->map_height += 1;
	}
	return (close(fd), 0);
}
// 改行だけでheightを確認するのは怪しいので、他の方法はないかな？
// １．数字の直後の改行を見て、判断する。
// ２．

t_point	**read_map(t_control *control, char *file_path)
{
	t_point		**map;
	int			fd;

	if (file_path == NULL)
		return (NULL);
	if (calc_map_size(control, file_path) == -1)
		return (NULL);
	fd = open(file_path, O_RDONLY | __O_CLOEXEC);
	if (fd == -1)
	{
		perror(file_path);
		return (NULL);
	}
	map = parse_map(fd, control->map_width, control->map_height);
	if (map == NULL)
	{
		close(fd);
		return (NULL);
	}
	// read_map.c の read_map 関数の最後に追加
// ...
printf("--- Step 1: Map Read Check ---\n");
printf("Map[0][0] -> x:%d, y:%d, z:%d\n", map[0][0].x, map[0][0].y, map[0][0].z);
printf("Last Point -> x:%d, y:%d, z:%d\n", map[control->map_height - 1][control->map_width - 1].x, map[control->map_height - 1][control->map_width - 1].y, map[control->map_height - 1][control->map_width - 1].z);
	close(fd);
	return (map);
}
