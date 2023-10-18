#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

static void	func_test(void *ptr)
{
	int	*num;

	num = ptr;
	*num *= 2;
}

void	test_ft_lstiter(void)
{
	t_list	*lst;
	t_list	*node;
	int		i;
	int		arr[] = {1, 2, 3, 4};

	test_counter += 1;
	i = 0;
	lst = ft_lstnew(arr);
	while (i < 3)
	{
		i += 1;
		ft_lstadd_back(&lst, ft_lstnew(arr + i));
	}
	ft_lstiter(lst, &func_test);
	i = 1;
	success = 1;
	while (i < 5)
	{
		if (*(int *)(lst->content) != i * 2)
			success = 0;
		node = lst;
		lst = lst->next;
		free(node);
		i++;
	}
	if (success == 0)
		printf("\tFAILED test '%d'.\n", test_counter);
}

void	run_testcases_ft_lstiter(void)
{
	printf("TEST 'ft_lstiter' started:\n");
	test_ft_lstiter();
	printf("%d/%d tests were successful.\n", success, test_counter);
}
