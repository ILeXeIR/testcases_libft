#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_memcmp(const void *s1, const void *s2, size_t n)
{
	test_counter += 1;
	if (ft_memcmp(s1, s2, n) == memcmp(s1, s2, n))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%s', '%s', '%zu'.\n", (char *)s1, (char *)s2, n);
	return (1);
}

void	run_testcases_ft_memcmp(void)
{
	int		arr1[] = {1, 2, 3};
	int		arr2[] = {1, 2, 0};

	printf("TEST 'ft_memcmp' started:\n");
	test_ft_memcmp("abcdef", "abcdef", 7);
	test_ft_memcmp("abcdef", "abcde1", 6);
	test_ft_memcmp("abcdef", "abcde1", 5);
	test_ft_memcmp("abcdef", "abcdef", 0);
	test_ft_memcmp("a", "b", 0);
	test_ft_memcmp("", "", 0);
	test_ft_memcmp("1", "", 0);
	test_ft_memcmp("1", "", 1);
	test_ft_memcmp(arr1, arr2, 8);
	test_ft_memcmp(arr1, arr2, 12);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
