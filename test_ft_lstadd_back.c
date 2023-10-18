#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

void	test_ft_lstadd_back(void)
{
	t_list	**lst;
	t_list	*first_node;
	t_list	*node;
	int		size;

	size = 1;
	first_node = ft_lstnew("");
	lst = &first_node;
	while (size < 4)
	{
		test_counter += 1;
		node = ft_lstnew("");
		ft_lstadd_back(lst, node);
		size += 1;
		if (ft_lstlast(*lst) == node && ft_lstsize(*lst) == size)
			success += 1;
		else
			printf("\tFAILED test '%d'.\n", test_counter);
	}
	while (*lst != NULL)
	{
		node = first_node;
		first_node = first_node->next;
		free(node);
	}
}

void	run_testcases_ft_lstadd_back(void)
{
	printf("TEST 'ft_lstadd_back' started:\n");
	test_ft_lstadd_back();
	printf("%d/%d tests were successful.\n", success, test_counter);
}
