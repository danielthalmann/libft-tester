#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "libft.h"
#include "faker.h"

void ft_memcmp_test(char *s, char *s2, int size);

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
		s = ft_fake_alpha(i + 5);
		s2 = malloc((i + 6) * sizeof(char));
		strcpy(s2, s);
		ft_memcmp_test(s, s2, i + 5);
		free(s);
		free(s2);
		i++;
	}
	char	m[] = {0, 0, 127, 0};
	char	m2[] = {0, 0, 42, 0};
	ft_memcmp_test(m, m2, 1);
	ft_memcmp_test(m, m2, 4);
	ft_memcmp_test(m, m2, 4);

	i = -1;
	while (i < 10)
	{
		s = ft_fake_alpha(i + 5);
		s2 = ft_fake_alpha(i + 4);
		ft_memcmp_test(s, s2, i + 4);
		free(s);
		free(s2);
		i++;
	}

}

void ft_memcmp_test(char *s, char *s2, int size)
{
	int	e;
	int	r;

	e = 0;
	e = memcmp(s, s2, size);
	r = ft_memcmp(s, s2, size);
	if (s && s2)
		printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tstring2 [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tmemcmp expected [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\tft_memcmp obtain [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\n", s, s2, e, r);
	assert(r  == e);
}
