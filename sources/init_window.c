/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:47:05 by abkasmi           #+#    #+#             */
/*   Updated: 2022/10/23 13:39:43 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*init_window_mlx(t_game *map)
{
	void	*win;

	win = mlx_new_window(map->mlx, WIN_X, WIN_Y, "solong");
	if (!win)
		return (0);
	return (win);
}
