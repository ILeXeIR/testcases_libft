#include "test_libft.h"

int	main(void)
{
	run_testcases_ft_atoi();
	run_testcases_ft_bzero();
	run_testcases_ft_calloc();
	run_testcases_ft_isalnum();
	run_testcases_ft_isalpha();
	run_testcases_ft_isascii();
	run_testcases_ft_isdigit();
	run_testcases_ft_isprint();
	run_testcases_ft_itoa();
	run_testcases_ft_memchr();
	run_testcases_ft_memcmp();
	run_testcases_ft_memcpy();
	run_testcases_ft_memmove();
	run_testcases_ft_memset();
	run_testcases_ft_putchar_fd();
	run_testcases_ft_putendl_fd();
	run_testcases_ft_putnbr_fd();
	run_testcases_ft_putstr_fd();
	run_testcases_ft_split();
	run_testcases_ft_strchr();
	run_testcases_ft_strdup();
	run_testcases_ft_striteri();
	run_testcases_ft_strjoin();
	run_testcases_ft_strlcat();
	run_testcases_ft_strlcpy();
	run_testcases_ft_strlen();
	run_testcases_ft_strmapi();
	run_testcases_ft_strncmp();
	run_testcases_ft_strnstr();
	run_testcases_ft_strrchr();
	run_testcases_ft_strtrim();
	run_testcases_ft_substr();
	run_testcases_ft_tolower();
	run_testcases_ft_toupper();
	printf("\nTesting Bonus part:\n");
	run_testcases_ft_lstnew();
	run_testcases_ft_lstadd_front();
	run_testcases_ft_lstsize();
	run_testcases_ft_lstlast();
	run_testcases_ft_lstadd_back();
	run_testcases_ft_lstdelone();
	run_testcases_ft_lstclear();
	run_testcases_ft_lstiter();
	run_testcases_ft_lstmap();
	return (0);
}
