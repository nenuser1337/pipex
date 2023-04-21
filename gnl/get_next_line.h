/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:19:34 by yait-oul          #+#    #+#             */
/*   Updated: 2023/04/21 05:19:41 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#include <string.h>
#include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strdup(char *src);
char	*ft_strcat(char *dest, char *src);
int		indexx(char *s, int c);

char	*rtrn(char **line, char **buf, char **remainder);
char	*nl_retrn(char **line, char **remainder, char **buf);

char	*checknbytes(char **line, char **remainder, char **buf, int bnr);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, char c);
void	here_doc(char *argv);

#endif
