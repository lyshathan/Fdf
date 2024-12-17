/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:58:39 by ly-sha            #+#    #+#             */
/*   Updated: 2024/12/17 08:40:51 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

float	find_average_gap(t_point **map)
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

