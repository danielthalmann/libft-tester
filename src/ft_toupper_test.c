#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"
#include "faker.h"

void ft_toupper_test(char s);

/**
 * @brief main test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char** argv)
{

	char *s;
    int i;
	(void) argc;
	(void) argv;
	
	s = ft_fake_printable(15);
    i = 0;
	while (s[i])
	{
		ft_toupper_test(s[i]);
		i++;
    }
	free(s);

	s = ft_fake_alpha(15);
    i = -1;
	while (i < 520)
	{
		ft_toupper_test(i);
		i++;
    }
	free(s);
}

void ft_toupper_test(char s)
{
	char e;
	char r;
	e = toupper(s);
	r = ft_toupper(s);
	printf("string [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\n", s,  e, r);
	assert(r == e);
}
