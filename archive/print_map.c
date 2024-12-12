/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:13:07 by lthan             #+#    #+#             */
/*   Updated: 2024/12/12 13:11:13 by lthan            ###   ########.fr       */
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
			// printf("%f|", map[y][x].y);
			// printf("%f	", map[y][x].x);
			// ft_printf("%d	", *(map[y][x].z));
			ft_printf("%d	", map[y][x].color);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}