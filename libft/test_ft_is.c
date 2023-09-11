#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void) ac;
	printf("%i", isalnum(av[1][0]));
}
