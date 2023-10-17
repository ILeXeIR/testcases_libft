#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strmapi(char *s, char (*f)(unsigned int, char), char *answer)
{
	char	*new_str;

	test_counter += 1;
	new_str = ft_strmapi(s, f);
	if (new_str != NULL && strcmp(new_str, answer) == 0)
	{
		success += 1;
		free(new_str);
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	if (new_str != NULL)
		free(new_str);
	return (1);
}

static char	func_test1(unsigned int n, char c)
{
	if (n % 2 == 1)
		return ('X');
	return (c);
}

static char	func_test2(unsigned int n, char c)
{
	if (n > 3)
		return ('\0');
	return (c);
}

static char	func_test3(unsigned int n, char c)
{
	return ('\0');
}

void	run_testcases_ft_strmapi(void)
{
	printf("TEST 'ft_strmapi' started:\n");
	test_ft_strmapi("abcabc", &func_test1, "aXcXbX");
	test_ft_strmapi("", &func_test1, "");
	test_ft_strmapi("abcabc", &func_test2, "abca");
	test_ft_strmapi("123", &func_test2, "123");
	test_ft_strmapi("abcabc", &func_test3, "");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
