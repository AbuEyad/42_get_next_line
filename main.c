/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:33:06 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/28 14:36:14 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>

int	main(void)
{
	int		i;

	char *name;
	int fd1;
	int fd;
	name = "test.txt";
	fd = open(name, O_RDONLY);
	printf("fd = %d\n", fd);
	/* 1 */ printf("GNL=%s",get_next_line(fd));//, "aaaaaaaaaa\n");
	/* 2 */ printf("GNL=%s",get_next_line(fd));//, "bbbbbbbbbb\n");
	// set the next read call to return -1
	// next_read_error = 1;
	// if (BUFFER_SIZE > 100) {
	// 	char *temp;
	// 	do {
	// 		temp = get_next_line(fd);
	// 		free(temp);
	// 	} while (temp != NULL);
	// }
	/* 3 */ printf("GNL=%s",get_next_line(fd));//, NULL);
	// next_read_error = 0;
	close(fd);
	fd = open(name, O_RDONLY);
	printf("fd = %d\n", fd);
	/* 4 */ printf("GNL=%s",get_next_line(fd));//, "aaaaaaaaaa\n");
	
	/* 5 */ printf("GNL=%s",get_next_line(fd));//, "bbbbbbbbbb\n");
	/* 6 */ printf("GNL=%s",get_next_line(fd));//, "cccccccccc\n");
	/* 7 */ printf("GNL=%s",get_next_line(fd));//, "dddddddddd\n");
	/* 8 */ printf("GNL=%s",get_next_line(fd));//, NULL);
	return (0);
}
