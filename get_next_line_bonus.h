/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:39:05 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/28 14:27:16 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1000
# endif

# ifndef MAX_FD
#  define MAX_FD 1025
# endif

int		found_line(char *str, char c);
char	*return_remaining_txt(char *read_txt);
int		ft_strlen(char *s);
char	*ft_strjoin(char *read_txt, char *tmp_txt);
char	*return_line(char *read_txt);
char	*read_file(int fd, char *read_txt);
char	*get_next_line(int fd);

#endif