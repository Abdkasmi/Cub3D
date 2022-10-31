/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:48:35 by abkasmi           #+#    #+#             */
/*   Updated: 2022/10/28 04:32:20 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "type_definition.h"

void	go_backward(t_perso *perso)
{
	if (perso->p_x - cos(perso->pa) * 0.2)
		perso->p_x -= cos(perso->pa) * 0.2;
	perso->p_y -= sin(perso->pa) * 0.2;
}

int	key_hook(int keycode, t_game *params)
{
	t_perso	*perso;

	perso = &params->perso;
	if (keycode == 123)
		rotate_left(perso);
	if (keycode == 124)
		rotate_right(perso);
	if (keycode == 0 || keycode == 2 || keycode == 13 || keycode == 126
		|| keycode == 1 || keycode == 125)
		move(keycode, params);
	if (keycode == 53)
		exit_free(params);
	return (0);
}

int	mouse_hook(int x, int y, t_game *params)
{
	static int	pre_x;

	pre_x = 0;
	printf("X: %d, Y: %d\n", x, y);
	if (y > WIN_Y * (4.0 / 5.0) && y < WIN_Y)
	{
		if (0 < x && x < WIN_X)
		{
			if (x < pre_x)
				rotate_left(&params->perso);
			else if (x > pre_x)
				rotate_right(&params->perso);
		}
	}
	pre_x = x;
	return (0);
}
