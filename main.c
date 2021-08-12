#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_bzero(void *s, int n);
void	*ft_memccpy(void *dst, const void *src, int c, int n);

void	l(char *msg){if(debug) printf("%s", msg);}
void	ld(int nb){if(debug) printf("%d",nb);}
void	enl(){if(debug) printf("\n");}
void	lc(char c){if(debug) printf("%c", c);}
int	has_new_line(char *tmp, int length)
{
	int i = 0;
	enl();
	l("Debug has new line");enl();
	l("length =");ld(length);enl();
	while (i < length && tmp[i] != '\n') {
		l("i =");ld(i);enl();
		l("tmp[i] =");lc(tmp[i]);enl();
		i++;
	}
	l("Exit loop");enl();
	l("i =");ld(i);enl();
	l("tmp[i] =");ld(tmp[i]);enl();
	if (i == length) return -1;
		return i;
}

int	main(int argc, char *argv[])
{
	(void)argc;(void)argv;
	l("Start\n");
	printf("Debug \t\t%d\nBUFFER_SIZE \t%d\n", debug, BUFFER_SIZE);
	int fd = open(tfile, O_RDONLY);
	l("fd\t\t");ld(fd);enl();
	l(tfile);
	if (fd < 1)
	{
		l("Error opening file");
		return (-1);
	}
	char tmp[32000];
	char copied[32000];
	// while does not have new line
	// read some more
	int readed = 0;
	int new_line_pos = 0;
	enl();
	do {
	readed += read(fd, tmp+readed, BUFFER_SIZE);
	} while((new_line_pos = has_new_line(tmp, readed)) == -1);
	enl();
	l(tmp);enl();
	ft_memccpy(copied, tmp, '\n', readed);
	l("copied ");l(copied);
	ft_memccpy(tmp, tmp+new_line_pos, 0, readed);
	ft_bzero(tmp+readed-new_line_pos,readed-new_line_pos);
	l("tmp after copy ");l(tmp);enl();
	close(fd);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivaniuk <nivaniuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:46:11 by nivaniuk          #+#    #+#             */
/*   Updated: 2021/02/14 11:05:49 by nivaniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, int n)
{
	unsigned char	*r;
	unsigned char	*s;

	s = (unsigned char*)src;
	r = (unsigned char*)dst;
	while (n--)
	{
		*r = *s;
		if (*r == (unsigned char)c)
			return (r + 1);
		r++;
		s++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivaniuk <nivaniuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:54:07 by nivaniuk          #+#    #+#             */
/*   Updated: 2021/01/10 14:22:10 by nivaniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, int n)
{
	char *r;

	r = s;
	while (n > 0)
	{
		r[--n] = '\0';
	}
}
