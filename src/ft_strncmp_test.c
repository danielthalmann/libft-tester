#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "libft.h"
#include "faker.h"

void ft_strncmp_test(char *s, char *s2, int size);

/**
 * @brief main test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char** argv)
{

	char	*s;
	char	*s2;
	int		i;
	(void) argc;
	(void) argv;
	
	i = -1;
	while (i < 10)
	{
		s = ft_fake_printable(i + 5);
		s2 = malloc((i + 6) * sizeof(char));
		strcpy(s2, s);
		ft_strncmp_test(s, s2, i + 4);
		free(s);
		free(s2);
		i++;
	}

	i = -1;
	while (i < 10)
	{
		s = ft_fake_alpha(i + 5);
		s2 = ft_fake_alpha(i + 4);
		ft_strncmp_test(s, s2, i + 4);
		free(s);
		free(s2);
		i++;
	}
	ft_strncmp_test("\0", "\200", 1);
	ft_strncmp_test("\200", "\0", 1);

	ft_strncmp_test("", "", 5);
	ft_strncmp_test("jkjk", "jtzrt", 0);
	ft_strncmp_test("jkjk", "jtzrt", 1);

}

void ft_strncmp_test(char *s, char *s2, int size)
{
	int	e;
	int	r;

	e = 0;
	e = strncmp(s, s2, size);
	r = ft_strncmp(s, s2, size);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tstring2 [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\n", s, s2, e, r);

	assert(r  == e);
}
