#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_striteri(char *s, void (*f)(unsigned int, char*), char *answer)
{
	test_counter += 1;
	ft_striteri(s, f);
	if (strcmp(s, answer) == 0)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

static void	func_test1(unsigned int n, char *s)
{
	if (n % 2 == 1)
		*s = 'X';
}

static void	func_test2(unsigned int n, char *s)
{
	if (n > 3)
		*s = '\0';
}

void	run_testcases_ft_striteri(void)
{
	char	s[10] = "abcabc";

	printf("TEST 'ft_striteri' started:\n");
	test_ft_striteri(s, &func_test1, "aXcXbX");
	strcpy(s, "");
	test_ft_striteri(s, &func_test1, "");
	strcpy(s, "abcabc");
	test_ft_striteri(s, &func_test2, "abca");
	strcpy(s, "123");
	test_ft_striteri(s, &func_test2, "123");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
