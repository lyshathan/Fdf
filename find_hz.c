/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:58:39 by ly-sha            #+#    #+#             */
/*   Updated: 2024/12/15 20:48:50 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

float	find_average_gap(t_point **map)
{
	float	current_gap;
	float	av_gap;
	int		count;
	int	x;
	int	y;

	av_gap = 0;
	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x + 1].z)
		{
			current_gap = ft_abs(*map[y][x].z - *map[y][x + 1].z);
			// printf("y = %d, x = %d, current gap = %f\n", y, x, current_gap);
			if (current_gap != 0)
			{
				av_gap = av_gap + current_gap;
				count++;
			}
			x++;
		}
		y++;
	}
	if (count == 0)
		return (1);
	av_gap = av_gap / count;
	printf("average gap = %f\n", av_gap);
	return (av_gap);
}


