/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:05:40 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/23 13:39:35 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_file_name(char *file_name)
{
	int	len;

	len = str_len(file_name);
	if (len <= 4 || (file_name[len - 1] != 'b' && file_name[len - 2] != 'u'
			&& file_name[len - 3] != 'c' && file_name[len - 4] != '.'))
	{
		write(2, "Error\nwrong filename.\n", 22);
		exit(1);
	}
}

int	open_file(char *path)
{
	int	file_des;

	file_des = open(path, O_RDONLY);
	if (file_des < 0)
	{
		perror("Error\n");
		exit(1);
	}
	return (file_des);
}
