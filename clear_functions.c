/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:45:15 by lthan             #+#    #+#             */
/*   Updated: 2024/12/16 13:09:44 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*clear_all(t_point **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x].z)
		{
			free(map[y][x].z);
			x++;
		}
		ft_free(map[y]);
		y++;
	}
	ft_free(map);
	return (NULL);
}

int	clear_ending(t_setup stp)
{
	clear_all(stp.map);
	if (stp.win)
		mlx_destroy_window(stp.mlx, stp.win);
	if (stp.mlx)
		mlx_destroy_display(stp.mlx);
	free(stp.mlx);
	return (0);
}
