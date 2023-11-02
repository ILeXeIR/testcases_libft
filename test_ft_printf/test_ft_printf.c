#include "../../ft_printf/ft_printf.h"
#include <stdio.h>

void	test_ft_printf(void)
{
	ft_printf("Mandatory part tests:\n");

	ft_printf("Test c:\n");
	ft_printf("%c!\n", 'a');
	printf("%c!\n\n", 'a');
	ft_printf("%c!\n", '\200');
	printf("%c!\n\n", '\200');
	ft_printf("%c!\n", 0);
	printf("%c!\n\n", 0);
	ft_printf("<%c>!\n", '\n');
	printf("<%c>!\n\n", '\n');

	ft_printf("Test S:\n");
	ft_printf("%s!\n", "");
	printf("%s!\n\n", "");
	ft_printf("$$$%s!\n", "abc");
	printf("$$$%s!\n\n", "abc");
	ft_printf("%s!\n", NULL);
	printf("%s!\n\n", NULL);

	ft_printf("Test u:\n");
	ft_printf("%u!\n", 0);
	printf("%u!\n\n", 0);
	ft_printf("__%u__!\n", 3147483647);
	printf("__%u__!\n\n", 3147483647);

	ft_printf("Test x:\n");
	ft_printf("%x!\n", 0);
	printf("%x!\n\n", 0);
	ft_printf("__%x__!\n", 3147483647);
	printf("__%x__!\n\n", 3147483647);

	ft_printf("Test X:\n");
	ft_printf("%X!\n", 0);
	printf("%X!\n\n", 0);
	ft_printf("__%X__!\n", 3147483647);
	printf("__%X__!\n\n", 3147483647);

	ft_printf("Test p:\n");
	ft_printf("%p!\n", NULL);
	printf("%p!\n\n", NULL);
	ft_printf("__%p__!\n", "abc");
	printf("__%p__!\n\n", "abc");
	ft_printf("__%p__!\n", &malloc);
	printf("__%p__!\n\n", &malloc);

	ft_printf("Test d:\n");
	ft_printf("%d!\n", 0);
	printf("%d!\n\n", 0);
	ft_printf("__%d__%d!\n", -2147483648, 2147483647);
	printf("__%d__%d!\n\n", -2147483648, 2147483647);

	ft_printf("Test i:\n");
	ft_printf("%i!\n", 0);
	printf("%i!\n\n", 0);
	ft_printf("__%i__%i!\n", -2147483648, 2147483647);
	printf("__%i__%i!\n\n", -2147483648, 2147483647);

	ft_printf("Test %%:\n");
	ft_printf("%%!\n");
	printf("%%!\n\n");
	ft_printf("%!\n");
	printf("%!\n\n");
	ft_printf("%%d!\n", 5);
	printf("%%d!\n\n", 5);

	ft_printf("Mixed test:\n");
	ft_printf("%%%d!\n", 5);
	printf("%%%d!\n\n", 5);
	ft_printf("S:%d%c:%s%i%x:%X%p:%%!\n", 0, '0', "11", 11, 11, 0xFF, "FF", "ERROR");
	printf("S:%d%c:%s%i%x:%X%p:%%!\n\n", 0, '0', "11", 11, 11, 0xFF, "FF", "ERROR");
	ft_printf("S:%d%c:%s%i%x:%X%p:%%!\n", 0, 0, "11\0XXX", 11, 11, 0xFF, "FF", "ERROR");
	printf("S:%d%c:%s%i%x:%X%p:%%!\n\n", 0, 0, "11\0XXX", 11, 11, 0xFF, "FF", "ERROR");


	ft_printf("Bonus part tests:\n");

	ft_printf("Test c:\n");
	ft_printf("%3c!%-5c!\n", 'a', 'b', 'c');
	printf("%3c!%-5c!\n\n", 'a', 'b', 'c');
	ft_printf("%--7c!\n", 'a');
	printf("%--7c!\n\n", 'a');
	
	ft_printf("Test s:\n");
	ft_printf("%10.5s!\n", "abcdefghijklmnop");
	printf("%10.5s!\n\n", "abcdefghijklmnop");
	ft_printf("%10.0s!\n", "abcdefghijklmnop");
	printf("%10.0s!\n\n", "abcdefghijklmnop");
	ft_printf("%.s!\n", "abcdefghijklmnop");
	printf("%.s!\n\n", "abcdefghijklmnop");
	ft_printf("%.25s!\n", "abcdefghijklmnop");
	printf("%.25s!\n\n", "abcdefghijklmnop");
	ft_printf("%-10s!%10s!\n", "abc", "def");
	printf("%-10s!%10s!\n\n", "abc", "def");
	ft_printf("%-10s%c\n", "abc", '!');
	printf("%-10s%c\n\n", "abc", '!');
	ft_printf("%-10s!\n", NULL);
	printf("%-10s!\n\n", NULL);
	ft_printf("%.5s!\n", NULL);
	printf("%.5s!\n\n", NULL);
	ft_printf("%10.6s!\n", NULL);
	printf("%10.6s!\n\n", NULL);
	
	ft_printf("Test u:\n");
	ft_printf("%-10u!\n", 0xFFFFFFFF);
	printf("%-10u!\n\n", 0xFFFFFFFF);
	ft_printf("%-010u!\n", 42);
	printf("%-010u!\n\n", 42);
	ft_printf("%010u!\n", 42);
	printf("%010u!\n\n", 42);
	ft_printf("%-10.5u!\n", 42);
	printf("%-10.5u!\n\n", 42);
	ft_printf("%010.5u!\n", 42);
	printf("%010.5u!\n\n", 42);
	ft_printf("%.2u!\n", 42345);
	printf("%.2u!\n\n", 42345);
	ft_printf("%5u!\n", 0);
	printf("%5u!\n\n", 0);
	ft_printf("%05u!\n", 0);
	printf("%05u!\n\n", 0);
	ft_printf("%5.u!\n", 0);
	printf("%5.u!\n\n", 0);
	ft_printf("%0-10u!\n", 42);
	printf("%0-10u!\n\n", 42);

	ft_printf("Test x:\n");
	ft_printf("%-10x!\n", 0x1A2B3C);
	printf("%-10x!\n\n", 0x1A2B3C);
	ft_printf("%-010x!\n", 0xD0E9F8);
	printf("%-010x!\n\n", 0xD0E9F8);
	ft_printf("%010x!\n", 0xFFFFFFFF);
	printf("%010x!\n\n", 0xFFFFFFFF);
	ft_printf("%-10.5x!\n", 42);
	printf("%-10.5x!\n\n", 42);
	ft_printf("%010.5x!\n", 42);
	printf("%010.5x!\n\n", 42);
	ft_printf("%.2x!\n", 42345);
	printf("%.2x!\n\n", 42345);
	ft_printf("%5x!\n", 0);
	printf("%5x!\n\n", 0);
	ft_printf("%-5x!\n", 0);
	printf("%-5x!\n\n", 0);
	ft_printf("%05x!\n", 0);
	printf("%05x!\n\n", 0);
	ft_printf("%5.x!\n", 0);
	printf("%5.x!\n\n", 0);
	ft_printf("%#-10x!\n", 42);
	printf("%#-10x!\n\n", 42);
	ft_printf("%0#10x!\n", 42);
	printf("%0#10x!\n\n", 42);
	ft_printf("%-#10.5x!\n", 42);
	printf("%-#10.5x!\n\n", 42);
	ft_printf("%#010.5x!\n", 42);
	printf("%#010.5x!\n\n", 42);
	ft_printf("%#.2x!\n", 42345);
	printf("%#.2x!\n\n", 42345);
	ft_printf("%#5x!\n", 0);
	printf("%#5x!\n\n", 0);
	ft_printf("%#-5x!\n", 0);
	printf("%#-5x!\n\n", 0);
	ft_printf("%0#5x!\n", 0);
	printf("%0#5x!\n\n", 0);
	ft_printf("%#5.x!\n", 0);
	printf("%#5.x!\n\n", 0);
	ft_printf("%0-#10x!\n", 42);
	printf("%0-#10x!\n\n", 42);

	ft_printf("Test X:\n");
	ft_printf("%-10X!\n", 0x1A2B3C);
	printf("%-10X!\n\n", 0x1A2B3C);
	ft_printf("%-010X!\n", 0xD0E9F8);
	printf("%-010X!\n\n", 0xD0E9F8);
	ft_printf("%010X!\n", 0xFFFFFFFF);
	printf("%010X!\n\n", 0xFFFFFFFF);
	ft_printf("%-10.5X!\n", 42);
	printf("%-10.5X!\n\n", 42);
	ft_printf("%010.5X!\n", 42);
	printf("%010.5X!\n\n", 42);
	ft_printf("%.2X!\n", 42345);
	printf("%.2X!\n\n", 42345);
	ft_printf("%5X!\n", 0);
	printf("%5X!\n\n", 0);
	ft_printf("%-5X!\n", 0);
	printf("%-5X!\n\n", 0);
	ft_printf("%05X!\n", 0);
	printf("%05X!\n\n", 0);
	ft_printf("%5.X!\n", 0);
	printf("%5.X!\n\n", 0);
	ft_printf("%#-10X!\n", 42);
	printf("%#-10X!\n\n", 42);
	ft_printf("%0#10X!\n", 42);
	printf("%0#10X!\n\n", 42);
	ft_printf("%-#10.5X!\n", 42);
	printf("%-#10.5X!\n\n", 42);
	ft_printf("%#010.5X!\n", 42);
	printf("%#010.5X!\n\n", 42);
	ft_printf("%#.2X!\n", 42345);
	printf("%#.2X!\n\n", 42345);
	ft_printf("%#5X!\n", 0);
	printf("%#5X!\n\n", 0);
	ft_printf("%#-5X!\n", 0);
	printf("%#-5X!\n\n", 0);
	ft_printf("%0#5X!\n", 0);
	printf("%0#5X!\n\n", 0);
	ft_printf("%#5.X!\n", 0);
	printf("%#5.X!\n\n", 0);
	ft_printf("%0-#10X!\n", 42);
	printf("%0-#10X!\n\n", 42);

	ft_printf("Test p:\n");
	ft_printf("%-10p!\n", "0x1A2B3C");
	printf("%-10p!\n\n", "0x1A2B3C");
	ft_printf("%10p!\n", "42345");
	printf("%10p!\n\n", "42345");
	ft_printf("%1p!\n", "abc");
	printf("%1p!\n\n", "abc");
	ft_printf("%-10p!\n", NULL);
	printf("%-10p!\n\n", NULL);
	ft_printf("%4p!\n", NULL);
	printf("%4p!\n\n", NULL);
	ft_printf("%10p!\n", NULL);
	printf("%10p!\n\n", NULL);

	ft_printf("Test d and i:\n");
	ft_printf("%3d!\n", 42000);
	printf("%3d!\n\n", 42000);
	ft_printf("%03i!\n", 42000);
	printf("%03i!\n\n", 42000);
	ft_printf("%0+3d!\n", 42000);
	printf("%0+3d!\n\n", 42000);
	ft_printf("%0 3d!\n", 42000);
	printf("%0 3d!\n\n", 42000);
	ft_printf("%-+3d!\n", 42000);
	printf("%-+3d!\n\n", 42000);
	ft_printf("%5d!\n", 42);
	printf("%5d!\n\n", 42);
	ft_printf("%-5d!\n", 42);
	printf("%-5d!\n\n", 42);
	ft_printf("%05d!\n", 42);
	printf("%05d!\n\n", 42);
	ft_printf("%0-5d!\n", 42);
	printf("%0-5d!\n\n", 42);
	ft_printf("%+5d!\n", 42);
	printf("%+5d!\n\n", 42);
	ft_printf("% 5d!\n", 42);
	printf("% 5d!\n\n", 42);
	ft_printf("%+ 5d!\n", 42);
	printf("%+ 5d!\n\n", 42);
	ft_printf("%+-5d!\n", 42);
	printf("%+-5d!\n\n", 42);
	ft_printf("%- 5d!\n", 42);
	printf("%- 5d!\n\n", 42);
	ft_printf("%+05d!\n", 42);
	printf("%+05d!\n\n", 42);
	ft_printf("%0 5d!\n", 42);
	printf("%0 5d!\n\n", 42);
	ft_printf("%5.5d!\n", 42);
	printf("%5.5d!\n\n", 42);
	ft_printf("%5.7d!\n", 42);
	printf("%5.7d!\n\n", 42);
	ft_printf("% 5.7d!\n", 42);
	printf("% 5.7d!\n\n", 42);
	ft_printf("%10.5d!\n", 42);
	printf("%10.5d!\n\n", 42);
	ft_printf("%-10.5d!\n", 42);
	printf("%-10.5d!\n\n", 42);
	ft_printf("%010.5d!\n", 42);
	printf("%010.5d!\n\n", 42);
	ft_printf("%+10.5d!\n", 42);
	printf("%+10.5d!\n\n", 42);
	ft_printf("% 10.5d!\n", 42);
	printf("% 10.5d!\n\n", 42);
	ft_printf("%+-10.5d!\n", 42);
	printf("%+-10.5d!\n\n", 42);
	ft_printf("%- 10.5d!\n", 42);
	printf("%- 10.5d!\n\n", 42);
	ft_printf("%+010.5d!\n", 42);
	printf("%+010.5d!\n\n", 42);
	ft_printf("%0 10.5d!\n", 42);
	printf("%0 10.5d!\n\n", 42);
	ft_printf("%5d!\n", -42);
	printf("%5d!\n\n", -42);
	ft_printf("%-5d!\n", -42);
	printf("%-5d!\n\n", -42);
	ft_printf("%05d!\n", -42);
	printf("%05d!\n\n", -42);
	ft_printf("%+5d!\n", -42);
	printf("%+5d!\n\n", -42);
	ft_printf("% 5i!\n", -42);
	printf("% 5i!\n\n", -42);
	ft_printf("%+-5d!\n", -42);
	printf("%+-5d!\n\n", -42);
	ft_printf("%- 5d!\n", -42);
	printf("%- 5d!\n\n", -42);
	ft_printf("%+05d!\n", -42);
	printf("%+05d!\n\n", -42);
	ft_printf("%0 5d!\n", -42);
	printf("%0 5d!\n\n", -42);
	ft_printf("%5.5d!\n", -42);
	printf("%5.5d!\n\n", -42);
	ft_printf("%5.7d!\n", -42);
	printf("%5.7d!\n\n", -42);
	ft_printf("% 5.7d!\n", -42);
	printf("% 5.7d!\n\n", -42);
	ft_printf("%10.5d!\n", -42);
	printf("%10.5d!\n\n", -42);
	ft_printf("%-10.5d!\n", -42);
	printf("%-10.5d!\n\n", -42);
	ft_printf("%010.5d!\n", -42);
	printf("%010.5d!\n\n", -42);
	ft_printf("%+10.5d!\n", -42);
	printf("%+10.5d!\n\n", -42);
	ft_printf("% 10.5d!\n", -42);
	printf("% 10.5d!\n\n", -42);
	ft_printf("%+-10.5d!\n", -42);
	printf("%+-10.5d!\n\n", -42);
	ft_printf("%- 10.5d!\n", -42);
	printf("%- 10.5d!\n\n", -42);
	ft_printf("%+010.5d!\n", -42);
	printf("%+010.5d!\n\n", -42);
	ft_printf("%0 10.5d!\n", -42);
	printf("%0 10.5d!\n\n", -42);
	ft_printf("%010.d!\n", -2147483648);
	printf("%010.d!\n\n", -2147483648);
	ft_printf("%.11i!\n", -2147483648);
	printf("%.11i!\n\n", -2147483648);
	ft_printf("%15.12d!\n", -2147483648);
	printf("%15.12d!\n\n", -2147483648);
	ft_printf("%-15.12d!\n", -2147483648);
	printf("%-15.12d!\n\n", -2147483648);
	ft_printf("%015d!\n", -2147483648);
	printf("%015d!\n\n", -2147483648);
	ft_printf("%015.12d!\n", -2147483648);
	printf("%015.12d!\n\n", (int)-2147483648);
	ft_printf("%0+5d!\n", 0);
	printf("%0+5d!\n\n", 0);
	ft_printf("%0+5.d!\n", 0);
	printf("%0+5.d!\n\n", 0);
	ft_printf("%0 5.i!\n", 0);
	printf("%0 5.i!\n\n", 0);
	ft_printf("%-+5.d!\n", 0);
	printf("%-+5.d!\n\n", 0);
	ft_printf("%- 5.d!\n", 0);
	printf("%- 5.d!\n\n", 0);
	ft_printf("% 5.3d!\n", 0);
	printf("% 5.3d!\n\n", 0);
	ft_printf("%-+5.3d!\n", 0);
	printf("%-+5.3d!\n\n", 0);
	ft_printf("%0+5.3d!\n", 0);
	printf("%0+5.3d!\n\n", 0);
	ft_printf("%-3d!\n", 0);
	printf("%-3d!\n\n", 0);
	ft_printf("%-3.d!\n", 0);
	printf("%-3.d!\n\n", 0);

	ft_printf("Mixed test:\n");
	ft_printf("%+- 10%:%10d!\n", 5);
	printf("%+- 10%:%10d!\n\n", 5);
	ft_printf("S:%5.d:%-5c:%5.1s:%05i:%-#5.2x:%05.3X:%-5p!\n", 0, '0', "11", 11, 11, 0xFF, "FF");
	printf("S:%5.d:%-5c:%5.1s:%05i:%-#5.2x:%05.3X:%-5p!\n\n", 0, '0', "11", 11, 11, 0xFF, "FF");
}

int	main(void)
{
	test_ft_printf();
	return (0);
}
