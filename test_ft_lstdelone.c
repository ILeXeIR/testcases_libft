#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

static void	del_func(void *ptr)
{
	free(ptr);
}

int	test_ft_lstdelone(void)
{
	t_list	*node1;
	t_list	*node2;
	void	*ptr;
	char	*str;

	test_counter += 1;
	ptr = malloc(10);
	str = "abc";
	node1 = ft_lstnew(ptr);
	node2 = ft_lstnew(str);
	node1->next = node2;
	ft_lstdelone(node1, &del_func);
	if (node2 != NULL && node2->content == str)
	{
		success += 1;
		free(node2);
		return (0);
	}
	if (node2 != NULL)
		free(node2);
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_lstdelone(void)
{
	printf("TEST 'ft_lstdelone' started:\n");
	test_ft_lstdelone();
	printf("\tYou should use 'valgrind' to check memory leaks.\n");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
