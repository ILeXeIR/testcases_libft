#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strlcpy(char *dst1, char *dst2, char *src, size_t size)
{
	test_counter += 1;
	if (ft_strlcpy(dst1, src, size) == strlcpy(dst2, src, size)
		&& strcmp(dst1, dst2) == 0)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_strlcpy(void)
{
	char	dst1[] = "xxxxxxxxxxxxxxxx";
	char	dst2[] = "xxxxxxxxxxxxxxxx";

	printf("TEST 'ft_strlcpy' started:\n");
	test_ft_strlcpy(dst1, dst2, "abcdef", 1);
	test_ft_strlcpy(dst1, dst2, "abcdef", 2);
	test_ft_strlcpy(dst1, dst2, "", 5);
	test_ft_strlcpy(dst1, dst2, "abcdef", 6);
	test_ft_strlcpy(dst1, dst2, "", 0);
	test_ft_strlcpy(dst1, dst2, "1234567890", 15);
	test_ft_strlcpy(dst1, dst2, "qwe", 0);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
