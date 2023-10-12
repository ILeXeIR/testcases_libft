#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_memcpy(void *dest1, void *dest2, const void *src, size_t n)
{
	test_counter += 1;
	ft_memcpy(dest1, src, n);
	memcpy(dest2, src, n);
	if (memcmp(dest1, dest2, 10) == 0)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%s', '%zu'.\n", (char *)src, n);
	return (1);
}

void	run_testcases_ft_memcpy(void)
{
	char	dest1[10];
	char	dest2[10];

	printf("TEST 'ft_memcpy' started:\n");
	test_ft_memcpy(dest1, dest2, "xxxxxxxxx", 10);
	test_ft_memcpy(dest1, dest2, "\0\0\0\0\0\0\0\0\0", 10);
	test_ft_memcpy(dest1, dest2, "yyyyyyyyy", 10);
	test_ft_memcpy(dest1, dest2, "zzzzzzzzz", 0);
	test_ft_memcpy(dest1, dest2, "aaaaaaaaa", 3);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
