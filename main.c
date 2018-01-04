/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:21:25 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/03 19:31:50 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <wchar.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>

int		main(int argc, char **argv)
{
//	setlocale(LC_ALL, NULL);
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
		rtn = ft_printf("%x\n", "猫猫");
		ft_printf("\nrtn value is: %d\n", rtn);

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
		rtn = printf("%S\n", "猫猫");
		printf("\nrtn value is: %d\n", rtn);
//		printf("size of size_t is %lu and size of long is %lu\n", sizeof(size_t), sizeof(long));
	}
	return (0);
}
