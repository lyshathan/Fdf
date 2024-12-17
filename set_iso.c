/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:45:39 by lthan             #+#    #+#             */
/*   Updated: 2024/12/17 08:12:52 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	iso_x(t_setup stp, t_point point, int x, int y)
{
	float	dest_x;

	dest_x = (x * cos(stp.angle)) + (y * cos(stp.angle + 2))
		+ ((*(point.z) / stp.h_z) * cos(stp.angle - 2));
	return (dest_x);
}

float	iso_y(t_setup stp, t_point point, int x, int y)
{
	float	dest_y;

	dest_y = (x * sin(stp.angle)) + (y * sin(stp.angle + 2))
		+ ((*(point.z) / stp.h_z) * sin(stp.angle - 2));
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
