/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:01:33 by lthan             #+#    #+#             */
/*   Updated: 2024/12/11 17:28:30 by lthan            ###   ########.fr       */
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

typedef struct	s_point {
	int		x;
	int		y;
	int		*z;
	char	*color;
}				t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int		iso_y(t_point point, int x, int y);
int		iso_x(t_point point, int x, int y);
void	draw_line(void *mlx, void *mlx_win, int shift, t_point point_a, t_point point_b);
char	**ft_split_set(char const *s, char *charset);
void	print_map(t_point **map);

#endif