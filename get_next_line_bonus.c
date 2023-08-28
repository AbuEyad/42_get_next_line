/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:37:20 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/28 13:42:31 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *read_txt)
{
	char	*tmp_txt;
	int		read_count;

	tmp_txt = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_txt)
		return (NULL);
	read_count = 1;
	while (!found_line(read_txt, '\n') && read_count != 0)
	{
		read_count = read(fd, tmp_txt, BUFFER_SIZE);
		if (read_count < 0 || !tmp_txt)
		{
			free(tmp_txt);
			free(read_txt);
			return (NULL);
		}
		tmp_txt[read_count] = '\0';
		read_txt = ft_strjoin(read_txt, tmp_txt);
	}
	free(tmp_txt);
	return (read_txt);
}

char	*get_next_line(int fd)
{
	static char	*read_txt[MAX_FD];
	char		*line_txt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_txt[fd] = read_file(fd, read_txt[fd]);
	if (!read_txt[fd])
		return (NULL);
	line_txt = return_line(read_txt[fd]);
	read_txt[fd] = return_remaining_txt(read_txt[fd]);
	return (line_txt);
}
