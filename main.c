/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:21:25 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/10 14:35:39 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int		main(int argc, char **argv)
{
//	setlocale(LC_CTYPE, "");
	setlocale(LC_ALL, "");
	if (argc > 1)
	{
//		unsigned long nbr;
//		nbr = 21474836495;

		printf(argv[1], argv[2]);
//		uintmax_t nbr = -58;
//		ft_printf("actual:   %u\n", atoi(argv[1]));;
//		ft_printf("actual:   %c\n", argv[1][0]);
//		ft_printf("actual:   %-0#5.6jX\n", nbr); //atoi(argv[1]));
//		ft_printf("actual:   %0#5.6X & %d\n", atoi(argv[1]), atoi(argv[2]));
//		ft_printf("actual:   %O\n", nbr);
//		ft_printf("actual:   %-+15d\n", atoi(argv[1]));


//		printf("expected: %u\n", atoi(argv[1]));
//		printf("expected: %c\n", argv[1][0]);
//		printf("expected: %-#5.6jX\n", nbr); //atoi(argv[1]));
//		printf("%0#5x\n", atoi(argv[1]));
//		printf("expected: %0#5.6X & %d\n", atoi(argv[1]), atoi(argv[2]));
//		printf("expected: %O\n", nbr); //not sure why this doesnt work
//		printf("expected: %-+15d\n", atoi(argv[1]));
	}	
	else
	{
//		signed char hh = 128;
//		ft_printf("actual:   %-+15hhd\n", hh);
//		printf("expected: %-+15hhd\n", hh);

//		unsigned int u = 4147483648;
//		ft_printf("actual:   %0-18.20u\n", u);
//		printf("expected: %-18.20u\n", u);
		
//		ft_printf("actual:   %%\a\b\f\n\r\t\v\\\n");
//		printf("expected: %%\a\b\f\n\r\t\v\\\n");

//		wchar_t ls[] = "诶";
//		ft_printf("actual:   %s\n", "诶");
//		wchar_t *ls = "漢字";//L"Wide Character string";
//		wchar_t *wch = L"u2e86";
//		wchar_t *widestring = L"Hello, world!";
//		printf("strlen is %zu vs %zu\n", ft_wstrlen(widestring), wcslen(widestring));
//		ft_printf("actual:   %s\n", widestring);		
//		printf("expected: %ls\n", widestring);//"诶");

//		ft_printf("actual:   %-20p\n", &wch);
//		printf("expected: %-20p\n", &wch);

//		int i = 0;
//		char color_code[] = "\033[0;31m";
//		ft_putstr(color_code);
/*		ft_putstr("\x1B[31m");
		ft_putstr("\x1B[44m");
//		ft_putstr("\x[0;31m");
//		while (color_code[i] != '\0')
//		{
//			write(1, &color_code[i], 1);
//			i++;
//		}
//		write(1, "\033[0;31m", );
		ft_putstr("this should be red :c\n");
//		ft_putstr("\033[0m");
//		ft_putstr("\033[49m");
		ft_putstr("this should be back to normal\n");
		ft_putstr("\033[0m");
//		printf("\033[1;31m");
//		printf("\x1B[37m");
		printf("Hello\n");
		printf("\033[0m");
		printf("World\n");
//		printf(" \033[01;34m Hello World");

		printf("\033[1;31m");
		printf("Hello world\n");
//		printf("\033[0m;");
*/

		int rtn;

		ft_printf("actual:   ");
//		rtn = ft_printf("%c", 'a');
//		rtn = ft_printf("%-5%");
//		rtn = ft_printf("%s\n", "abcg");
//		rtn = ft_printf("%ls\n", widestring);
//		rtn = ft_printf("%0#5.6X & %-5.6d\n", 68558, -3567);
//		int n = -42;
//		rtn = ft_printf("%#x", 0); //4294967296);
//		rtn =  ft_printf("%5.2s is a string", "this");
//		rtn = ft_printf("%.2s", NULL);
//		rtn = ft_printf("@moulitest: %s", NULL);
//		rtn = ft_printf("%5c", 42);
//		rtn = ft_printf("%d", 2147483648);
//		rtn = ft_printf("%u", -1);
//		rtn = ft_printf("%d", -2147483648);
//		rtn = ft_printf("%hhd", -129);
//		rtn = ft_printf("%lld", 9223372036854775807);
//		rtn = ft_printf("%zd", -1);
//		rtn = ft_printf("@moulitest: %#.x %#.0x", 0, 0);
//		rtn = ft_printf("@moulitest: %#.o %#.0o", 0, 0);		
//		rtn = ft_printf("%.x", 0);
//		rtn = ft_printf("%.d", 0);
//		rtn = ft_printf("%Z");
//		rtn = ft_printf("%05%");
//		rtn = ft_printf("%ll-25x", 9223372036854775807);
//		rtn = ft_printf("%jx", 4294967296);
//		rtn = ft_printf("%010s is a string", "this");
//		rtn = ft_printf("%5+d", 42);
//		rtn = ft_printf("%zhd", 4294967296);
//		rtn = ft_printf("%hhld", 128);
//		rtn = ft_printf("@moulitest: %.d %.0d", 0, 0);
//		rtn = ft_printf("%####0000 33..1..d", 256);	
//		wchar_t *blah = L"米";
//		rtn = ft_printf("%S", L"米");
//		wchar_t chinese[] = L"我不是中国人。";
//		wchar_t chinese[] = L"something here";
//		rtn = ft_printf("%S", L"\u0141");
//		rtn = ft_printf("%S", chinese);
//		rtn = ft_printf("%x\n", "猫猫");
//		wchar_t cat[] = L"猫";
//		ft_printf("%s", cat);
//		rtn = ft_printf("%*.5d", 2, 288);
//		signed char tmp;
//		rtn = ft_printf("the number is %n", &tmp);
//		rtn = ft_printf("the double number is: %lf", 54657987987.232);
//		rtn = ft_printf("%015.3E", 9256.65);
//		rtn = ft_printf("%e", 1001.0);
//		rtn = ft_printf("%e", 0.0000000000000000000000000000000000056);
//		long double ldbl = 92239995874563214587452159585625478521458745956321456985214785236541236598751235846297372000000000000.0; //0.0
//		rtn = ft_printf("%Le", ldbl);
//		double y = 42.0; //0.00000000666666666666;
//		rtn = ft_printf("%#.0g", y);
//		rtn = ft_printf("%f", -2147483649.0);// 1.99999999);
//		rtn = ft_printf("%g", -8000.0);
//		rtn = ft_printf("%-15g", 56222223.985);
//		rtn = ft_printf("%e", 0.0);
//		char long_string[] = "dlksjaflkjlksdjflksjdljrlskjlkdjflksjfjoeirusljflksj kjdflks lkskjflkdsjflskj lkjflkjflksdj lskjflksjeoirueoijflksdjf lkslfjlksdfjlksdoiweurosejflksdfj lskjfisyoeiwrsljflkdsjf lksdjflsoeirulskjflksdj flksdjflksdjf oirsijflksjklkdsjflkdsjflkjdlfjldfjldsfjlfjlsdjfljflsdkfjlkfjlkdsfjldksjfldsjf";
//		rtn = ft_printf("%s %hhn", long_string, &tmp);
//		rtn = ft_printf("%*.*d", 15, 5, 658);
//		rtn = ft_printf("%'u", 234);
//		rtn = ft_printf("this will be{blue} diff {eoc}and this is {light blue} light diff {eoc} normal now{");
//		rtn = ft_printf("%'20.5d", -1250);
//		rtn = ft_printf("%15p", &rtn);
//		rtn = ft_printf("{%s}and this is{blue} blue {eoc}and back to normal", "");
//		rtn = ft_printf("{%f}{%F}", -1.42, -1.42);
//		rtn = ft_printf("{%*d}", -5, 42);
//		rtn = ft_printf("{%S}", NULL);
////		rtn = ft_printf("%S", L"米");
//		rtn = ft_printf("a%Sb%sc%S", L"我", "42", L"猫");
//		wchar_t *wstr;
//		wstr = L"sjlkjerolkdjfks kldfjs12345 kdjfksjfd";
//		rtn = ft_printf("%S", wstr);
//		rtn = ft_printf("{%10R}");
//		ft_printf("\n");
//		rtn = ft_printf("{%*3d}", 0, 0);
//		ft_printf("%.p, %.0p", 0, 0);
//		rtn = ft_printf("%#.3o", 1);
//		rtn = ft_printf("{%05.S}", L"42 c est cool");
//		int tmp = 0xFFFF;
//		rtn = ft_printf("{%030x}", tmp);
//		rtn = ft_printf("%.0p, %.p", 0, 0);
//		rtn = ft_printf("%#.O", 0);
////		rtn = ft_printf("%-56.32g\n", 5427875454587545.2569545454); //need to debug
//		double testnbr = 5427875454587545.2569545454;
////		double testnbr = 5427875454587500.00;
////		rtn = ft_printf("%-56.18g", testnbr);
////		rtn = ft_printf("%.9g", 45789.215400500); 
//		rtn = ft_printf("{color test %s} this is{red} red but now{green} green", "commencing:");
		rtn = ft_printf("%0'.7d", 36887);
//		rtn = ft_printf("%e", 123565489795465987.856);
//		long double ldbl = -5875465854564564545554.21254;
//		rtn = ft_printf("%Le", ldbl);
		ft_printf("\nrtn value is: %d\n", rtn);
//		ft_printf("tmp is %d\n", tmp);

		printf("expected: ");
//		rtn = printf("%c", 'a');
//		rtn = printf("%-5%");
//		rtn = printf("%s\n", "abcg");
//		rtn = printf("%ls\n", widestring);
//		rtn = printf("%0#5.6X & %-5.6d\n", 68558, -3567);
//		rtn = printf("%#x", 0); //4294967296);
//		rtn = printf("%5.2s is a string", "this");
//		rtn = printf("%.2s", NULL);
//		rtn = printf("@moulitest: %s", NULL);
//		rtn = printf("%5c", 42);
//		rtn = printf("%d", 2147483648);			
//		rtn = printf("%u", -1);
//		rtn = printf("%d", -2147483648);
//		rtn = printf("%hhd", -129);
//		rtn = printf("%lld", 9223372036854775807);
//		rtn = printf("%zd", -1);
//		rtn = printf("@moulitest: %#.x %#.0x", 0, 0);
//		rtn = printf("%.x", 0);
//		rtn = printf("%.d", 0);
//		rtn = printf("@moulitest: %#.o %#.0o", 0, 0);
//		rtn = printf("%Z");
//		rtn = printf("%05%");
//		rtn = printf("%ll-25x", 9223372036854775807);
//		rtn = printf("%jx", 4294967296);
//		rtn = printf("%010s is a string", "this");
//		rtn = printf("%5+d", 42);
//		rtn = printf("%zhd", 4294967296);
//		rtn = printf("%k\n");
//		rtn = printf("%hhld", 128);
//		rtn = printf("@moulitest: %.d %.0d", 0, 0);
//		rtn = printf("%####0000 33..1..d", 256);
//		rtn = printf("%S", L"我是一只猫。");
//		rtn = printf("%S", L"\u0141");
//		rtn = printf("%ls", chinese);
//		rtn = printf("%S\n", "猫猫");
//		rtn = printf("%ls", L"猫");
//		rtn = printf("%*.5d", 2, 288);
//		signed char tmp2;
//		rtn = printf("the number is %n", &tmp2);
//		rtn = printf("prints 0 suprisingly: %.f\n", 0);
//		rtn = printf("the double number is: %lf", 54657987987.232);
//		rtn = printf("%015.3E", 9256.65);
//		rtn = printf("%e", 1001.0);
//		rtn = printf("%e", 0.0000000000000000000000000000000000056);
//		rtn = printf("%Le", ldbl);
//		rtn = printf("%#.0g", y);
//		rtn = printf("%f", -2147483649.0);// 1.99999999);
//		rtn = printf("%g", -8000.0);
//		rtn = printf("%-15g", 56222223.985);
//		rtn = printf("%e", 0.0);
//		rtn = printf("%s %hhn", long_string, &tmp2);
//		rtn = printf("%*.*d", 15, 5, 658);
//		rtn = printf("%'20.5d", -1250);
//		rtn = printf("%2$d %d %d", 6, 68, 98);
//		rtn = printf("%15p", &rtn);
//		rtn = printf("{%f}{%F}", -1.42, -1.42);
//		rtn = printf("{%*d}", -5, 42);
//		rtn = printf("{%S}", NULL);
////		rtn = printf("%S", L"米");
//		rtn = printf("a%Sb%sc%S", L"我", "42", L"猫");
//		rtn = printf("%S", wstr);
//		rtn = printf("{%10R}");
//		printf("\n");
//		printf("{%*3d}", 0, 0);
//		printf("{%-15Z}", 123);
//		printf("%.p, %.0p", 0, 0);
//		rtn = printf("%#.3o", 1);
//		rtn = printf("{%05.S}", L"42 c est cool");
//		rtn = printf("{%030x}", tmp);
//		rtn = printf("%'u", 234);
//		rtn = printf("{%05p}", 0);
//		rtn = printf("%.0p, %.p", 0, 0);
//		rtn = printf("%#.O", 0);
////		rtn = printf("%-56.32g\n", 5427875454587545.2569545454);
////		rtn = printf("%.9g", 45789.215400500);
////		rtn = printf("%-56.18g", testnbr);
////		rtn = printf("{color test %s} this is{red} red but now{green} green {eoc}then normal", "commencing:");
		rtn = printf("%0'.7d", 36887);	
//		rtn = printf("%e", 123565489795465987.856);
//		rtn = printf("%Le", ldbl);
		printf("\nrtn value is: %d\n", rtn);
//		printf("-10 to power of 18 is %lld\n", ft_power(-10, 18));
		printf("first is %.20f second is %.20f\n", 0.5/1000000000000000000, 0.5/8446744073709551616);
//		ft_putstr("\x1B[5m");
//		ft_putstr("this should blink\n");

//		printf("size of short is %lu and size of long is %lu and size of long long is %lu and size of uintmax is %lu and size of double is %lu and size of long double is %lu and size of unsigned long long is %lu\n", sizeof(short), sizeof(long), sizeof(long long), sizeof(uintmax_t), sizeof(double), sizeof(long double), sizeof(unsigned long long));
//		printf("tmp is %d\n", tmp2);
//		printf("size of size_t is %lu and size of long is %lu\n", sizeof(size_t), sizeof(long));
	}
	return (0);
}
