#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strrchr(char *s, int c)
{
	test_counter += 1;
	if (ft_strrchr(s, c) == strrchr(s, c))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_strrchr(void)
{
	printf("TEST 'ft_strrchr' started:\n");
	test_ft_strrchr("akadshfihads", 'd');
	test_ft_strrchr("akadshfihads", 'a');
	test_ft_strrchr("akadshfihads", 'A');
	test_ft_strrchr("", 'A');
	test_ft_strrchr("akadshfihads", 'd' + 512);
	test_ft_strrchr("akadshfihads", 'A' + 256);
	test_ft_strrchr("akadshfihads", '\0');
	test_ft_strrchr("", '\0');
	printf("%d/%d tests were successful.\n", success, test_counter);
}
