#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

static int	get_fail(void)
{
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

static int	get_success(void)
{
	success += 1;
	return (0);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

static int	arr_cmp(char **arr1, char **arr2)
{
	int	i;

	i = 0;
	while (arr1[i] != NULL && arr2[i] != NULL && strcmp(arr1[i], arr2[i]) == 0)
		i++;
	if (arr1[i] == arr2[i])
	{
		free_arr(arr1);
		return (0);
	}
	free_arr(arr1);
	return (1);
}

int	test_ft_split(char const *s, char c, char **answer)
{
	char	**result;

	test_counter += 1;
	result = ft_split(s, c);
	if (result == NULL && answer == NULL)
		return (get_success());
	else if (result == NULL || answer == NULL)
	{
		if (result != NULL)
			free_arr(result);
		return (get_fail());
	}
	if (arr_cmp(result, answer) == 0)
		return (get_success());
	return (get_fail());
}

void	run_testcases_ft_split(void)
{
	printf("TEST 'ft_split' started:\n");

	char	*answer0[] = {NULL};
	test_ft_split("", 'a', answer0);
	test_ft_split("aaaaa", 'a', answer0);

	char	*answer1[] = {"123"};
	test_ft_split("123", '4', answer1);
	test_ft_split("---123---", '-', answer1);

	char	*answer2[] = {"adkh", "d", "c\n\nf!", "11", NULL};
	test_ft_split("adkh d c\n\nf!   11", ' ', answer2);
	test_ft_split("   adkh d c\n\nf!   11   ", ' ', answer2);

	char	*answer3[] = {"  ", " ", " ", NULL};
	test_ft_split("\n\n  \n \n\n \n", '\n', answer3);

	printf("%d/%d tests were successful.\n", success, test_counter);
}
