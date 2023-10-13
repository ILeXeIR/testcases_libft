#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_putendl_fd(char *s)
{
	int		fd;
	int		len;
	char	str[10] = "";

	test_counter += 1;
	fd = open("testfile.txt", O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		printf("\tFAILED test '%d'. Can't open testfile.txt\n", test_counter);
		return (1);
	}
	ft_putendl_fd(s, fd);
	close(fd);
	fd = open("testfile.txt", O_RDONLY);
	len = read(fd, str, strlen(s) + 1);
	close(fd);
	if (len == (strlen(s) + 1) && strncmp(str, s, len - 1) == 0 && str[len - 1] == '\n')
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_putendl_fd(void)
{
	printf("TEST 'ft_putendl_fd' started:\n");
	test_ft_putendl_fd("abcd");
	test_ft_putendl_fd("12345");
	test_ft_putendl_fd("\n");
	test_ft_putendl_fd("");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
