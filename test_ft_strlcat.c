#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_strlcat(char *dst1, char *dst2, char *src, size_t size)
{
	test_counter += 1;
	strcpy(dst2, dst1);
	if (ft_strlcat(dst1, src, size) == strlcat(dst2, src, size)
		&& strcmp(dst1, dst2) == 0)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_strlcat(void)
{
	char	dst1[20] = "xxxxx";
	char	dst2[20];

	printf("TEST 'ft_strlcat' started:\n");
	test_ft_strlcat(dst1, dst2, "123", 20);
	test_ft_strlcat(dst1, dst2, "456", 10);
	test_ft_strlcat(dst1, dst2, "789", 5);
	test_ft_strlcat(dst1, dst2, "", 5);
	test_ft_strlcat(dst1, dst2, "", 20);
	test_ft_strlcat(dst1, dst2, "abc", 0);
	strcpy(dst1, "");
	test_ft_strlcat(dst1, dst2, "", 0);
	test_ft_strlcat(dst1, dst2, "asd", 0);
	test_ft_strlcat(dst1, dst2, "asd", 2);
	strcpy(dst1, "");
	test_ft_strlcat(dst1, dst2, "yyyyy", 6);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
