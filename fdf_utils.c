/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:47:40 by lthan             #+#    #+#             */
/*   Updated: 2024/12/11 17:34:10 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	iso_x(t_point point, int x, int y)
{
	int		dest_x;
	double	angle;

	angle = 120;
	dest_x = (x * cos(angle)) + (y * cos(angle + 2)) + ((*(point.z) / 2) * cos(angle - 2));
	return (dest_x);
}

int	iso_y(t_point point, int x, int y)
{
	int		dest_y;
	double	angle;

	angle = 120;
	dest_y = (x * sin(angle)) + (y * sin(angle + 2)) + ((*(point.z) / 2) * sin(angle - 2));
	return (dest_y);
}

void	draw_line(void *mlx, void *mlx_win, int shift, t_point point_a, t_point point_b)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;

	ft_printf("--> point_a x = %d | point_a y = %d\n",point_a.x, point_a.y);
	ft_printf("--> point_b x = %d | point_b y = %d\n\n",point_b.x, point_b.y);
	
	dx = ft_abs(point_b.x) - ft_abs(point_a.x);
	dy = ft_abs(point_b.y) - ft_abs(point_a.y);
	
	if (dx >= dy)
		step = dx;
	else
		step = dy;
	printf("==> dx = %f | dy = %f | step = %f\n",dx, dy, step);
	
	dx = dx / step;
	dy = dy / step;

	
	
	x = point_a.x;
	y = point_a.y;

	printf("point de depart = %f, %f || step = %f | dx = %f | dy = %f\n", x, y, step, dx, dy);

	(void)shift;
	// (void)mlx;
	// (void)mlx_win;
	float i = 1;
	while (i <= step)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x0FFE600);
		x = x + dx;
		y = y + dy;
		i++;
	}
}

// void	draw_line(void *mlx, void *mlx_win, int shift, t_point point_a, t_point point_b)
// {
// 	float	 x;
// 	float	y;
// 	float	dx;
// 	float	dy;
// 	int	step;

// 	dx = ft_abs(iso_x(point_b)) - ft_abs(iso_x(point_a));
// 	dy = ft_abs(iso_y(point_b)) - ft_abs(iso_y(point_a));
// 	ft_printf("==> dx = %f | dy = %f\n",dx, dy);
	
// 	if (dx >= dy)
// 		step = dx;
// 	else
// 		step = dy;
	
// 	dx = dx / step;
// 	dy = dy / step;
// 	ft_printf("step = %d | dx = %f | dy = %f\n", step, dx, dy);
	
// 	x = iso_x(point_a);
// 	y = iso_y(point_a);
	
// 	// (void)shift;
// 	// (void)mlx;
// 	// (void)mlx_win;
// 	while (step > 0)
// 	{
// 		mlx_pixel_put(mlx, mlx_win, (x * 20 + shift), (y * 20 + shift), 0x0FF00FF);
// 		x = x + dx;
// 		y = y + dy;
// 		step--;
// 	}
// }
