/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:08:00 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 10:39:10 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceil(t_game *g, int end, t_ray ray)
{
	int	i;

	i = -1;
	while (++i < end)
	{
		if (i > end - 2 && i < end)
			my_mlx_pixel_put(&g->data, ray.x, i, 0);
		else
			my_mlx_pixel_put(&g->data, ray.x, i, g->txtrs.ceil);
	}
}

void	draw_floor(t_game *g, int start, int end, t_ray ray)
{
	int	i;

	i = -1;
	while (start + ++i < end)
	{
		if (i < 2)
			my_mlx_pixel_put(&g->data, ray.x, start + i, 0);
		else
			my_mlx_pixel_put(&g->data, ray.x, start + i, g->txtrs.floor);
	}
}

int	chose_side(t_game *game, float y, t_ray ray)
{
	float	ray_x;
	float	ray_y;

	ray_x = ray.pos[0];
	ray_y = ray.pos[1];
	if (ray_x == (int)ray_x && ray_x < game->perso.p_x)
		return (get_img_pix(&game->east, (ray_y - (int)ray_y) * -1, y));
	else if (ray_x == (int)ray_x && ray_x > game->perso.p_x)
		return (get_img_pix(&game->west, (ray_y - (int)ray_y), y));
	else if (ray_y == (int)ray_y && ray_y > game->perso.p_y)
		return (get_img_pix(&game->north, (ray_x - (int)ray_x) * -1, y));
	else
		return (get_img_pix(&game->south, (ray_x - (int)ray_x), y));
}

void	draw_wall(t_game *game, int start, float wall, t_ray ray)
{
	int	color;
	int	start_wall;
	int	index;
	int	end;

	start_wall = -1;
	index = -1;
	end = wall;
	if (wall > WIN_Y)
	{
		start_wall = (wall - WIN_Y) / 2 - 1;
		end = WIN_Y;
	}
	while (++index < end)
	{
		color = chose_side(game, ++start_wall / wall, ray);
		my_mlx_pixel_put(&game->data, ray.x, start + index, color);
	}
}

void	draw_line(t_ray ray, t_game *game, int x)
{
	int				off;
	unsigned int	wall;

	wall = WIN_Y / ray.dist;
	ray.x = x;
	off = (WIN_Y - wall) / 2;
	if (WIN_Y < wall)
		off = 0;
	draw_ceil(game, off, ray);
	draw_wall(game, off, wall, ray);
	draw_floor(game, off + wall, WIN_Y, ray);
}
