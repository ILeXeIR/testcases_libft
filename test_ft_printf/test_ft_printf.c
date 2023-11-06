#include "../../ft_printf/ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	assert_values(int x1, int x2)
{
	if (x1 != x2)
		ft_printf("FAIL\nReturned values: custom %d:%d original.\n\n", x1, x2);
	else
		ft_printf("\n");
}

void	test_ft_printf(void)
{
	int	x1;
	int	x2;

	ft_printf("Mandatory part tests:\n");

	x1 = ft_printf(NULL);
	x2 = printf(NULL);
	assert_values(x1, x2);
	x1 = ft_printf("Hello!\n");
	x2 = printf("Hello!\n");
	assert_values(x1, x2);
	x1 = ft_printf("");
	x2 = printf("");
	assert_values(x1, x2);

	ft_printf("Test c:\n");
	x1 = ft_printf("%c!\n", 'a');
	x2 = printf("%c!\n", 'a');
	assert_values(x1, x2);
	x1 = ft_printf("%c!\n", '\200');
	x2 = printf("%c!\n", '\200');
	assert_values(x1, x2);
	x1 = ft_printf("%c!\n", 0);
	x2 = printf("%c!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("<%c>!\n", '\n');
	x2 = printf("<%c>!\n", '\n');
	assert_values(x1, x2);

	ft_printf("Test S:\n");
	x1 = ft_printf("%s!\n", "");
	x2 = printf("%s!\n", "");
	assert_values(x1, x2);
	x1 = ft_printf("$$$%s!\n", "abc");
	x2 = printf("$$$%s!\n", "abc");
	assert_values(x1, x2);
	x1 = ft_printf("%s!\n", NULL);
	x2 = printf("%s!\n", (char *) NULL);
	assert_values(x1, x2);

	ft_printf("Test u:\n");
	x1 = ft_printf("%u!\n", 0);
	x2 = printf("%u!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("__%u__!\n", 3147483647);
	x2 = printf("__%u__!\n", (unsigned int)3147483647);
	assert_values(x1, x2);

	ft_printf("Test x:\n");
	x1 = ft_printf("%x!\n", 0);
	x2 = printf("%x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("__%x__!\n", 3147483647);
	x2 = printf("__%x__!\n", (unsigned int)3147483647);
	assert_values(x1, x2);

	ft_printf("Test X:\n");
	x1 = ft_printf("%X!\n", 0);
	x2 = printf("%X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("__%X__!\n", 3147483647);
	x2 = printf("__%X__!\n", (unsigned int)3147483647);
	assert_values(x1, x2);

	ft_printf("Test p:\n");
	x1 = ft_printf("%p!\n", NULL);
	x2 = printf("%p!\n", NULL);
	assert_values(x1, x2);
	x1 = ft_printf("__%p__!\n", "abc");
	x2 = printf("__%p__!\n", "abc");
	assert_values(x1, x2);
	x1 = ft_printf("__%p__!\n", &malloc);
	x2 = printf("__%p__!\n", &malloc);
	assert_values(x1, x2);
	x1 = ft_printf("__%p__!\n", &x1);
	x2 = printf("__%p__!\n", &x1);
	assert_values(x1, x2);
	x1 = ft_printf("__%p__!\n", ULONG_MAX);
	x2 = printf("__%p__!\n", (void *)ULONG_MAX);
	assert_values(x1, x2);
	x1 = ft_printf("__%p__!\n", LONG_MIN);
	x2 = printf("__%p__!\n", (void *)LONG_MIN);
	assert_values(x1, x2);
	x1 = ft_printf("__%p__!\n", UINT_MAX);
	x2 = printf("__%p__!\n", (void *)UINT_MAX);
	assert_values(x1, x2);
	x1 = ft_printf("__%p__!\n", (unsigned long)UINT_MAX + 1);
	x2 = printf("__%p__!\n", (void *)((unsigned long)UINT_MAX + 1));
	assert_values(x1, x2);

	ft_printf("Test d:\n");
	x1 = ft_printf("%d!\n", 0);
	x2 = printf("%d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("__%d__%d!\n", -2147483648, 2147483647);
	x2 = printf("__%d__%d!\n", (int)-2147483648, 2147483647);
	assert_values(x1, x2);

	ft_printf("Test i:\n");
	x1 = ft_printf("%i!\n", 0);
	x2 = printf("%i!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("__%i__%i!\n", -2147483648, 2147483647);
	x2 = printf("__%i__%i!\n", (int)-2147483648, 2147483647);
	assert_values(x1, x2);

	ft_printf("Test %%:\n");
	x1 = ft_printf("%%!\n");
	x2 = printf("%%!\n");
	assert_values(x1, x2);
	x1 = ft_printf("%!\n");
	x2 = printf("%!\n");
	assert_values(x1, x2);
	x1 = ft_printf("%%d!\n", 5);
	x2 = printf("%%d!\n", 5);
	assert_values(x1, x2);

	ft_printf("Mixed test:\n");
	x1 = ft_printf("%%%d!\n", 5);
	x2 = printf("%%%d!\n", 5);
	assert_values(x1, x2);
	x1 = ft_printf("S:%d%c:%s%i%x:%X%p:%%!\n", 0, '0', "11", 11, 11, 0xFF, "FF", "ERROR");
	x2 = printf("S:%d%c:%s%i%x:%X%p:%%!\n", 0, '0', "11", 11, 11, 0xFF, "FF", "ERROR");
	assert_values(x1, x2);
	x1 = ft_printf("S:%d%c:%s%i%x:%X%p:%%!\n", 0, 0, "11\0XXX", 11, 11, 0xFF, "FF", "ERROR");
	x2 = printf("S:%d%c:%s%i%x:%X%p:%%!\n", 0, 0, "11\0XXX", 11, 11, 0xFF, "FF", "ERROR");
	assert_values(x1, x2);


	ft_printf("Bonus part tests:\n");

	ft_printf("Test c:\n");
	x1 = ft_printf("%3c!%-5c!\n", 'a', 'b', 'c');
	x2 = printf("%3c!%-5c!\n", 'a', 'b', 'c');
	assert_values(x1, x2);
	x1 = ft_printf("%--7c!\n", 'a');
	x2 = printf("%--7c!\n", 'a');
	assert_values(x1, x2);
	
	ft_printf("Test s:\n");
	x1 = ft_printf("%10.5s!\n", "abcdefghijklmnop");
	x2 = printf("%10.5s!\n", "abcdefghijklmnop");
	assert_values(x1, x2);
	x1 = ft_printf("%10.0s!\n", "abcdefghijklmnop");
	x2 = printf("%10.0s!\n", "abcdefghijklmnop");
	assert_values(x1, x2);
	x1 = ft_printf("%.s!\n", "abcdefghijklmnop");
	x2 = printf("%.s!\n", "abcdefghijklmnop");
	assert_values(x1, x2);
	x1 = ft_printf("%.25s!\n", "abcdefghijklmnop");
	x2 = printf("%.25s!\n", "abcdefghijklmnop");
	assert_values(x1, x2);
	x1 = ft_printf("%-10s!%10s!\n", "abc", "def");
	x2 = printf("%-10s!%10s!\n", "abc", "def");
	assert_values(x1, x2);
	x1 = ft_printf("%-10s%c\n", "abc", '!');
	x2 = printf("%-10s%c\n", "abc", '!');
	assert_values(x1, x2);
	x1 = ft_printf("%-10s!\n", NULL);
	x2 = printf("%-10s!\n", (char *) NULL);
	assert_values(x1, x2);
	x1 = ft_printf("%.5s!\n", NULL);
	x2 = printf("%.5s!\n", (char *) NULL);
	assert_values(x1, x2);
	x1 = ft_printf("%10.6s!\n", NULL);
	x2 = printf("%10.6s!\n", (char *) NULL);
	assert_values(x1, x2);
	
	ft_printf("Test u:\n");
	x1 = ft_printf("%-10u!\n", 0xFFFFFFFF);
	x2 = printf("%-10u!\n", 0xFFFFFFFF);
	assert_values(x1, x2);
	x1 = ft_printf("%-010u!\n", 42);
	x2 = printf("%-010u!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%010u!\n", 42);
	x2 = printf("%010u!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%-10.5u!\n", 42);
	x2 = printf("%-10.5u!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%010.5u!\n", 42);
	x2 = printf("%010.5u!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%.2u!\n", 42345);
	x2 = printf("%.2u!\n", 42345);
	assert_values(x1, x2);
	x1 = ft_printf("%5u!\n", 0);
	x2 = printf("%5u!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%05u!\n", 0);
	x2 = printf("%05u!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%5.u!\n", 0);
	x2 = printf("%5.u!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%0-10u!\n", 42);
	x2 = printf("%0-10u!\n", 42);
	assert_values(x1, x2);

	ft_printf("Test x:\n");
	x1 = ft_printf("%-10x!\n", 0x1A2B3C);
	x2 = printf("%-10x!\n", 0x1A2B3C);
	assert_values(x1, x2);
	x1 = ft_printf("%-010x!\n", 0xD0E9F8);
	x2 = printf("%-010x!\n", 0xD0E9F8);
	assert_values(x1, x2);
	x1 = ft_printf("%010x!\n", 0xFFFFFFFF);
	x2 = printf("%010x!\n", 0xFFFFFFFF);
	assert_values(x1, x2);
	x1 = ft_printf("%-10.5x!\n", 42);
	x2 = printf("%-10.5x!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%010.5x!\n", 42);
	x2 = printf("%010.5x!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%.2x!\n", 42345);
	x2 = printf("%.2x!\n", 42345);
	assert_values(x1, x2);
	x1 = ft_printf("%5x!\n", 0);
	x2 = printf("%5x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%-5x!\n", 0);
	x2 = printf("%-5x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%05x!\n", 0);
	x2 = printf("%05x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%5.x!\n", 0);
	x2 = printf("%5.x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%#-10x!\n", 42);
	x2 = printf("%#-10x!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%0#10x!\n", 42);
	x2 = printf("%0#10x!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%-#10.5x!\n", 42);
	x2 = printf("%-#10.5x!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%#010.5x!\n", 42);
	x2 = printf("%#010.5x!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%#.2x!\n", 42345);
	x2 = printf("%#.2x!\n", 42345);
	assert_values(x1, x2);
	x1 = ft_printf("%#5x!\n", 0);
	x2 = printf("%#5x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%#-5x!\n", 0);
	x2 = printf("%#-5x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%0#5x!\n", 0);
	x2 = printf("%0#5x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%#5.x!\n", 0);
	x2 = printf("%#5.x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%#1.x!\n", 0);
	x2 = printf("%#1.x!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%0-#10x!\n", 42);
	x2 = printf("%0-#10x!\n", 42);
	assert_values(x1, x2);

	ft_printf("Test X:\n");
	x1 = ft_printf("%-10X!\n", 0x1A2B3C);
	x2 = printf("%-10X!\n", 0x1A2B3C);
	assert_values(x1, x2);
	x1 = ft_printf("%-010X!\n", 0xD0E9F8);
	x2 = printf("%-010X!\n", 0xD0E9F8);
	assert_values(x1, x2);
	x1 = ft_printf("%010X!\n", 0xFFFFFFFF);
	x2 = printf("%010X!\n", 0xFFFFFFFF);
	assert_values(x1, x2);
	x1 = ft_printf("%-10.5X!\n", 42);
	x2 = printf("%-10.5X!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%010.5X!\n", 42);
	x2 = printf("%010.5X!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%.2X!\n", 42345);
	x2 = printf("%.2X!\n", 42345);
	assert_values(x1, x2);
	x1 = ft_printf("%5X!\n", 0);
	x2 = printf("%5X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%-5X!\n", 0);
	x2 = printf("%-5X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%05X!\n", 0);
	x2 = printf("%05X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%5.X!\n", 0);
	x2 = printf("%5.X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%#-10X!\n", 42);
	x2 = printf("%#-10X!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%0#10X!\n", 42);
	x2 = printf("%0#10X!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%-#10.5X!\n", 42);
	x2 = printf("%-#10.5X!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%#010.5X!\n", 42);
	x2 = printf("%#010.5X!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%#.2X!\n", 42345);
	x2 = printf("%#.2X!\n", 42345);
	assert_values(x1, x2);
	x1 = ft_printf("%#5X!\n", 0);
	x2 = printf("%#5X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%#-5X!\n", 0);
	x2 = printf("%#-5X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%0#5X!\n", 0);
	x2 = printf("%0#5X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%#5.X!\n", 0);
	x2 = printf("%#5.X!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%0-#10X!\n", 42);
	x2 = printf("%0-#10X!\n", 42);
	assert_values(x1, x2);

	ft_printf("Test p:\n");
	x1 = ft_printf("%-10p!\n", "0x1A2B3C");
	x2 = printf("%-10p!\n", "0x1A2B3C");
	assert_values(x1, x2);
	x1 = ft_printf("%10p!\n", "42345");
	x2 = printf("%10p!\n", "42345");
	assert_values(x1, x2);
	x1 = ft_printf("%1p!\n", "abc");
	x2 = printf("%1p!\n", "abc");
	assert_values(x1, x2);
	x1 = ft_printf("%-10p!\n", NULL);
	x2 = printf("%-10p!\n", NULL);
	assert_values(x1, x2);
	x1 = ft_printf("%4p!\n", NULL);
	x2 = printf("%4p!\n", NULL);
	assert_values(x1, x2);
	x1 = ft_printf("%10p!\n", NULL);
	x2 = printf("%10p!\n", NULL);
	assert_values(x1, x2);
	x1 = ft_printf("%25p!\n", &x1);
	x2 = printf("%25p!\n", &x1);
	assert_values(x1, x2);
	x1 = ft_printf("%-25p!\n", &x1);
	x2 = printf("%-25p!\n", &x1);
	assert_values(x1, x2);

	ft_printf("Test d and i:\n");
	x1 = ft_printf("%3d!\n", 42000);
	x2 = printf("%3d!\n", 42000);
	assert_values(x1, x2);
	x1 = ft_printf("%03i!\n", 42000);
	x2 = printf("%03i!\n", 42000);
	assert_values(x1, x2);
	x1 = ft_printf("%0+3d!\n", 42000);
	x2 = printf("%0+3d!\n", 42000);
	assert_values(x1, x2);
	x1 = ft_printf("%0 3d!\n", 42000);
	x2 = printf("%0 3d!\n", 42000);
	assert_values(x1, x2);
	x1 = ft_printf("%-+3d!\n", 42000);
	x2 = printf("%-+3d!\n", 42000);
	assert_values(x1, x2);
	x1 = ft_printf("%5d!\n", 42);
	x2 = printf("%5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%-5d!\n", 42);
	x2 = printf("%-5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%05d!\n", 42);
	x2 = printf("%05d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%0-5d!\n", 42);
	x2 = printf("%0-5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%+5d!\n", 42);
	x2 = printf("%+5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("% 5d!\n", 42);
	x2 = printf("% 5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%+ 5d!\n", 42);
	x2 = printf("%+ 5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%+-5d!\n", 42);
	x2 = printf("%+-5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%- 5d!\n", 42);
	x2 = printf("%- 5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%+05d!\n", 42);
	x2 = printf("%+05d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%0 5d!\n", 42);
	x2 = printf("%0 5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%5.5d!\n", 42);
	x2 = printf("%5.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%5.7d!\n", 42);
	x2 = printf("%5.7d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("% 5.7d!\n", 42);
	x2 = printf("% 5.7d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%10.5d!\n", 42);
	x2 = printf("%10.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%-10.5d!\n", 42);
	x2 = printf("%-10.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%010.5d!\n", 42);
	x2 = printf("%010.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%+10.5d!\n", 42);
	x2 = printf("%+10.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("% 10.5d!\n", 42);
	x2 = printf("% 10.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%+-10.5d!\n", 42);
	x2 = printf("%+-10.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%- 10.5d!\n", 42);
	x2 = printf("%- 10.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%+010.5d!\n", 42);
	x2 = printf("%+010.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%0 10.5d!\n", 42);
	x2 = printf("%0 10.5d!\n", 42);
	assert_values(x1, x2);
	x1 = ft_printf("%5d!\n", -42);
	x2 = printf("%5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%-5d!\n", -42);
	x2 = printf("%-5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%05d!\n", -42);
	x2 = printf("%05d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%+5d!\n", -42);
	x2 = printf("%+5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("% 5i!\n", -42);
	x2 = printf("% 5i!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%+-5d!\n", -42);
	x2 = printf("%+-5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%- 5d!\n", -42);
	x2 = printf("%- 5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%+05d!\n", -42);
	x2 = printf("%+05d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%0 5d!\n", -42);
	x2 = printf("%0 5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%5.5d!\n", -42);
	x2 = printf("%5.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%5.7d!\n", -42);
	x2 = printf("%5.7d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("% 5.7d!\n", -42);
	x2 = printf("% 5.7d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%10.5d!\n", -42);
	x2 = printf("%10.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%-10.5d!\n", -42);
	x2 = printf("%-10.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%010.5d!\n", -42);
	x2 = printf("%010.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%+10.5d!\n", -42);
	x2 = printf("%+10.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("% 10.5d!\n", -42);
	x2 = printf("% 10.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%+-10.5d!\n", -42);
	x2 = printf("%+-10.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%- 10.5d!\n", -42);
	x2 = printf("%- 10.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%+010.5d!\n", -42);
	x2 = printf("%+010.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%0 10.5d!\n", -42);
	x2 = printf("%0 10.5d!\n", -42);
	assert_values(x1, x2);
	x1 = ft_printf("%010.d!\n", -2147483648);
	x2 = printf("%010.d!\n", (int)-2147483648);
	assert_values(x1, x2);
	x1 = ft_printf("%.11i!\n", -2147483648);
	x2 = printf("%.11i!\n", (int)-2147483648);
	assert_values(x1, x2);
	x1 = ft_printf("%15.12d!\n", -2147483648);
	x2 = printf("%15.12d!\n", (int)-2147483648);
	assert_values(x1, x2);
	x1 = ft_printf("%-15.12d!\n", -2147483648);
	x2 = printf("%-15.12d!\n", (int)-2147483648);
	assert_values(x1, x2);
	x1 = ft_printf("%015d!\n", -2147483648);
	x2 = printf("%015d!\n", (int)-2147483648);
	assert_values(x1, x2);
	x1 = ft_printf("%015.12d!\n", -2147483648);
	x2 = printf("%015.12d!\n", (int)-2147483648);
	assert_values(x1, x2);
	x1 = ft_printf("%0+5d!\n", 0);
	x2 = printf("%0+5d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%0+5.d!\n", 0);
	x2 = printf("%0+5.d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%0 5.i!\n", 0);
	x2 = printf("%0 5.i!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%-+5.d!\n", 0);
	x2 = printf("%-+5.d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%- 5.d!\n", 0);
	x2 = printf("%- 5.d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("% 5.3d!\n", 0);
	x2 = printf("% 5.3d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%-+5.3d!\n", 0);
	x2 = printf("%-+5.3d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%0+5.3d!\n", 0);
	x2 = printf("%0+5.3d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%-3d!\n", 0);
	x2 = printf("%-3d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%-3.d!\n", 0);
	x2 = printf("%-3.d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%.d!\n", 0);
	x2 = printf("%.d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("% .d!\n", 0);
	x2 = printf("% .d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%+.d!\n", 0);
	x2 = printf("%+.d!\n", 0);
	assert_values(x1, x2);
	x1 = ft_printf("%1.d!\n", 0);
	x2 = printf("%1.d!\n", 0);
	assert_values(x1, x2);

	ft_printf("Mixed test:\n");
	x1 = ft_printf("%+- 10%:%10d!\n", 5);
	x2 = printf("%+- 10%:%10d!\n", 5);
	assert_values(x1, x2);
	x1 = ft_printf("S:%5.d:%-5c:%5.1s:%05i:%-#5.2x:%05.3X:%-5p!\n", 0, '0', "11", 11, 11, 0xFF, "FF");
	x2 = printf("S:%5.d:%-5c:%5.1s:%05i:%-#5.2x:%05.3X:%-5p!\n", 0, '0', "11", 11, 11, 0xFF, "FF");
	assert_values(x1, x2);
}

int	main(void)
{
	test_ft_printf();
	return (0);
}
