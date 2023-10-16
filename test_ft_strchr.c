#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strchr(char *s, int c)
{
	test_counter += 1;
	if (ft_strchr(s, c) == strchr(s, c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_strchr(void)
{
	printf("TEST 'ft_strchr' started:\n");
	test_ft_strchr("akadshfihads", 'd');
	test_ft_strchr("akadshfihads", 'a');
	test_ft_strchr("akadshfihads", 'A');
	test_ft_strchr("", 'A');
	test_ft_strchr("akadshfihads", 'd' + 512);
	test_ft_strchr("akadshfihads", 'A' + 256);
	test_ft_strchr("akadshfihads", '\0');
	test_ft_strchr("", '\0');
	printf("%d/%d tests were successful.\n", success, test_counter);
}
