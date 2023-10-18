#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

void	test_ft_lstsize(void)
{
	t_list	*lst;
	t_list	*temp;
	int		size;

	size = 0;
	while (size < 5)
	{
		test_counter += 1;
		if (size == 0)
			lst = ft_lstnew("");
		else
			ft_lstadd_front(&lst, ft_lstnew(""));
		size += 1;
		if (ft_lstsize(lst) == size)
			success += 1;
		else
			printf("\tFAILED test '%d'.\n", test_counter);
	}
	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void	run_testcases_ft_lstsize(void)
{
	printf("TEST 'ft_lstsize' started:\n");
	test_ft_lstsize();
	printf("%d/%d tests were successful.\n", success, test_counter);
}
