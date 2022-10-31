/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:03:28 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 07:50:02 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_to_img(t_game *game)
{
	t_img	*img[4];
	char	*txtrs[4];
	int		i;

	i = -1;
	img[0] = &game->north;
	txtrs[0] = game->txtrs.north;
	img[1] = &game->east;
	txtrs[1] = game->txtrs.east;
	img[2] = &game->south;
	txtrs[2] = game->txtrs.south;
	img[3] = &game->west;
	txtrs[3] = game->txtrs.west;
	while (++i < 4)
	{
		img[i]->wall = mlx_xpm_file_to_image(game->mlx, txtrs[i],
				&img[i]->width, &img[i]->height);
		if (!img[i]->wall)
			exit_free(game);
		img[i]->addr_img = mlx_get_data_addr(img[i]->wall, &img[i]->bpp,
				&img[i]->l_l, &img[i]->endian);
		if (!img[i]->addr_img)
			exit_free(game);
	}
}

void	parse_line(char *str, t_game *g)
{
	int	temp;

	temp = skip_spaces(str);
	if (str[temp] == 'N' && str[temp + 1] == 'O' && str[temp + 2] == ' '
		&& !g->txtrs.north)
		g->txtrs.north = copy_path(str + temp + 2, g);
	else if (str[temp] == 'S' && str[temp + 1] == 'O' && str[temp + 2] == ' '
		&& !g->txtrs.south)
		g->txtrs.south = copy_path(str + temp + 2, g);
	else if (str[temp] == 'W' && str[temp + 1] == 'E' && str[temp + 2] == ' '
		&& !g->txtrs.west)
		g->txtrs.west = copy_path(str + temp + 2, g);
	else if (str[temp] == 'E' && str[temp + 1] == 'A' && str[temp + 2] == ' '
		&& !g->txtrs.east)
		g->txtrs.east = copy_path(str + temp + 2, g);
	else if (str[temp] == 'F' && str[temp + 1] == ' ' && g->txtrs.floor == -1)
		g->txtrs.floor = copy_colors(str + temp + 1, g);
	else if (str[temp] == 'C' && str[temp + 1] == ' ' && g->txtrs.ceil == -1)
		g->txtrs.ceil = copy_colors(str + temp + 1, g);
	else
	{
		write(2, "Error\nProblems with textures.\n", 30);
		exit_free(g);
	}
}

int	skip_spaces(char *string)
{
	int	index;

	index = 0;
	while (string[index] && string[index] == ' ')
	{
		index++;
	}
	return (index);
}

char	*copy_path(char *string, t_game *game)
{
	int		index;
	int		len;
	char	*path;

	string += skip_spaces(string);
	len = 0;
	while (string[len] && string[len] != ' ' && string[len] != '\n')
		len++;
	path = malloc((len + 1) * sizeof(char));
	if (!path)
		exit_free(game);
	index = -1;
	while (++index < len)
	{
		path[index] = string[index];
	}
	path[index] = '\0';
	return (path);
}

int	copy_colors(char *string, t_game *game)
{
	int	index;
	int	colors[3];
	int	len;

	index = -1;
	while (++index < 3)
	{
		string += skip_spaces(string);
		len = 0;
		while (string[len] && string[len] != ' ' && string[len] != ','
			&& string[len] != '\n')
		{
			len++;
		}
		colors[index] = ft_atoi(string, len);
		if (colors[index] < 0 || colors[index] > 255)
		{
			write(2, "Error\nWrong colors\n", 19);
			exit_free(game);
		}
		string += len + skip_spaces(string + len);
		if (*string == ',')
			string++;
	}
	return (0 << 24 | colors[0] << 16 | colors[1] << 8 | colors[2]);
}
