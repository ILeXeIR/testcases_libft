#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strnstr(const char *s1, const char *s2, size_t n)
{
	test_counter += 1;
	if (ft_strnstr(s1, s2, n) == strnstr(s1, s2, n))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%s', '%s', '%zu'.\n", s1, s2, n);
	return (1);
}

void	run_testcases_ft_strnstr(void)
{
	printf("TEST 'ft_strnstr' started:\n");
	test_ft_strnstr("abcdef", "abcdef", 7);
	test_ft_strnstr("abcdef", "abcde1", 6);
	test_ft_strnstr("abcdef", "abcde1", 5);
	test_ft_strnstr("a", "a", 0);
	test_ft_strnstr("a", "a", 1);
	test_ft_strnstr("a", "b", 0);
	test_ft_strnstr("", "", 0);
	test_ft_strnstr("1", "", 0);
	test_ft_strnstr("1", "", 1);
	test_ft_strnstr("", "1", 0);
	test_ft_strnstr("", "1", 1);
	test_ft_strnstr("ababababa", "bab", 10);
	test_ft_strnstr("aba", "abab", 10);
	test_ft_strnstr("", "\0", 2);
	test_ft_strnstr("maaabaaoxaab", "aaba", 20);
	test_ft_strnstr("maaabaaoxaab", "aaba", 5);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
