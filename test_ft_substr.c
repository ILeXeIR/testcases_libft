#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_substr(char *s, unsigned int start, size_t len, char *answer)
{
	char	*dst;

	test_counter += 1;
	dst = ft_substr(s, start, len);
	if (dst != NULL && strcmp(dst, answer) == 0)
	{
		success += 1;
		free(dst);
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	if (dst != NULL)
		free(dst);
	return (1);
}

int	test_ft_substr_null(char *s, unsigned int start)
{
	char	*dst;

	test_counter += 1;
	dst = ft_substr(s, start, 10000000000000000);
	if (dst == NULL)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test NULL.\n");
	free(dst);
	return (1);
}

void	run_testcases_ft_substr(void)
{
	printf("TEST 'ft_substr' started:\n");
	test_ft_substr("Abcdef", 0, 10, "Abcdef");
	test_ft_substr("", 0, 10, "");
	test_ft_substr("", 0, 0, "");
	test_ft_substr("", 5, 10, "");
	test_ft_substr("Abcdef", 0, 3, "Abc");
	test_ft_substr("Abcdef", 3, 2, "de");
	test_ft_substr("Abcdef\0xxxxx", 5, 10, "f");
	test_ft_substr("Abcdef", 0, 0, "");
	test_ft_substr("Abcdef", 10, 10, "");
	test_ft_substr_null("Abcdef", 0);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
