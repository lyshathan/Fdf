/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:58:39 by ly-sha            #+#    #+#             */
/*   Updated: 2024/12/16 08:15:33 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

float	average_gap_x(t_point **map)
{
	float	av_gap;
	int		count;
	int		x;
	int		y;

	av_gap = 0;
	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x + 1].z)
		{
			if (ft_abs(*map[y][x].z - *map[y][x + 1].z) != 0)
			{
				av_gap = av_gap + ft_abs(*map[y][x].z - *map[y][x + 1].z);
				count++;
			}
			x++;
		}
		y++;
	}
	if (count == 0)
		return (1);
	return (av_gap / count);
}

float	average_gap_y(t_point **map, int count)
{
	float	av_gap;
	int		x;
	int		y;

	av_gap = 0;
	x = 0;
	y = 0;
	while (map[y][x].z)
	{
		y = 0;
		while (map[y + 1])
		{
			if (ft_abs(*map[y][x].z - *map[y + 1][x].z) != 0)
			{
				av_gap = av_gap + ft_abs(*map[y][x].z - *map[y + 1][x].z);
				count++;
			}
			y++;
		}
		x++;
	}
	if (count == 0)
		return (1);
	return (av_gap / count);
}

float	find_average_gap(t_point **map)
{
	float	av_gap;
	int		count;

	count = 0;
	av_gap = (average_gap_x(map) + average_gap_y(map, count)) / 2;
	return (av_gap);
}
