/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:45:39 by lthan             #+#    #+#             */
/*   Updated: 2024/12/14 14:45:55 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	iso_x(t_setup stp, t_point point, int x, int y)
{
	float	dest_x;
	double	angle;

	angle = 120;
	dest_x = (x * cos(angle)) + (y * cos(angle + 2))
		+ ((*(point.z) / stp.h_z) * cos(angle - 2));
	return (dest_x);
}

float	iso_y(t_setup stp, t_point point, int x, int y)
{
	float	dest_y;
	double	angle;

	angle = 120;
	dest_y = (x * sin(angle)) + (y * sin(angle + 2))
		+ ((*(point.z) / stp.h_z) * sin(angle - 2));
	return (dest_y);
}

void	set_map_iso(t_setup stp, t_point **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			map[y][x].x = iso_x(stp, map[y][x], x, y);
			map[y][x].y = iso_y(stp, map[y][x], x, y);
			x++;
		}
		y++;
	}
}
