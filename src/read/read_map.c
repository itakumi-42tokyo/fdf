/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:59:19 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 21:11:03 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "macro.h"
#include "libft.h"
#include "utils.h"
#include <fcntl.h>
#include <stddef.h>

// 16進数にも対応させないといけない
//　改行ごとにチェックする関数にするべきか？
int	parse_token(t_point **map, char **tokens, const int y, const int width)
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
	while (tokens[i] != NULL)
	{
		(map[y][i]).x = i;
		(map[y][i]).y = y;
		(map[y][i]).z = ut_atoi_with_error(tokens[i], &error);
		if (error == true)
			return (-1);
		i++;
	}
}
// 整数はどの型までを許容するか？　整数で来ない場合もあるのかな？
// ut_atoi_with_errorは、数字以外が入力されているときも反応する。


// ここでlineを解析して、必要な情報を抽出する
// 例えば、空白で区切られた整数を取得するなど
// 解析後はlineを解放する
t_point *parse_map(int fd, int width, int height)
{
	t_point	**map;
	char 	**tokens;
	char	*line;
	int		y;

	map = malloc(sizeof(t_point *) * (width + 1));
	if (map == NULL)
		return (NULL);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		tokens = ft_split(line, ' ');
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
	free(line);
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (perror(file_path), close(fd), -1);
		else if (read_bytes == 0)
			break;
		control->map_height += ut_count_target(buffer, '\n');
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
	control->map_width = 0;
	control->map_height = 0;
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
	close(fd);
	return (map);
}
