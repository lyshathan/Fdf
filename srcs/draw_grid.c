/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:46:30 by lthan             #+#    #+#             */
/*   Updated: 2024/12/16 16:16:00 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	calcul_draw_line(t_setup stp, t_point p1, t_point p2)
{
	float	step;

	if (ft_abs(p2.x - p1.x) >= ft_abs(p2.y - p1.y))
		step = ft_abs(p2.x - p1.x);
	else
		step = ft_abs(p2.y - p1.y);
	step = step * stp.scale;
	return (step);
}

void	draw_line(t_img *img, t_setup stp, t_point p1, t_point p2)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;

	step = calcul_draw_line(stp, p1, p2);
	dx = (p2.x - p1.x) / step;
	dy = (p2.y - p1.y) / step;
	x = p1.x;
	y = p1.y;
	while (step > 0)
	{
		if (p2.col)
			put_pixel_to_image(img, (x * stp.scale + stp.shift_x),
				(y * stp.scale + stp.shift_y), p2.col);
		else
			put_pixel_to_image(img, (x * stp.scale + stp.shift_x),
				(y * stp.scale + stp.shift_y), COLOR);
		x = x + dx;
		y = y + dy;
		step--;
	}
}

void	draw_grid(t_img *img, t_setup stp, t_point **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x + 1].z)
		{
			draw_line(img, stp, map[y][x], map[y][x + 1]);
			if (map[y + 1])
			{
				draw_line(img, stp, map[y][x], map[y + 1][x]);
			}
			x++;
		}
		if (map[y + 1])
		{
			draw_line(img, stp, map[y][x], map[y + 1][x]);
		}
		y++;
	}
}
