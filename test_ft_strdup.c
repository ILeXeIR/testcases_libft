#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

static void	free_strings(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
}

int	test_ft_strdup(char *s)
{
	char	*dst1;
	char	*dst2;

	test_counter += 1;
	dst1 = ft_strdup(s);
	dst2 = strdup(s);
	if (dst1 != NULL && dst2 != NULL && strcmp(dst1, dst2) == 0)
	{
		success += 1;
		free_strings(dst1, dst2);
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	free_strings(dst1, dst2);
	return (1);
}

void	run_testcases_ft_strdup(void)
{
	printf("TEST 'ft_strdup' started:\n");
	test_ft_strdup("akad\n  shfih ads");
	test_ft_strdup("");
	test_ft_strdup("akadsh\0fihads");
	test_ft_strdup("0");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
