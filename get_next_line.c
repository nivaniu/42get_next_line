/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivaniuk <nivaniuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:49:33 by nivaniuk          #+#    #+#             */
/*   Updated: 2021/08/22 09:55:26 by nivaniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_return(char *delimeter, char **memory, char **result)
{
	char	*tmp;

	if (delimeter)
	{
		*result = ft_strndup(*memory, delimeter - *memory + 1);
		tmp = ft_strndup(delimeter + 1, ft_strlen(delimeter + 1));
		if (!result || !tmp)
			return (ERR);
		free(*memory);
		*memory = tmp;
		return (OK);
	}
	else
	{
		if (*memory && **memory == 0)
		{
			*result = 0;
			free(*memory);
		}
		else
			*result = *memory;
		*memory = 0;
		return (EOF);
	}
}

static int	ft_read(int fd, char **memory, char **buffer, char **result)
{
	ssize_t	had_read;
	char	*tmp;
	char	*delimeter;

	while (1)
	{
		delimeter = ft_strchr(*memory, '\n');
		if (delimeter)
			break ;
		had_read = read(fd, *buffer, BUFFER_SIZE);
		if (had_read == -1)
			return (ERR);
		if (had_read == 0)
			break ;
		(*buffer)[had_read] = 0;
		tmp = ft_strjoin(*memory, *buffer);
		if (!tmp)
			return (ERR);
		free(*memory);
		*memory = tmp;
	}
	return (ft_return(delimeter, memory, result));
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*memory[OPEN_MAX + 1];
	char		*buffer;
	int			read_result;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	if (!memory[fd])
		memory[fd] = ft_strndup("", 0);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!memory[fd] || !buffer)
		return (0);
	result = 0;
	read_result = ft_read(fd, &memory[fd], &buffer, &result);
	free(buffer);
	if (read_result == ERR || read_result == EOF)
	{
		free(memory[fd]);
		memory[fd] = 0;
	}
	if (read_result == ERR)
		return (0);	
	return (result);
}
