/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:01:33 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 15:09:50 by lthan            ###   ########.fr       */
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

# define ESC_KEY 65307

typedef struct	s_point {
	float	x;
	float	y;
	int		*z;
	int		color;
}				t_point;

typedef struct s_setup {
	void	*mlx;
	void	*win;
	int		scale;
	int		shift;
	int		h_z;
	t_point **map;
}				t_setup;

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

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
void	draw_line(t_setup stp, t_point point_a, t_point point_b);
void	draw_single_h(t_setup stp, t_point **map);
void	draw_grid(t_setup stp, t_point **map);

//SPLIT SET
char	**free_split(char **tab, size_t k);
char	**ft_split_set(char const *s, char *charset);

//PRINT COORDONATES
void	print_map(t_point **map);

//HOOK
int	close_esc(int keycode, t_setup *stp);
int	close_cross(t_setup *stp);

void	clear_all(t_point **map);

#endif