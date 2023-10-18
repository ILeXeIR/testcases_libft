#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

static void	*func_test(void *ptr)
{
	int	num;
	int	*new_ptr;

	new_ptr = ptr;
	num = *new_ptr * 3;
	new_ptr += 4;
	*new_ptr = num;
	return (new_ptr);
}

static void del_int(void *ptr)
{
	*(int *)ptr = 0;
}

void	test_ft_lstmap(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*node;
	int		i;
	int		arr[8] = {1, 2, 3, 4};

	test_counter += 1;
	i = 1;
	lst1 = ft_lstnew(arr);
	while (i < 4)
	{
		ft_lstadd_back(&lst1, ft_lstnew(arr + i));
		i += 1;
	}
	lst2 = ft_lstmap(lst1, &func_test, &del_int);
	node = lst2;
	success = 1;
	i = 1;
	while (i < 5)
	{
		if (*(int *)(node->content) != i * 3)
			success = 0;
		node = node->next;
		i++;
	}
	if (success == 0)
		printf("\tFAILED test '%d'.\n", test_counter);
	ft_lstclear(&lst1, &del_int);
	ft_lstclear(&lst2, &del_int);
}

void	run_testcases_ft_lstmap(void)
{
	printf("TEST 'ft_lstmap' started:\n");
	test_ft_lstmap();
	printf("%d/%d tests were successful.\n", success, test_counter);
}
