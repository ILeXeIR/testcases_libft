#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_itoa(int c, char *res)
{
	char	*str;

	test_counter += 1;
	str = ft_itoa(c);
	if (strcmp(str, res) == 0)
	{
		success += 1;
		free(str);
		return (0);
	}
	free(str);
	printf("\tFAILED with '%d'.\n", c);
	return (1);
}

void	run_testcases_ft_itoa(void)
{
	int		i = 0;
	int		arguments[] = {0, 1, -5, 2147483647, -2147483648};
	char	*results[] = {"0", "1", "-5", "2147483647", "-2147483648"};

	printf("TEST 'ft_itoa' started:\n");
	while (i < 5)
	{
		test_ft_itoa(arguments[i], results[i]);
		i++;
	}
	printf("%d/%d tests were successful.\n", success, test_counter);
}
