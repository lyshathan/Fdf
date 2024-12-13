/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:19:14 by lthan             #+#    #+#             */
/*   Updated: 2024/12/13 18:18:42 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initial_map_info(t_point **map, t_map_info *map_info)
{
	map_info->lowest_x = map[0][0].x;
	map_info->highest_x = map[0][0].x;
	map_info->lowest_y = map[0][0].y;
	map_info->highest_y = map[0][0].y;
}

void	set_map_info(t_point **map, t_map_info *map_info)
{
	int	x;
	int	y;

	initial_map_info(map, map_info);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			if (map[y][x].x < map_info->lowest_x)
				map_info->lowest_x = map[y][x].x;
			if (map[y][x].x > map_info->highest_x)
				map_info->highest_x = map[y][x].x;
			if (map[y][x].y < map_info->lowest_y)
				map_info->lowest_y = map[y][x].y;
			if (map[y][x].y > map_info->highest_y)
				map_info->highest_y = map[y][x].y;
			x++;
		}
		y++;
	}
	map_info->size_map_x = ft_abs(map_info->lowest_x - map_info->highest_x);
	map_info->size_map_y = ft_abs(map_info->lowest_y - map_info->highest_y);
}

void	find_scale(t_map_info map_info, t_setup *stp)
{
	int		scale;
	float	shift_neg_x;
	float	shift_neg_y;

	if (stp->width / map_info.size_map_x < stp->height / map_info.size_map_y)
		scale = stp->width * 0.9 / map_info.size_map_x;
	else
		scale = stp->height * 0.9 / map_info.size_map_y;
	stp->scale = scale;
	if (map_info.lowest_x < 0)
		shift_neg_x = ft_abs(map_info.lowest_x * stp->scale);
	else
		shift_neg_x = 0;
	if (map_info.lowest_y < 0)
		shift_neg_y = ft_abs(map_info.lowest_y * stp->scale);
	else
		shift_neg_y = 0;
	stp->shift_x = (stp->width
			- (map_info.size_map_x * stp->scale)) / 2 + shift_neg_x;
	stp->shift_y = (stp->height
			- (map_info.size_map_y * stp->scale)) / 2 + shift_neg_y;
}
