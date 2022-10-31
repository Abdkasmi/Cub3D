/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_testing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:49:16 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 02:46:38 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_elems(char element)
{
	if (element == '0')
		return (0);
	if (element == '1')
		return (0);
	if (element == ' ')
		return (0);
	if (element == 'N')
		return (0);
	if (element == 'E')
		return (0);
	if (element == 'S')
		return (0);
	if (element == 'W')
		return (0);
	return (1);
}

int	is_map_good(t_game m_struc)
{
	int		index[2];
	char	**map;

	map = m_struc.map;
	index[0] = -1;
	while (++index[0] < m_struc.size[0])
	{
		index[1] = -1;
		while (++index[1] < m_struc.size[1])
		{
			if (map[index[0]][index[1]] == '0')
			{
				if (index[0] == 0 || index[0] == m_struc.size[0] - 1
					|| index[1] == 0 || index[1] == m_struc.size[1] - 1)
					return (0);
				if (map[index[0] - 1][index[1]] == ' ' || map[index[0]][index[1]
					- 1] == ' ' || map[index[0] + 1][index[1]] == ' '
					|| map[index[0]][index[1] + 1] == ' ')
					return (0);
			}
			if (check_map_elems(map[index[0]][index[1]]))
				return (0);
		}
	}
	return (1);
}
