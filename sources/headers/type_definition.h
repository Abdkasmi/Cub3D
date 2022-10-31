/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_definition.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:47:31 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 07:45:55 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_DEFINITION_H
# define TYPE_DEFINITION_H

# define WIN_X 1920.0
# define WIN_Y 1080.0
# define DR 0.0174533
# define PI 3.141592
# define FOV 60
# define DOF 100

typedef struct s_txtrs
{
	char		*north;
	char		*east;
	char		*south;
	char		*west;
	int			floor;
	int			ceil;
}				t_txtrs;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			l_l;
	int			endian;
}				t_data;

typedef struct s_perso
{
	double		pa;
	double		p_x;
	double		p_y;
}				t_perso;

typedef struct s_ray
{
	int		x;
	float	dist;
	float	pos[2];
}				t_ray;

typedef struct s_img
{
	void		*wall;
	char		*addr_img;
	int			width;
	int			height;
	int			bpp;
	int			l_l;
	int			endian;
}				t_img;

typedef struct s_map
{
	char		**map;
	int			size[2];
	void		*mlx;
	void		*win;
	int			index;
	int			fd;
	t_perso		perso;
	t_img		img;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_data		data;
	t_txtrs		txtrs;
}				t_game;

#endif /* TYPE_DEFINITION_H */
