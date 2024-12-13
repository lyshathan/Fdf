/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:13:07 by lthan             #+#    #+#             */
/*   Updated: 2024/12/13 17:58:03 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_point **map)
{
	int x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			printf("%f|", map[y][x].y);
			printf("%f	", map[y][x].x);
			// ft_printf("%d	", *(map[y][x].z));
			// ft_printf("%d	", map[y][x].col);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
