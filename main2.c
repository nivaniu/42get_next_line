#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_bzero(void *s, int n);
void	*ft_memccpy(void *dst, const void *src, int c, int n);
char	*ft_strdup(const char *s);

void	l(char *msg){if(debug) printf("%s", msg);}
void	ld(int nb){if(debug) printf("%d",nb);}
void	enl(){if(debug) printf("\n");}
void	lc(char c){if(debug) printf("%c", c);}
int	has_new_line(char *tmp, int length)
{
	int i = 0;
	enl();
//	l("Debug has new line");enl();
//	l("length =");ld(length);enl();
	while (i < length && tmp[i] != '\n') {
//		l("i =");ld(i);enl();
//		l("tmp[i] =");lc(tmp[i]);enl();
		i++;
	}
//	l("Exit loop");enl();
//	l("i =");ld(i);enl();
//	l("tmp[i] =");ld(tmp[i]);enl();
	if (i == length) return -1;
		return i+1;
}
char	*get_next_line(int fd){

static char tmp[32000];
char copied[32000];
static int readed;
int new_line_pos = 0;
ft_bzero(copied,32000);
if(tmp[0] && (new_line_pos = has_new_line(tmp, readed)) !=-1){
l("Readed = ");ld(readed);
l("\nnew_line_pos = ");ld(new_line_pos);
l("\ntmp 0 has something an contains new line");
l("\ntmp = .");l(tmp);
l("\ncopied = .");l(copied);
ft_memccpy(copied, tmp, '\n', readed);
l("\ncopied ");l(copied);
ft_memccpy(tmp, tmp+new_line_pos, 0, readed);
ft_bzero(tmp+readed-new_line_pos,readed-new_line_pos);
l("\ntmp after copy ");l(tmp);enl();
readed -= new_line_pos;
l("\nReaded at the end ");ld(readed);enl();
}else{
do {
readed += read(fd, tmp+readed, BUFFER_SIZE);
} while((new_line_pos = has_new_line(tmp, readed)) == -1);
enl();
l("tmp = .");l(tmp);enl();
ft_memccpy(copied, tmp, '\n', readed);
l("\ncopied .");l(copied);
ft_memccpy(tmp, tmp+new_line_pos, 0, readed);
ft_bzero(tmp+readed-new_line_pos,readed-new_line_pos);
l("\ntmp after copy .");l(tmp);enl();
readed -= new_line_pos;
l("\nReaded at the end ");ld(readed);enl();
}
ft_bzero(tmp+readed-new_line_pos,readed-new_line_pos);
return (ft_strdup(copied));
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
//	static char tmp[32000];
//	char copied[32000];
	// while does not have new line
	// read some more
//	int readed = 0;
//	int new_line_pos = 0;
//	enl();
//	do {
//	readed += read(fd, tmp+readed, BUFFER_SIZE);
//	} while((new_line_pos = has_new_line(tmp, readed)) == -1);
//	enl();
//	l(tmp);enl();
//	ft_memccpy(copied, tmp, '\n', readed);
//	l("copied ");l(copied);
//	ft_memccpy(tmp, tmp+new_line_pos, 0, readed);
//	ft_bzero(tmp+readed-new_line_pos,readed-new_line_pos);
//	l("tmp after copy ");l(tmp);enl();
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	close(fd);
	return (0);
}
void	*ft_memccpy(void *dst, const void *src, int c, int n)
{
	unsigned char	*r;
	unsigned char	*s;

	s = (unsigned char*)src;
	r = (unsigned char*)dst;
	while (n--)
	{
		if (*r == (unsigned char)c)
			return (r + 1);
		*r = *s;
		r++;
		s++;
	}
	return (0);
}
void	ft_bzero(void *s, int n)
{
	char *r;

	r = s;
	while (n > 0)
	{
		r[--n] = '\0';
	}
}

int			ft_len(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = (char *)malloc((ft_len(s) + 1) * sizeof(char))))
		return (0);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
