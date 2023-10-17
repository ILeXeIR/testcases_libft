#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strtrim(char *s1, char *set, char *answer)
{
	char	*dst;

	test_counter += 1;
	dst = ft_strtrim(s1, set);
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

void	run_testcases_ft_strtrim(void)
{
	printf("TEST 'ft_strtrim' started:\n");
	test_ft_strtrim("31231aba123cd12111", "123", "aba123cd");
	test_ft_strtrim("31231aba123cd12111", "321", "aba123cd");
	test_ft_strtrim("31231aba123cd12111", "ab", "31231aba123cd12111");
	test_ft_strtrim("31231aba123cd12111", "", "31231aba123cd12111");
	test_ft_strtrim("31231aba123cd12111", "111111", "31231aba123cd12");
	test_ft_strtrim("31231aba123\0cd12111", "123", "aba");
	test_ft_strtrim("", "123", "");
	test_ft_strtrim("3132132", "123", "");
	test_ft_strtrim("\n", " ", "\n");
	test_ft_strtrim("", "", "");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
