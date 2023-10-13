#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_memset(void *dest1, void *dest2, int c, size_t n)
{
	test_counter += 1;
	ft_memset(dest1, c, n);
	memset(dest2, c, n);
	if (n == 0)
		n = 1;
	if (memcmp(dest1, dest2, n) == 0)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_memset(void)
{
	char	str1[11] = "xxxxxxxxxx";
	char	str2[11] = "yyyyyyyyyy";

	printf("TEST 'ft_memset' started:\n");
	test_ft_memset(str1, str2, '1', 1);
	test_ft_memset(str1, str2, '0', 0);
	test_ft_memset(str1, str2, '\0', 2);
	test_ft_memset(str1, str2, 200, 3);
	test_ft_memset(str1, str2, ' ', 4);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
