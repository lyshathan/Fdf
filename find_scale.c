/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:19:14 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 17:59:32 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_scale(t_point **map, t_setup *stp)
{
	int		x;
	int		y;
	float	lowest_x;
	float	highest_x;
	float	lowest_y;
	float	highest_y;
	int		scale;

	lowest_x = map[0][0].x;
	highest_x = map[0][0].x;
	lowest_y = map[0][0].y;
	highest_y = map[0][0].y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			if (map[y][x].x < lowest_x)
				lowest_x = map[y][x].x;
			if (map[y][x].x > highest_x)
				highest_x = map[y][x].x;
			if (map[y][x].y < lowest_y)
				lowest_y = map[y][x].y;
			if (map[y][x].y > highest_y)
				highest_y = map[y][x].y;
			x++;
		}
		y++;
	}
	printf ("\n");
	printf(RED"lowest x = %f	|| highest x = %f	|| size max x = %f\n", lowest_x, highest_x, (ft_abs(lowest_x - highest_x)));
	printf("lowest y = %f	|| highest y = %f	|| size max y = %f\n"RESET, lowest_y, highest_y, (ft_abs(lowest_y - highest_y)));


	if (stp->width / ft_abs(lowest_x - highest_x) < stp->height / ft_abs(lowest_y - highest_y))
		scale = stp->width * 0.8 / ft_abs(lowest_x - highest_x);
	else
		scale = stp->height * 0.8 / ft_abs(lowest_y - highest_y);

	printf("SCALE = %d\n", scale);
	stp->scale = scale;
}

// int	find_shift_x(t_point **map, t_setup stp)
// {
	
// }