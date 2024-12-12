/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:46:30 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 16:58:54 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_img *img, t_setup stp, t_point point_a, t_point point_b)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;
	int		color;
	
	dx = point_b.x - point_a.x;
	dy = point_b.y - point_a.y;
	
	if (ft_abs(dx) >= ft_abs(dy))
		step = ft_abs(dx);
	else
		step = ft_abs(dy);
	step = step * stp.scale;
	
	dx = dx / step;
	dy = dy / step;


	x = point_a.x;
	y = point_a.y;

	float i = 1;
	while (i <= step)
	{
		color = 0x0FFFFFF;
		if (point_b.color)
			color = point_b.color;
		
		put_pixel_to_image(img, (x * stp.scale + stp.shift), (y * stp.scale + stp.shift), color);
		
		x = x + dx;
		y = y + dy;
		i++;
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
