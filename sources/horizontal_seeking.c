/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_seeking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 07:47:02 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 09:55:32 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "type_definition.h"

t_ray	find_h_dist(t_game *map, float delta[2], t_ray ray, float angle)
{
	float	dist;
	int		pos[2];

	dist = 0;
	while (dist < DOF)
	{
		pos[0] = ray.pos[0];
		pos[1] = ray.pos[1];
		if (PI < angle)
			pos[1]--;
		dist = distance(map->perso.p_x, map->perso.p_y, ray.pos[0], ray.pos[1]);
		if (pos[0] >= 0 && pos[0] < map->size[1] && pos[1] >= 0
			&& pos[1] < map->size[0] && map->map[pos[1]][pos[0]] == '1')
		{
			ray.dist = dist;
			break ;
		}
		ray.pos[0] += delta[0];
		ray.pos[1] += delta[1];
	}
	return (ray);
}

t_ray	horizontal_seeking(t_game *map, float angle)
{
	float	delta[2];
	t_ray	ray;
	float	atan;

	atan = -1 / tan(angle);
	ray.pos[0] = map->perso.p_x;
	ray.pos[1] = map->perso.p_y;
	ray.dist = 1000000;
	if (PI < angle)
	{
		ray.pos[1] = (int)map->perso.p_y;
		delta[1] = -1;
		delta[0] = -delta[1] * atan;
	}
	else if (angle < PI)
	{
		ray.pos[1] = (int)map->perso.p_y + 1;
		delta[1] = 1;
		delta[0] = -delta[1] * atan;
	}
	else
		return (ray);
	ray.pos[0] = (map->perso.p_y - ray.pos[1]) * atan + map->perso.p_x;
	return (find_h_dist(map, delta, ray, angle));
}
