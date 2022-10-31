/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:26:31 by abkasmi           #+#    #+#             */
/*   Updated: 2022/10/28 07:48:44 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	get_shortest_dist(t_game *map, float angle)
{
	t_ray	rays[2];
	float	delta_angle;

	rays[0] = vertical_seeking(map, angle);
	rays[1] = horizontal_seeking(map, angle);
	if (rays[1].dist < rays[0].dist)
	{
		rays[0].pos[0] = rays[1].pos[0];
		rays[0].pos[1] = rays[1].pos[1];
		rays[0].dist = rays[1].dist;
	}
	delta_angle = map->perso.pa - angle;
	if (delta_angle < 0)
		delta_angle += 2 * PI;
	else if (delta_angle > 2 * PI)
		delta_angle -= 2 * PI;
	rays[0].dist = rays[0].dist * cos(delta_angle);
	return (rays[0]);
}

int	raycast(t_game *map)
{
	float	angle;
	t_ray	ray_struct;
	int		ray;

	ray = -1;
	angle = map->perso.pa - (DR * (int)(FOV / 2));
	while (ray++ < WIN_X)
	{
		ray_struct = get_shortest_dist(map, angle);
		draw_line(ray_struct, map, ray);
		angle += (DR * FOV) / WIN_X;
		if (angle < 0)
			angle += 2 * PI;
		if (angle > 2 * PI)
			angle -= 2 * PI;
	}
	mlx_clear_window(map->mlx, map->win);
	mlx_put_image_to_window(map->mlx, map->win, map->data.img, 0, 0);
	return (0);
}
