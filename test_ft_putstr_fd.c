#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_putstr_fd(char *s)
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
	ft_putstr_fd(s, fd);
	close(fd);
	fd = open("testfile.txt", O_RDONLY);
	len = read(fd, str, strlen(s) + 1);
	close(fd);
	if (len == strlen(s) && strncmp(str, s, len) == 0)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_putstr_fd(void)
{
	printf("TEST 'ft_putstr_fd' started:\n");
	test_ft_putstr_fd("abcd");
	test_ft_putstr_fd("12345");
	test_ft_putstr_fd("\n");
	test_ft_putstr_fd("");
	printf("%d/%d tests were successful.\n", success, test_counter);
}
