#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_calloc_0(void)
{
	char	*str1;
	char	*str2;
	int		res;

	test_counter += 1;
	str1 = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));
	res = memcmp(str1, str2, 10 * sizeof(char));
	free(str1);
	free(str2);
	if (res == 0)
	{
		success += 1;
		return (0);
	}
	printf("FAILED test 0.\n");
	return (1);
}

int	test_ft_calloc_1(void)
{
	char		*str1;
	char		*str2;
	int			res;
	long long	size;

	test_counter += 1;
	size = 1000000000000000000;
	str1 = ft_calloc(10, size);
	str2 = calloc(10, size);
	if (str1 == str2 && str1 == NULL)
	{
		success += 1;
		return (0);
	}
	printf("FAILED test 1.\n");
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (1);
}

void	run_testcases_ft_calloc(void)
{
	printf("TEST 'ft_calloc' started:\n");
	test_ft_calloc_0();
	test_ft_calloc_1();
	printf("%d/%d tests were successful.\n", success, test_counter);
}
