#include <stdlib.h>
#include <stdio.h>

void	destructor_leaks(void)__attribute__((destructor));

void	destructor_leaks(void)
{
	int	ret;

	ret = system("leaks a.out &> leaks.txt");
	if (ret)
		printf("\e[31m!LEAK DETECTED!\e[0m\n");
}
