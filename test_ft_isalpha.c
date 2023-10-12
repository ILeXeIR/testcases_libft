#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_isalpha(int c)
{
	test_counter += 1;
	if (ft_isalpha(c) == isalpha(c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%c'.\n", c);
	return (1);
}

void	run_testcases_ft_isalpha(void)
{
	printf("TEST 'ft_isalpha' started:\n");
	test_ft_isalpha('0');
	test_ft_isalpha('a');
	test_ft_isalpha(0);
	test_ft_isalpha(73);
	test_ft_isalpha(' ');
	test_ft_isalpha('Z');
	test_ft_isalpha('^');
	printf("%d/%d tests were successful.\n", success, test_counter);
}
