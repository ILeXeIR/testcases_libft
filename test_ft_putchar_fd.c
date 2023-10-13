#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

int	test_ft_putchar_fd(char c)
{
	int		fd;
	int		len;
	char	str[1];

	test_counter += 1;
	fd = open("testfile.txt", O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		printf("\tFAILED test '%d'. Can't open testfile.txt\n", test_counter);
		return (1);
	}
	ft_putchar_fd(c, fd);
	close(fd);
	fd = open("testfile.txt", O_RDONLY);
	len = read(fd, str, 1);
	close(fd);
	if (len == 1 && *str == c)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test '%d'.\n", test_counter);
	return (1);
}

void	run_testcases_ft_putchar_fd(void)
{
	printf("TEST 'ft_putchar_fd' started:\n");
	test_ft_putchar_fd('A');
	test_ft_putchar_fd('\n');
	test_ft_putchar_fd(' ');
	printf("%d/%d tests were successful.\n", success, test_counter);
}
