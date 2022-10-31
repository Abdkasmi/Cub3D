/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:47:28 by abkasmi           #+#    #+#             */
/*   Updated: 2022/10/28 07:51:47 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "type_definition.h"

void	rotate_left(t_perso *perso)
{
	perso->pa -= PI / 75.0;
	if ((int)(perso->pa < 0))
		perso->pa += 2 * PI;
}

void	rotate_right(t_perso *perso)
{
	perso->pa += PI / 75.0;
	if ((int)(perso->pa / (2 * PI)) != 0)
		perso->pa -= 2 * PI;
}

void	move(int key_id, t_game *g)
{
	double	delta[2];

	delta[0] = -cos(g->perso.pa) * 0.1;
	delta[1] = -sin(g->perso.pa) * 0.1;
	if (key_id == 0)
	{
		delta[0] = +sin(g->perso.pa) * 0.1;
		delta[1] = -cos(g->perso.pa) * 0.1;
	}
	else if (key_id == 2)
	{
		delta[0] = -sin(g->perso.pa) * 0.1;
		delta[1] = +cos(g->perso.pa) * 0.1;
	}
	else if (key_id == 126 || key_id == 13)
	{
		delta[0] = +cos(g->perso.pa) * 0.1;
		delta[1] = +sin(g->perso.pa) * 0.1;
	}
	if (g->map[(int)g->perso.p_y][(int)(g->perso.p_x + 2 * delta[0])] != '1')
		g->perso.p_x += delta[0];
	if (g->map[(int)(g->perso.p_y + 2 * delta[1])][(int)g->perso.p_x] != '1')
		g->perso.p_y += delta[1];
}
