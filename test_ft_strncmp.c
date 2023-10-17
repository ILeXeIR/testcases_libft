#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	test_counter += 1;
	if (ft_strncmp(s1, s2, n) == strncmp(s1, s2, n))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%s', '%s', '%zu'.\n", s1, s2, n);
	return (1);
}

void	run_testcases_ft_strncmp(void)
{
	printf("TEST 'ft_strncmp' started:\n");
	test_ft_strncmp("abcdef", "abcdef", 7);
	test_ft_strncmp("abcdef", "abcde1", 6);
	test_ft_strncmp("abcdef", "abcde1", 5);
	test_ft_strncmp("abcdef", "abcdef", 0);
	test_ft_strncmp("a", "b", 0);
	test_ft_strncmp("", "", 0);
	test_ft_strncmp("1", "", 0);
	test_ft_strncmp("1", "", 1);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
