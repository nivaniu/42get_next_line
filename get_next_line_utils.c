/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivaniuk <nivaniuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:49:34 by nivaniuk          #+#    #+#             */
/*   Updated: 2021/08/22 09:33:09 by nivaniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	while (*str++)
		ret++;
	return (ret);
}

char	*ft_strchr(const char *str, char c)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp && *tmp != c)
		tmp++;
	if (*tmp != c)
		return (0);
	return (tmp);
}

char	*ft_strndup(const char*s, size_t n)
{
	char	*tmp;
	char	*res;

	res = (char *)malloc(n + 1);
	if (!res)
		return (0);
	tmp = res;
	while (n--)
		*tmp++ = *s++;
	*tmp = 0;
	return (res);
}

char	*ft_strjoin(char const *src, char const *to_join)
{
	char	*res;
	char	*tmp;
	size_t	len_src;
	size_t	len_to_join;

	len_src = ft_strlen(src);
	len_to_join = ft_strlen(to_join);
	res = (char *)malloc(len_src + len_to_join + 1);
	tmp = res;
	while (*src)
		*res++ = *src++;
	while (*to_join)
		*res++ = *to_join++;
	*res = 0;
	return (tmp);
}
