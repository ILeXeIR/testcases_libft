#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_lstadd_front(void)
{
	t_list	**lst;
	t_list	*first_node;
	t_list	*node1;
	t_list	*node2;
	t_list	*new;
	char	*s1 = "abc";
	char	*s2 = "123";
	char	*s_new = "xxx";

	test_counter += 1;
	node1 = ft_lstnew(s1);
	first_node = node1;
	node2 = ft_lstnew(s2);
	new = ft_lstnew(s_new);
	lst = &first_node;
	node1->next = node2;
	ft_lstadd_front(lst, new);
	if (*lst == new && new->content == s_new && new->next == node1
		&& node1->content == s1 && node1->next == node2 && node2->next == NULL)
	{
		success += 1;
		free(node1);
		free(node2);
		free(new);
		return (0);
	}
	if (node1 != NULL)
		free(node1);
	if (node2 != NULL)
		free(node2);
	if (new != NULL)
		free(new);
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_lstadd_front(void)
{
	printf("TEST 'ft_lstadd_front' started:\n");
	test_ft_lstadd_front();
	printf("%d/%d tests were successful.\n", success, test_counter);
}
