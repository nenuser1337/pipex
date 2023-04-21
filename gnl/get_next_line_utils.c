/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:19:30 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/23 19:37:37 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, char c)
{
	size_t	i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
	{
		if (i >= start && j < ft_strlen(s))
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = s[i];
	str[j + 1] = '\0';
	free(s);
	return (str);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlen(src);
	new = malloc(size * sizeof(char) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*strjoin;
	int		i;

	i = 0;
	if (!s2)
		s2 = "";
	if (!s1)
		s1 = ft_strdup("");
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	strjoin = malloc(size_s1 + size_s2 + 1);
	if (!strjoin)
		return (NULL);
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	strjoin[i] = '\0';
	ft_strcat(strjoin, s2);
	free(s1);
	return (strjoin);
}
