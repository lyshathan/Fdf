/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:01:33 by lthan             #+#    #+#             */
/*   Updated: 2024/12/16 14:18:04 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./libft/ft_printf.h"
# include "./libft/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define RESET   "\033[0m"

# ifndef WIDTH
#  define WIDTH 1800
# endif

# ifndef HEIGHT
#  define HEIGHT 1500
# endif

# ifndef COLOR
#  define COLOR 0x0FFFFFF
# endif

# ifndef ESC_KEY
#  define ESC_KEY 65307
# endif

# ifndef UP
#  define UP 65362
# endif

# ifndef DOWN
#  define DOWN 65364
# endif

# ifndef LEFT
#  define LEFT 65361
# endif

# ifndef RIGHT
#  define RIGHT 65363
# endif

# ifndef PLUS
#  define PLUS 65451
# endif

# ifndef MINUS
#  define MINUS 65453
# endif

typedef struct s_map_info
{
	float	lowest_x;
	float	highest_x;
	float	lowest_y;
	float	highest_y;
	float	size_map_x;
	float	size_map_y;
}			t_map_info;

typedef struct s_point
{
	float	x;
	float	y;
	int		*z;
	int		col;
}			t_point;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_setup
{
	void	*mlx;
	void	*win;
	int		scale;
	float	shift_x;
	float	shift_y;
	float	h_z;
	t_point	**map;
	int		width;
	int		height;
	t_img	*img;
}			t_setup;

//UTILS
float	ft_abs(float nb);
void	*ft_free(void *data);
int		ft_convert_base_hexa(char *hexa);
char	**free_split(char **tab, size_t k);
char	**ft_split_set(char const *s, char *charset);
int		ft_count_line(char *filename);

//PARSE MAP
int		set_point(char *s, int index, int y, t_point *parse);
void	*free_parse_line(char **split, int len, t_point *parse_line, int i);
t_point	*allocate_parse_line(char **split, char *line, int *len);
int		fill_parse_line(char **split, int y, t_point *parse_line);
t_point	*ft_parse_line(int fd, int y);

//SET ISO
float	iso_x(t_setup stp, t_point point, int x, int y);
float	iso_y(t_setup stp, t_point point, int x, int y);
void	set_map_iso(t_setup stp, t_point **map);

//SET MAP INFO + SCALE + SHIFT
void	set_map_info(t_point **map, t_map_info *map_info);
void	find_scale(t_map_info map_info, t_setup *stp);
float	find_average_gap(t_point **map);

//DRAW GRID
void	draw_line(t_img *img, t_setup stp, t_point point_a, t_point point_b);
void	draw_grid(t_img *img, t_setup stp, t_point **map);

//DISPLAY IMAGE
void	put_pixel_to_image(t_img *img, int x, int y, int color);
void	print_image(t_setup *stp);

//HOOK
int		close_esc(int keycode, t_setup *stp);
int		close_cross(t_setup *stp);
int		mouse_zoom(int button, int x, int y, t_setup *stp);
int		key_hook(int keycode, t_setup *stp);

//CLEAR
void	*clear_all(t_point **map);
int		clear_ending(t_setup stp);

//FDF
int		fdf(char **arv);

#endif