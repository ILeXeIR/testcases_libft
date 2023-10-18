#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

static void	del_func(void *ptr)
{
	free(ptr);
}

int	test_ft_lstclear(void)
{
	t_list	*first_node;
	t_list	*node;
	void	*ptr;
	int		i;

	test_counter += 1;
	i = 0;
	first_node = ft_lstnew("");
	node = first_node;
	while (i < 3)
	{
		ptr = malloc(10);
		node->next = ft_lstnew(ptr);
		node = node->next;
		i++;
	}
	ft_lstclear(&(first_node->next), &del_func);
	if (first_node->next == NULL)
	{
		success += 1;
		free(first_node);
		return (0);
	}
	if (first_node != NULL)
		free(first_node);
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_lstclear(void)
{
	printf("TEST 'ft_lstclear' started:\n");
	test_ft_lstclear();
	printf("\tYou should use 'valgrind' to check memory leaks.\n");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
