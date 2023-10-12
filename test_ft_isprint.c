#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_isprint(int c)
{
	test_counter += 1;
	if (ft_isprint(c) == isprint(c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%c'.\n", c);
	return (1);
}

void	run_testcases_ft_isprint(void)
{
	printf("TEST 'ft_isprint' started:\n");
	test_ft_isprint('0');
	test_ft_isprint('a');
	test_ft_isprint(0);
	test_ft_isprint('\n');
	test_ft_isprint(' ');
	test_ft_isprint(127);
	test_ft_isprint(233);
	test_ft_isprint(-53);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
