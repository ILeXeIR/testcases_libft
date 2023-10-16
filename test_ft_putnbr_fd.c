#include "test_libft.h"

static int	test_counter = 0;
static int	success = 0;

static int	get_num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	test_ft_putnbr_fd(int n)
{
	int		fd;
	int		str_len;
	int		n_len;
	char	str[12] = "";

	test_counter += 1;
	fd = open("testfile.txt", O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		printf("\tFAILED test '%d'. Can't open testfile.txt\n", test_counter);
		return (1);
	}
	ft_putnbr_fd(n, fd);
	close(fd);
	fd = open("testfile.txt", O_RDONLY);
	n_len = get_num_len(n);
	str_len = read(fd, str, 12);
	close(fd);
	if (n_len == str_len && atoi(str) == n)
	{
		success += 1;
		return (0);
	}
	printf("\tFAILED test with '%d'.\n", n);
	return (1);
}

void	run_testcases_ft_putnbr_fd(void)
{
	printf("TEST 'ft_putnbr_fd' started:\n");
	test_ft_putnbr_fd(0);
	test_ft_putnbr_fd(7);
	test_ft_putnbr_fd(-3);
	test_ft_putnbr_fd(2147483647);
	test_ft_putnbr_fd(-2147483648);
	printf("%d/%d tests were successful.\n", success, test_counter);
}
