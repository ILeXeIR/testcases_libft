#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_memmove(void *str1, void *str2, int i_dest, int i_src, size_t n)
{
	test_counter += 1;
	ft_memmove(str1 + i_dest, str1 + i_src, n);
	memmove(str2 + i_dest, str2 + i_src, n);
	if (memcmp(str1, str2, 11) == 0)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_memmove(void)
{
	char	str1[11] = "1234567890";
	char	str2[11] = "1234567890";

	printf("TEST 'ft_memmove' started:\n");
	test_ft_memmove(str1, str2, 3, 0, 5);
	test_ft_memmove(str1, str2, 0, 1, 7);
	test_ft_memmove(str1, str2, 0, 0, 10);
	test_ft_memmove(str1, str2, 5, 0, 0);
	test_ft_memmove(str1, str2, 0, 0, 0);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
