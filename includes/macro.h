/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:20:55 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/16 23:20:56 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

// Error messege
# define SYNTAX_ERROR "Usage: ./fdf <filename>\n"
# define MALLOC_ERROR "malloc error\n"
# define MAP_READ_ERROR "map read error\n"
# define FAILED_MLX_INIT "failed mix_init\n"
# define FAILED_MLX_WIN "failed mlx_window\n"
# define FAILED_MLX_IMG "failed mlx_img\n"
# define FAILED_MLX_DATA_ADDR "failed mlx_data_addr\n"
# define ERROR_PROJ_MACRO "error: PROJ macro is incorrect\n"
# define ERROR_KEY "Error: the key is not supported.\n"
# define TRANSLATE "translate!!\n"
# define RESET_RENDER "View reset to default.\n"
# define MOUSE_LEFT_BUTTON "mouse_left_button\n"
# define MOUSE_MIDDLE_BUTTON "mouse_middle_button\n"
# define MOUSE_RIGHT_BUTTON "mouse_right_button\n"
# define MOUSE_RELEASE "mouse_button is release\n"

// keycode
# define ESC_MACOS 53
# define ESC_LINUX 65307
# define X_MACOS 7
# define X_LINUX 120
# define R_LINUX 114
# define W_LINUX 119
# define A_LINUX 97
# define S_LINUX 115
# define D_LINUX 100
# define CURSOR_UP_LINUX 65362
# define CURSOR_DOWN_LINUX 65364
# define CURSOR_LEFT_LINUX 65361
# define CURSOR_RIGHT_LINUX 65363

// window size
# define DEFAULT_WIN_SIZE_X 1000
# define DEFAULT_WIN_SIZE_Y 1000

// title
# define DEFAULT_TITLE "FDF"
# define CORRECT_FILE_EXTENSION ".fdf"

// buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

// π
# ifndef M_PI
#  define M_PI 3.14159265359
# endif

// cos
# define COS_MINUS_45 0.707107
# define COS_MINUS_300 0.866025403784438646763723170752936183471402626
# define COS_30 0.866025403784438646763723170752936183471402626
# define COS_45 0.707107

// sin
# define SIN_MINUS_45 -0.707107
# define SIN_MINUS_30 -0.500000
# define SIN_30 0.500000
# define SIN_45 0.707107

// sqrt
# define SQRT_2 1.41421356237

// separate chars
# define SEP " \t\n"

// color information in map
# ifndef COLOR_INFO
#  define COLOR_INFO "0x"
# endif

// hexadecimal table
# ifndef HEX_TABLE
#  define HEX_TABLE "0123456789ABCDEF"
# endif

// projection select
# define ISO 0
# define PERSP 1
// PROJはMakefileから渡される

# ifndef PROJ
#  define PROJ ISO
# endif

# define ZOOM_MIN 0.1
# define ZOOM_MAX 10.0

# ifndef FLT_MAX
#  define FLT_MAX 3.40282347e+38F
# endif

#endif
