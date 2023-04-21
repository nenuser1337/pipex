/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:57 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/24 21:37:36 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	str++;
	return (str);
}

int	indexx(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0')
		{
			return (-1);
		}
		i++;
	}
	i++;
	return (i);
}

char	*checknbytes(char **line, char **remainder, char **buf, int bnr)
{
	free(*buf);
	*remainder = 0;
	if (bnr && **line)
		return (*line);
	free(*line);
	return (NULL);
}

char	*nl_retrn(char **line, char **remainder, char **buf)
{
	*remainder = ft_strdup(*line + indexx(*line, '\n'));
	free(*buf);
	return (ft_substr(*line, 0, '\n'));
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			nbytes;
	char		*buf;

	nbytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = ft_strjoin(remainder, 0);
	while (nbytes > 0)
	{
		if (ft_strchr(line, '\n'))
			return (nl_retrn(&line, &remainder, &buf));
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes < 0)
			return (checknbytes(&line, &remainder, &buf, 0));
		buf[nbytes] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (checknbytes(&line, &remainder, &buf, 1));
}
