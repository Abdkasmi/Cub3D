/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:47:48 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 10:05:10 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "type_definition.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		str_len(char *string);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	draw_line(t_ray ray, t_game *game, int x);
int		get_img_pix(t_img *img, float x, float y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		open_file(char *path);
int		str_len(char *string);
void	handle_file_name(char *file_name);

int		ft_atoi(const char *str, int limit);

void	*new_img(t_game *map);
float	distance(double x_a, double y_a, double x_b, double y_b);
int		compare(float a, float b);

void	*init_window_mlx(t_game *map);

int		key_hook(int keycode, t_game *params);
int		raycast(t_game *map);
void	convert_to_img(t_game *game);
void	*init_window_mlx(t_game *map);
void	handle_file_name(char *file_name);
void	read_map(char *path, int start, int width, t_game *game);
int		str_len(char *string);
void	parse_line(char *str, t_game *game);
char	*next_line(int file_des, int *total_read);
int		open_file(char *path);
void	routine_read(char *path, t_game *game);

void	init_map_array(t_game *game);
void	fill_map_array(int file_des, t_game *game);
void	player_placing(t_game *game, int index[2]);
char	*read_line(int file_des, int *total_read);
void	get_game_dim(int file_des, t_game *map);

int		is_map_good(t_game m_struc);

void	move(int key, t_game *game);
void	rotate_right(t_perso *perso);
void	rotate_left(t_perso *perso);

int		copy_colors(char *string, t_game *game);
char	*copy_path(char *string, t_game *game);
int		skip_spaces(char *string);
void	parse_line(char *str, t_game *game);
void	convert_to_img(t_game *game);

float	map_size(t_game *map);

char	*reading_loop(char *line, int file_des, int *total_read);
char	read_char(int file_des);
char	*reading_errors(int id, char *line);
char	*read_line(int file_des, int *total_read);
char	*next_line(int file_des, int *total_read);

void	free_map(t_game *game);
void	free_txtrs(t_game *game);
int		exit_free(t_game *game);
int		is_digit(int c);
t_ray	vertical_seeking(t_game *map, float angle);
t_ray	horizontal_seeking(t_game *map, float angle);

#endif /* CUB3D_H */
