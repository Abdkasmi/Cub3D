/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_seeking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 07:47:02 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 07:47:40 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "type_definition.h"

t_ray	find_v_dist(t_game *map, float delta[2], t_ray ray, float angle)
{
	float	dist;
	int		pos[2];

	dist = 0;
	while (dist < DOF)
	{
		pos[0] = ray.pos[0];
		pos[1] = ray.pos[1];
		if (angle > PI / 2 && angle < PI + (PI / 2))
			pos[0]--;
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

t_ray	vertical_seeking(t_game *map, float angle)
{
	float	delta[2];
	t_ray	ray;
	float	atan;

	atan = -tan(angle);
	ray.pos[0] = map->perso.p_x;
	ray.pos[1] = map->perso.p_y;
	ray.dist = 1000000;
	if (angle > PI / 2 && angle < PI + (PI / 2))
	{
		ray.pos[0] = (int)map->perso.p_x;
		delta[0] = -1;
		delta[1] = -delta[0] * atan;
	}
	else if (angle < PI / 2 || angle > PI + (PI / 2))
	{
		ray.pos[0] = (int)map->perso.p_x + 1;
		delta[0] = 1;
		delta[1] = -delta[0] * atan;
	}
	else
		return (ray);
	ray.pos[1] = (map->perso.p_x - ray.pos[0]) * atan + map->perso.p_y;
	return (find_v_dist(map, delta, ray, angle));
}
