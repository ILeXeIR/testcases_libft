#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strlen(const char *s)
{
	test_counter += 1;
	if (ft_strlen(s) == strlen(s))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_strlen(void)
{
	printf("TEST 'ft_strlen' started:\n");
	test_ft_strlen("asdfg");
	test_ft_strlen("");
	test_ft_strlen("\n");
	test_ft_strlen("as\0dfg");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
