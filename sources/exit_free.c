/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:47:02 by abkasmi           #+#    #+#             */
/*   Updated: 2022/10/28 10:48:05 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "type_definition.h"

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	free_map(t_game *game)
{
	int	index;

	index = game->size[0];
	if (game->map)
	{
		while (index-- > 0)
			if (game->map[index])
				free(game->map[index]);
		free(game->map);
	}
}

void	free_txtrs(t_game *game)
{
	if (game->txtrs.north)
		free(game->txtrs.north);
	if (game->txtrs.south)
		free(game->txtrs.south);
	if (game->txtrs.east)
		free(game->txtrs.east);
	if (game->txtrs.west)
		free(game->txtrs.west);
}

int	exit_free(t_game *game)
{
	free_map(game);
	free_txtrs(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->data.img)
		mlx_destroy_image(game->mlx, game->data.img);
	if (game->north.wall)
		mlx_destroy_image(game->mlx, game->north.wall);
	if (game->south.wall)
		mlx_destroy_image(game->mlx, game->south.wall);
	if (game->east.wall)
		mlx_destroy_image(game->mlx, game->east.wall);
	if (game->west.wall)
		mlx_destroy_image(game->mlx, game->west.wall);
	exit(0);
}
