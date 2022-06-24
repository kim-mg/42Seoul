/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:26:38 by myunkim           #+#    #+#             */
/*   Updated: 2021/06/30 20:19:00 by myunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	d = 2147483647;
	int	i = -2147483648;
	unsigned int u = 4294967295;
	int	x = 314159;
	int	X = 314159;
	char	c = 'c';
	char	s[] = "hello, world";
	int	*p;
	
	int	n;
	signed char	hhn;
	short int	hn;
	long int	ln;
	long long int	lln;
	double	e = 3.14159265359;
	double	f = 3.14159265359;
	double	g = 3.14159265359;
	double	t = 314.33;

	long int	l = -2147483648;
	long long int	ll = 9223372036854775807LL;
	unsigned long int	ul = 4294967295;
	unsigned long long int	ull = 18446744073709551615ULL;

	short int	h = -32768;
	signed char	hh = 'C';
	unsigned short int	uh = 65535;
	unsigned char	uhh = 'C';

	wchar_t	wc = 'c';
	wchar_t	*ws = L"hello, world";

	// Mandatory : cspdiuxX 서식 지정자
	printf("============================================\n");
	printf("============== MANDATORY PART ==============\n");
	printf("============================================\n");
	printf("=========== 1.cspdiuxX%% formats ===========\n");
	printf("============================================\n\n");
	printf("* character : %010c\n\n", c);
	printf("* string : %s\n\n", s);
	printf("* pointer : %p\n\n", p);
	printf("* digits : %d\n\n", d);
	printf("* integer : %i\n\n", i);
	printf("* unsigned integer : %u\n\n", u);
	printf("* lower hexadecimal : %x\n\n", -x);
	printf("* capital hexadecimal : %X\n\n", X);
	printf("* percent sign print : %-05%\n\n");
	
	// Mandatory : -0.* 플래그
	printf("============================================\n");
	printf("=============== 2.-0.* flags ===============\n");
	printf("============================================\n\n");
	// '-' 존재 시 '0'은 무시 됨
	printf("* '-'flag fmt=d, width=15 // left align : %-15d\n", d);
	printf("* '-'flag fmt=d, precision=15 // left align : %-.15d\n", d);
	printf("* '-'flag fmt=d, width=3 // left align : %-3d\n", d);
	printf("* '-'flag fmt=d, precision=3 // left align : %-.3d\n", d);
	printf("* '-'flag fmt=s, width=15 // left align : %-15s\n", s);
	printf("* '-'flag fmt=s, precision=15 // left align : %-.15s\n", s);
	printf("* '-'flag fmt=s, width=3 // left align : %-3s\n", s);
	printf("* '-'flag fmt=s, precision=3 // left align : %-.3s\n\n", s);
	// string에 '0' 플래그 warning 뜨지만 사용가능
	printf("* 1'0'flag fmt=d, width=15 // fill '0' in rest space : %025.15d\n", d);
	printf("* 2'0'flag fmt=d, width=15 // fill '0' in rest space : %0015d\n", d);
	printf("* 2'0'flag fmt=d, width=15 // fill '0' in rest space : %0.15d\n", d);
	printf("* 0'0'flag fmt=s, width=15 // warning but can fill '0' : %0*.5s\n", 15, s);
	printf("* 0'0'flag fmt=s, width=15 // warning but can fill '0' : %015s\n\n", s);
	// 정밀도 크기만큼의 공간을 확보하고 조건 별 출력
	printf("* '.*'flag fmt=d, *=15 // fill '0' in rest '*' : %15.15d\n", d);
	printf("* '.*'flag fmt=d, *=15 // fill '0' in rest '*' : %-15.10x\n", x);
	printf("* '.*'flag fmt=d, *=3 // print only 'd' : %.3d\n", d);
	printf("* '.*'flag fmt=d, *=None // print only 'd' : %.d\n", d);
	printf("* '.*'flag fmt=s, *=15 // case '*' > str = print 's' : %.15s\n", s);
	printf("* '.*'flag fmt=s, *=3 // case '*' < str = print '*'size from 's' : %.3s\n", s);
	printf("* '.*'flag fmt=s, *=None // case '*' none = None : %.s\n\n", s);
	// 폭 크기만큼의 공간을 확보하고 남는 공간만큼 ' '으로 채움
	printf("* '*'flag fmt=d, *=15 // get '*'size space : %015.30d\n", -d);
	printf("* '*'flag fmt=d, *=3 // get '*'size space : %3d\n", d);
	printf("* '*'flag fmt=s, *=15 // get '*'size space : %010.13s\n", s);
	printf("* '*'flag fmt=s, *=3 // get '*'size space : %.s\n\n", s);
	
	// Bonus : nfge 서식 지정자
	printf("============================================\n");
	printf("================ BONUS PART ================\n");
	printf("============================================\n");
	printf("============== 1.nfge formats ==============\n");
	printf("============================================\n\n");
	printf("* case : ");
	printf("abcde%n'%%n'fgfg\n", &n);
	printf("* nums of characters from the start to 'n' : %d\n\n", n);
	printf("* float : %f\n", f);
	printf("* float : %f\n\n", t);
	printf("* g : %g\n", g);
	printf("* g : %g\n\n", t);
	printf("* e : %e\n", e);
	printf("* e : %e\n\n", t);

	// Bonus : l ll h hh # ' ' '+' + -0.* 플래그
	printf("============================================\n");
	printf("========= 2.l ll h hh # ' ' + flags ========\n");
	printf("============================================\n\n");
	// long
	printf("* long d : %ld\n", l);
	printf("* long i : %li\n", l);
	printf("* long u : %lu\n", ul);
	printf("* long x : %lx\n", ul);
	printf("* long X : %lX\n", ul);
	printf("case : ");
	printf("abcde%ln'%%n'fg\n", &ln);
	printf("* long n : %ld\n", ln);
	printf("* long f : %lf\n", t);
	printf("* long g : %lg\n", t);
	printf("* long e : %le\n", t);
	printf("* long c : %lc\n", wc);
	printf("* long s : %ls\n\n", ws);
	// long long
	printf("* long long d : %lld\n", ll);
	printf("* long long i : %lli\n", ll);
	printf("* long long u : %llu\n", ull);
	printf("* long long x : %llx\n", ull);
	printf("* long long X : %llX\n", ull);
	printf("case : ");
	printf("abcde%lln'%%n'fg\n", &lln);
	printf("* long long n : %lld\n\n", lln);
	// short
	printf("* short d : %hd\n", h);
	printf("* short i : %hi\n", h);
	printf("* short u : %hu\n", uh);
	printf("* short x : %hx\n", uh);
	printf("* short X : %hX\n", uh);
	printf("case : ");
	printf("abcde%hn'%%n'fg\n", &hn);
	printf("* short n : %d\n\n", hn);
	// short short
	printf("* short short d : %hhd\n", hh);
	printf("* short short i : %hhi\n", hh);
	printf("* short short u : %hhu\n", uhh);
	printf("* short short x : %hhx\n", uhh);
	printf("* short short X : %hhX\n", uhh);
	printf("case : ");
	printf("abcde%hhn'%%n'fg\n", &hhn);
	printf("* short short n : %d\n\n", hhn);
	return (0);
}
