/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:39:41 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/03 23:03:53 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include   <stdlib.h>
# include   <stdio.h>
# include   <unistd.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>

int		get_strchr(char *str);
char	*get_next_line(int fd);
int		get_strlen(const char *s);
char	*get_strjoin(char *s1, char *s2);
char	*get_strdup(const char *s1);
char	*get_substr(char const *s, size_t start, size_t len);
char	*get_next(char *str);
char	*get_line(char *str);
char	*norm_kekw(char *str, int fd);

#endif