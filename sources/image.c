/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:25:55 by abkasmi           #+#    #+#             */
/*   Updated: 2022/10/28 05:51:12 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "type_definition.h"

int	compare(float a, float b)
{
	float	precision;

	precision = 0.001;
	if (a > b - precision && a < b + precision)
		return (1);
	return (0);
}

void	*new_img(t_game *map)
{
	void	*img;

	img = mlx_new_image(map->mlx, WIN_X, WIN_Y);
	if (!img)
		exit_free(map);
	map->data.addr = mlx_get_data_addr(img, &map->data.bpp, &map->data.l_l,
			&map->data.endian);
	if (!map->data.addr)
		exit_free(map);
	return (img);
}
