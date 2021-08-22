/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivaniuk <nivaniuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:49:30 by nivaniuk          #+#    #+#             */
/*   Updated: 2021/08/22 09:34:25 by nivaniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OK 1
# define EOF 0
# define ERR -1

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, char c);
char		*ft_strndup(const char*s, size_t n);
char		*ft_strjoin(char const *src, char const *to_join);

#endif
