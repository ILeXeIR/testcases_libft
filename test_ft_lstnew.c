#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_lstnew(void *content)
{
	t_list	*lst;

	test_counter += 1;
	lst = ft_lstnew(content);
	if (lst != NULL && lst->content == content && lst->next == NULL)
	{
		success += 1;
		free(lst);
		return (0);
	}
	if (lst != NULL)
		free(lst);
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_lstnew(void)
{
	printf("TEST 'ft_lstnew' started:\n");
	test_ft_lstnew("asdfg");
	test_ft_lstnew(NULL);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
