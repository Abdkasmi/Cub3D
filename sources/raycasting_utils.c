/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:55:22 by abkasmi           #+#    #+#             */
/*   Updated: 2022/10/28 07:40:13 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "type_definition.h"

float	distance(double x_a, double y_a, double x_b, double y_b)
{
	return (sqrt(pow(x_b - x_a, 2) + pow(y_b - y_a, 2)));
}

float	map_size(t_game *map)
{
	return (map->size[0] * map->size[1]);
}
