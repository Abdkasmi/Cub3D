/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:37:51 by abkasmi           #+#    #+#             */
/*   Updated: 2022/10/27 14:09:22 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "type_definition.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_img_pix(t_img *img, float x, float y)
{
	char	*ptr;
	int		ptr2;

	ptr = img->addr_img + (int)((int)(y * img->height) * img->l_l + (int)(x
				* img->width) * (img->bpp / 8));
	ptr2 = *((int *)ptr);
	return (ptr2);
}

int	create_trgb(unsigned char colors[3])
{
	return (0 << 24 | colors[0] << 16 | colors[1] << 8 | colors[2]);
}
