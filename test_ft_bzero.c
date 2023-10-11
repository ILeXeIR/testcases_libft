#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_bzero_0(void)
{
	char	str1[11] = "xxxxxxxxxx";
	char	str2[11] = "xxxxxxxxxx";

	test_counter += 1;
	ft_bzero(str1 + 2, 3);
	bzero(str2 + 2, 3);
	if (memcmp(str1, str2, 11) == 0)
	{
		success += 1;
		return (0);
	}
	printf("FAILED test 0.\n");
	return (1);
}

int	test_ft_bzero_1(void)
{
	char	str1[11] = "xxxxxxxxxx";
	char	str2[11] = "xxxxxxxxxx";

	test_counter += 1;
	ft_bzero(str1, 0);
	bzero(str2, 0);
	if (memcmp(str1, str2, 11) == 0)
	{
		success += 1;
		return (0);
	}
	printf("FAILED test 1.\n");
	return (1);
}

void	run_testcases_ft_bzero(void)
{
	printf("TEST 'ft_bzero' started:\n");
	test_ft_bzero_0();
	test_ft_bzero_1();
	printf("%d/%d tests were successful.\n", success, test_counter);
}
