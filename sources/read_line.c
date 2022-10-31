/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:26:11 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/10/28 04:30:15 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*next_line(int file_des, int *total_read)
{
	char	*line;

	line = read_line(file_des, total_read);
	while (line && line[0] == 0)
	{
		free(line);
		line = read_line(file_des, total_read);
	}
	return (line);
}

char	*reading_errors(int id, char *line)
{
	if (id == 0)
		return (line);
	free(line);
	exit(1);
}

char	read_char(int file_des)
{
	char	buff[1];
	int		byte_read;

	byte_read = read(file_des, buff, 1);
	if (byte_read <= 0)
		return (byte_read);
	return (*buff);
}

char	*read_line(int file_des, int *total_read)
{
	char	*line;
	char	buffer;

	buffer = read_char(file_des);
	if (buffer < 0)
		exit(1);
	if (buffer == 0)
		return (0);
	line = malloc(1 * sizeof(char));
	if (!line)
		exit(1);
	line[0] = buffer;
	line = reading_loop(line, file_des, total_read);
	return (line);
}

char	*reading_loop(char *line, int file_des, int *total_read)
{
	char	*temp_line;
	char	buffer;
	int		total;
	int		index;

	total = 0;
	index = -1;
	while (line[total] != '\n')
	{
		buffer = read_char(file_des);
		if (buffer <= 0)
			return (reading_errors(buffer, line));
		index = -1;
		temp_line = malloc((total + 2) * sizeof(char));
		if (!temp_line)
			reading_errors(buffer, line);
		while (++index < total + 1)
			temp_line[index] = line[index];
		temp_line[++total] = buffer;
		free(line);
		line = temp_line;
	}
	line[total] = '\0';
	*total_read += total + 1;
	return (line);
}
