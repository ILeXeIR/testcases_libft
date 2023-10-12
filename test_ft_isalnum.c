#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_isalnum(int c)
{
	test_counter += 1;
	if (ft_isalnum(c) == isalnum(c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%c'.\n", c);
	return (1);
}

void	run_testcases_ft_isalnum(void)
{
	printf("TEST 'ft_isalnum' started:\n");
	test_ft_isalnum('0');
	test_ft_isalnum('a');
	test_ft_isalnum(0);
	test_ft_isalnum(53);
	test_ft_isalnum(' ');
	test_ft_isalnum('Z');
	test_ft_isalnum('^');
	printf("%d/%d tests were successful.\n", success, test_counter);
}
