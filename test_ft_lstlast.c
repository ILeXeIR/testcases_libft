#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

void	test_ft_lstlast(void)
{
	t_list	*lst;
	t_list	*node;
	int		size;

	size = 0;
	while (size < 3)
	{
		test_counter += 1;
		if (size == 0)
		{
			lst = ft_lstnew("");
			node = lst;
		}
		else
			ft_lstadd_front(&lst, ft_lstnew(""));
		size += 1;
		if (ft_lstlast(lst) == node)
			success += 1;
		else
			printf("\tFAILED test '%d'.\n", test_counter);
	}
	while (lst != NULL)
	{
		node = lst;
		lst = lst->next;
		free(node);
	}
}

void	run_testcases_ft_lstlast(void)
{
	printf("TEST 'ft_lstlast' started:\n");
	test_ft_lstlast();
	printf("%d/%d tests were successful.\n", success, test_counter);
}
