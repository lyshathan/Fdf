/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:01:33 by lthan             #+#    #+#             */
/*   Updated: 2024/12/13 18:29:43 by ly-sha           ###   ########.fr       */
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
# include <stdio.h>			////////////////////Caution!!!

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 700
# endif

# ifndef ESC_KEY
# define ESC_KEY 65307
# endif

# ifndef COLOR
# define COLOR 0x0FFFF00
# endif

typedef struct	s_map_info {
	float	lowest_x;
	float	highest_x;
	float	lowest_y;
	float	highest_y;
	float	size_map_x;
	float	size_map_y;
}				t_map_info;

typedef struct	s_point {
	float	x;
	float	y;
	int		*z;
	int		col;
}				t_point;

typedef struct s_setup {
	void	*mlx;
	void	*win;
	int		scale;
	float		shift_x;
	float		shift_y;
	float		h_z;
	t_point **map;
	int     width;
    int     height;
}				t_setup;

typedef struct s_img {
    void    *img_ptr;   // Pointer to the image
    char    *data;      // Pointer to the image data
    int     bpp;        // Bits per pixel
    int     size_line;  // Size of a line in bytes
    int     endian;     // Endianess
    int     width;      // Image width
    int     height;     // Image height
}               t_img;



void	put_pixel_to_image(t_img *img, int x, int y, int color);

//UTILS
float	ft_abs(float nb);
void	*ft_free(void *data);
int		ft_convert_base_hexa(char *hexa);

//PARSE MAP
int		ft_count_line(char *filename);
t_point *ft_parse_line(int fd, int y);
int		set_point(char *s, int index, int y, t_point *parse);
t_point **ft_parse_map(char *filename);

//SET ISO
float	iso_x(t_setup stp, t_point point, int x, int y);
float	iso_y(t_setup stp, t_point point, int x, int y);
void	set_map_iso(t_setup stp, t_point **map);

//DRAW GRID
void	draw_line(t_img *img, t_setup stp, t_point point_a, t_point point_b);
// void	draw_single_h(t_setup stp, t_point **map);
void	draw_grid(t_img *img, t_setup stp, t_point **map);

//SPLIT SET
char	**free_split(char **tab, size_t k);
char	**ft_split_set(char const *s, char *charset);

//PRINT COORDONATES
void	print_map(t_point **map);

//HOOK
int	close_esc(int keycode, t_setup *stp);
int	close_cross(t_setup *stp);

//SET MAP INFO + SCALE + SHIFT
void	set_map_info(t_point **map, t_map_info *map_info);
void	find_scale(t_map_info map_info, t_setup *stp);

//CLEAR
void	*clear_all(t_point **map);

#endif
