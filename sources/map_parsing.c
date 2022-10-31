/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:21:57 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 10:06:15 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_game_dim(int file_des, t_game *map)
{
	int		byte_read;
	char	*temp_line;

	byte_read = 0;
	map->size[0] = 1;
	temp_line = read_line(file_des, &byte_read);
	while (temp_line)
	{
		if (byte_read > map->size[1])
			map->size[1] = byte_read;
		byte_read = 0;
		map->size[0]++;
		free(temp_line);
		temp_line = read_line(file_des, &byte_read);
	}
	free(temp_line);
}

void	player_placing(t_game *game, int index[2])
{
	if (game->map[index[1]][index[0]] == 'N'
		|| game->map[index[1]][index[0]] == 'E'
		|| game->map[index[1]][index[0]] == 'S'
		|| game->map[index[1]][index[0]] == 'W')
	{
		if (game->perso.p_x != -1 || game->perso.p_y != -1)
		{
			write(2, "More than one player information.\n", 34);
			exit_free(game);
		}
		game->perso.p_x = index[0] + 0.5;
		game->perso.p_y = index[1] + 0.5;
		if (game->map[index[1]][index[0]] == 'N')
			game->perso.pa = PI + (PI / 2);
		else if (game->map[index[1]][index[0]] == 'E')
			game->perso.pa = 2 * PI;
		else if (game->map[index[1]][index[0]] == 'S')
			game->perso.pa = PI / 2;
		else if (game->map[index[1]][index[0]] == 'W')
			game->perso.pa = PI;
		game->map[index[1]][index[0]] = '0';
	}
}

void	fill_map_array(int file_des, t_game *game)
{
	int		index[2];
	char	*temp_line;
	int		byte_read;

	index[1] = -1;
	while (++index[1] < game->size[0])
	{
		index[0] = -1;
		temp_line = read_line(file_des, &byte_read);
		while (++index[0] < game->size[1])
		{
			if (temp_line[index[0]])
			{
				game->map[index[1]][index[0]] = temp_line[index[0]];
				player_placing(game, index);
			}
			else
				while (index[0] < game->size[1])
					game->map[index[1]][index[0]++] = ' ';
		}
		free(temp_line);
	}
}

void	init_map_array(t_game *game)
{
	int	index;

	index = -1;
	game->map = malloc(game->size[0] * sizeof(char *));
	if (!game->map)
		exit_free(game);
	while (++index < game->size[0])
	{
		game->map[index] = malloc(game->size[1] * sizeof(char));
		if (!game->map[index])
			exit_free(game);
	}
}

void	read_map(char *path, int start, int width, t_game *game)
{
	char	*temp;

	game->size[1] = width;
	get_game_dim(game->fd, game);
	close(game->fd);
	game->fd = open(path, O_RDONLY);
	temp = malloc(start * sizeof(char));
	if (!temp)
		exit_free(game);
	read(game->fd, temp, start);
	free(temp);
	init_map_array(game);
	fill_map_array(game->fd, game);
	if (!is_map_good(*game))
	{
		write(2, "Error\nInvalid map.\n", 19);
		exit_free(game);
	}
}
