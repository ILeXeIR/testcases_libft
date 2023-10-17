#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_toupper(int c)
{
	test_counter += 1;
	if (ft_toupper(c) == toupper(c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%c'.\n", c);
	return (1);
}

void	run_testcases_ft_toupper(void)
{
	printf("TEST 'ft_toupper' started:\n");
	test_ft_toupper('0');
	test_ft_toupper('a');
	test_ft_toupper('A');
	test_ft_toupper(66);
	test_ft_toupper(100);
	test_ft_toupper(' ');
	test_ft_toupper('z');
	test_ft_toupper('^');
	printf("%d/%d tests were successful.\n", success, test_counter);
}
