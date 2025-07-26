/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:00:52 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 10:12:00 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_isometric
{
	double	iso_x;
	double	iso_y;
	int		color;
}	t_isometric;

typedef struct s_perspective
{
	double	persp_x;
	double	persp_y;
	int		color;
}	t_perspective;

// scale前とscale後のマップはどちらも保持したほうが良いか？
// mapはおそらく方形と捉えて良さそう。
typedef struct s_control
{
	void			*mlx;
	void			*win;
	void			*img;
	int				win_size_x;
	int				win_size_y;
	char			*title;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*data_addr;
	t_point			**map; // 2D配列のポインタ
	t_isometric		**iso_map; // 2D配列のポインタ
	int				iso_min_x0_y1[2];
	int				iso_max_x0_y1[2];
	t_perspective	**persp_map; // 2D配列のポインタ
	int				map_width; // マップの幅
	int				map_height; // マップの高さ
	int				offset_x;
	int				offset_y;
	double			scale;
}	t_control;

#endif
