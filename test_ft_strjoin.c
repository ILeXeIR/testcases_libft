#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strjoin(char *s1, char *s2)
{
	char	*dst;

	test_counter += 1;
	dst = ft_strjoin(s1, s2);
	if (strncmp(dst, s1, strlen(s1)) == 0 && strcmp(dst + strlen(s1), s2) == 0)
	{
		success += 1;
		free(dst);
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	free(dst);
	return (1);
}

void	run_testcases_ft_strjoin(void)
{
	printf("TEST 'ft_strjoin' started:\n");
	test_ft_strjoin("abcd", "123");
	test_ft_strjoin("", "");
	test_ft_strjoin("abcd", "");
	test_ft_strjoin("", "123");
	test_ft_strjoin("\n", " ");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
