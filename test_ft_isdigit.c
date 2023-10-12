#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_isdigit(int c)
{
	test_counter += 1;
	if (ft_isdigit(c) == isdigit(c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%c'.\n", c);
	return (1);
}

void	run_testcases_ft_isdigit(void)
{
	printf("TEST 'ft_isdigit' started:\n");
	test_ft_isdigit('0');
	test_ft_isdigit('9');
	test_ft_isdigit(0);
	test_ft_isdigit(53);
	test_ft_isdigit(' ');
	test_ft_isdigit('Z');
	test_ft_isdigit('^');
	printf("%d/%d tests were successful.\n", success, test_counter);
}
