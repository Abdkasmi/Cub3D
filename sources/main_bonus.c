/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:24:59 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 10:46:54 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	routine_read(char *path, t_game *game)
{
	char	*line;
	int		total_read;
	int		lenght;
	int		cycles;

	game->fd = open_file(path);
	cycles = -1;
	total_read = 0;
	line = next_line(game->fd, &total_read);
	while (line && ++cycles < 6)
	{
		parse_line(line, game);
		free(line);
		line = next_line(game->fd, &total_read);
	}
	lenght = str_len(line);
	free(line);
	read_map(path, total_read - lenght - 1, lenght, game);
}

void	init_struct(t_game *game)
{
	game->win = 0;
	game->map = 0;
	game->mlx = 0;
	game->data.img = 0;
	game->north.wall = 0;
	game->east.wall = 0;
	game->west.wall = 0;
	game->south.wall = 0;
	game->txtrs.ceil = -1;
	game->txtrs.floor = -1;
	game->txtrs.east = 0;
	game->txtrs.south = 0;
	game->txtrs.west = 0;
	game->txtrs.north = 0;
	game->perso.p_x = -1;
	game->perso.p_y = -1;
	game->perso.pa = -1;
}

int	main(int n_arg, char **args)
{
	int		file_des;
	t_game	game;

	if (n_arg != 2)
	{
		write(2, "Error\nincorrect number of arguments.\n", 37);
		exit(1);
	}
	init_struct(&game);
	handle_file_name(args[1]);
	file_des = open_file(args[1]);
	routine_read(args[1], &game);
	game.mlx = mlx_init();
	game.win = init_window_mlx(&game);
	game.data.img = new_img(&game);
	convert_to_img(&game);
	raycast(&game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 6, 0, mouse_hook, &game);
	mlx_loop_hook(game.mlx, raycast, &game);
	mlx_hook(game.win, 17, 0, exit_free, &game);
	mlx_loop(game.mlx);
	close(file_des);
	exit_free(&game);
}
