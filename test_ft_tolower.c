#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_tolower(int c)
{
	test_counter += 1;
	if (ft_tolower(c) == tolower(c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%c'.\n", c);
	return (1);
}

void	run_testcases_ft_tolower(void)
{
	printf("TEST 'ft_tolower' started:\n");
	test_ft_tolower('0');
	test_ft_tolower('a');
	test_ft_tolower('A');
	test_ft_tolower(66);
	test_ft_tolower(100);
	test_ft_tolower(' ');
	test_ft_tolower('Z');
	test_ft_tolower('^');
	printf("%d/%d tests were successful.\n", success, test_counter);
}
