#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_atoi(char *s)
{
	test_counter += 1;
	if (ft_atoi(s) == atoi(s))
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED with '%s'.\n", s);
	return (1);
}

void	run_testcases_ft_atoi(void)
{
	printf("TEST 'ft_atoi' started:\n");
	test_ft_atoi("123");
	test_ft_atoi("-5");
	test_ft_atoi("0");
	test_ft_atoi("");
	test_ft_atoi("a0000124");
	test_ft_atoi("0000125abc");
	test_ft_atoi("-00126");
	test_ft_atoi("+00127");
	test_ft_atoi("-+128");
	test_ft_atoi("+-129");
	test_ft_atoi("\n \t130");
	test_ft_atoi("     -131");
	test_ft_atoi("--132");
	test_ft_atoi("++133");
	test_ft_atoi("2147483647");
	test_ft_atoi("-2147483648");
	test_ft_atoi("-335214726836458");
	printf("%d/%d tests were successful.\n", success, test_counter);
}

// int	main(void)
// {
// 	run_testcases_ft_atoi();
// 	return (0);
// }
