#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_memchr(const void *s, int c, size_t n)
{
	test_counter += 1;
	if (ft_memchr(s, c, n) == memchr(s, c, n))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%s', '%c', '%zu'.\n", (char *)s, c, n);
	return (1);
}

void	run_testcases_ft_memchr(void)
{
	printf("TEST 'ft_memchr' started:\n");
	test_ft_memchr("abcdef", 'f', 6);
	test_ft_memchr("abcdef", 'f', 5);
	test_ft_memchr("abcdef", 'x', 7);
	test_ft_memchr("abcdef", 'a', 0);
	test_ft_memchr("1 2 3 4", ' ', 7);
	test_ft_memchr("abc", '\0', 4);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
