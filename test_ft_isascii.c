#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_isascii(int c)
{
	test_counter += 1;
	if (ft_isascii(c) == isascii(c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%c'.\n", c);
	return (1);
}

void	run_testcases_ft_isascii(void)
{
	printf("TEST 'ft_isascii' started:\n");
	test_ft_isascii('0');
	test_ft_isascii('a');
	test_ft_isascii(0);
	test_ft_isascii('\n');
	test_ft_isascii(' ');
	test_ft_isascii(127);
	test_ft_isascii(128);
	test_ft_isascii(200);
	test_ft_isascii(-10);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
