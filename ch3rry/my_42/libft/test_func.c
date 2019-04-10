/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:26:59 by caellis           #+#    #+#             */
/*   Updated: 2019/04/09 20:26:54 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "test_printer_color.h"

# define S_TEST "H3IL CH3RRY"
# define S_TEST2 "H3IL BADBOI"
# define LEN_1 12
# define LEN_2 24
# define OK "_____GOOD__BOI_____\n"
# define NOK "XXX__BAD_DOGE__XXX\n"

static int	intcmp(int *n1, int *n2)
{
	return (n1 == n2);
}

static void	checker(void *s1, void *s2, int (*f)(void *, void *))
{
	if (f(s1, s2) != 0)
	{
		b_red(); printf(" ...\t...\t...\n"NOK" ...\t...\t...\n"); reset();
	}
	else
	{
		b_green(); printf(" ...\t...\t...\n"OK" ...\t...\t...\n\n"); reset();
	}
}

int			main(void)
{
	char	str1[LEN_1] = S_TEST;
	char	str2[LEN_1] = S_TEST;
	char	str24[LEN_2] = {"Almost empty..."};
	char	str242[LEN_2] = {"Almost empty..."};
	int		n1;
	int		n2;
	char	*buff;
	int		(*ft_cmp_s)(void *, void *);

	printf("\nHi, Master!\nHere are your tests..\n");
	printf("Please, enjoy\n\n");
	magenta(); printf(" ...\t...\t...\n"); reset();
	red(); printf(" .. %s  ..\n", S_TEST); reset();
	magenta(); printf(" ...\t...\t...\n\n"); reset();
	
	ft_cmp_s = (int (*)(void *, void *))strcmp;
	yellow(); printf("\n ...GO FT_MEMSET...\n"); reset();	//FT_MEMSET
	printf("memset() out:\n%s\n", memset(str1, 33, 4));
	printf("ft_memset() out:\n%s\n", ft_memset(str2, 33, 4));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	yellow(); printf("\n ...GO FT_BZERO...\n"); reset();	//FT_BZERO
	bzero(str1, 4); ft_bzero(str2, 4);
	printf("bzero() out:\n%s\n", str1);
	printf("ft_bzero() out:\n%s\n", str2);
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	yellow(); printf("\n ...GO FT_MEMCPY...\n"); reset();	//FT_MEMCPY
	ft_memset(str2, 33, 4); //set args
	printf("memcpy() out:\n%s\n", memcpy(str1, str2, LEN_1 - 1));
	ft_strcpy(str1, S_TEST); //set args
	printf("ft_memcpy() out:\n%s\n", ft_memcpy(str1, str2, LEN_1 - 1));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	yellow(); printf("\n ...GO FT_MEMCCPY...\n"); reset();	//FT_MEMCCPY
	ft_memset(str2, 33, 4); //set args
	printf("memccpy() opt1(no 'A' met) out:\n%s\n", memccpy(str1, str2, 'A', LEN_1 - 1));
	ft_strcpy(str1, S_TEST); //set args
	printf("ft_memccpy() opt1(no 'A' met) out:\n%s\n", ft_memccpy(str1, str2, 'A', LEN_1 - 1));
	checker(str1, str2, ft_cmp_s);
	printf("memccpy() opt2(' ' met) out:\n%s\n", memccpy(str1, str2, ' ', LEN_1 - 1));
	ft_strcpy(str1, S_TEST); //set args
	printf("ft_memccpy() opt2(' ' met) out:\n%s\n", ft_memccpy(str1, str2, ' ', LEN_1 - 1));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	yellow(); printf("\n ...GO FT_MEMMOVE...\n"); reset();	//FT_MEMMOVE
	ft_memset(str2, 33, 4); //set args
	printf("memmove() opt1(no crossin) out:\n%s\n", memmove(str1, str2, 4));
	ft_strcpy(str1, S_TEST); ft_memset(str2, 33, 4); //set args
	printf("ft_memmove() opt1(no crossin) out:\n%s\n", ft_memmove(str1, str2, 4));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset
	//now let's try f###in things up:)
	ft_memset(str1, 33, 5); buff = str1; //set args
	printf("memmove() opt2(screwed up) out:\n%s\n", memmove(str1, str1 + 1, 3));
	ft_strcpy(str1, S_TEST); ft_memset(str1, 33, 5); //set args
	printf("ft_memmove() opt2(screwed up) out:\n%s\n", ft_memmove(str1, str1 + 1, 3));
	checker(buff, str1, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	yellow(); printf("\n ...GO FT_MEMСMP...\n"); reset();	//FT_MEMCHR
	n1 = memcmp(str1, str2, LEN_1 - 1); n2 = ft_memcmp(str1, str2, LEN_1 - 1);
	printf("memcmp() out:\n%i\nft_memcmp() out:\n%i\n", n1, n2);
	ft_cmp_s = (int (*)(void *, void *))intcmp; //set func
	checker((char *)&n1, (char *)&n2, ft_cmp_s);
	//test 2 unequal strings
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST2);
	n1 = memcmp(str1, str2, LEN_1 - 1); n2 = ft_memcmp(str1, str2, LEN_1 - 1);
	printf("memcmp() unmatch test out:\n%i\nft_memcmp() unmatch test out:\n%i\n", n1, n2);
	checker((char *)&n1, (char *)&n2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset
	ft_cmp_s = (int (*)(void *, void *))strcmp; //reset func

	yellow(); printf("\n ...GO FT_STRLEN...\n"); reset();	//FT_STRLEN
	ft_cmp_s = (int (*)(void *, void *))intcmp; //set func
	n1 = strlen(str1); n2 = ft_strlen(str1);
	printf("strlen() out:\n%i\n", n1); printf("ft_strlen() out:\n%i\n", n2);
	checker((char *)&n1, (char *)&n2, ft_cmp_s);
	// now let's go empty
	n1 = strlen(""); n2 = ft_strlen("");
	printf("strlen() empty str out:\n%i\n", n1); printf("ft_strlen() out:\n%i\n", n2);
	checker((char *)&n1, (char *)&n2, ft_cmp_s);
	strcpy(str1, S_TEST); strcpy(str2, S_TEST); //reset
	ft_cmp_s = (int (*)(void *, void *))strcmp; //reset func

	yellow() ; printf("\n ...GO FT_STRCPY...\n"); reset();	//FT_STRCPY
	printf("strcpy() ok out:\n%s\n", strcpy(str1, "!!!!"));
	printf("ft_strcpy() ok out:\n%s\n", ft_strcpy(str2, "!!!!"));
	checker(str1, str2, ft_cmp_s);
	strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //set args
	// now dest > src
	printf("strcpy() opt2 (dest > src) out:\n%s\n", strcpy(str1, "YEAH"));
	printf("ft_strcpy() opt2(dest > src) out:\n%s\n", ft_strcpy(str2, "YEAH"));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	yellow() ; printf("\n ...GO FT_STRCPY...\n"); reset();	//FT_STRNCPY
	printf("strncpy() ok out:\n%s\n", strncpy(str1, "!!!!", 4));
	printf("ft_strncpy() ok out:\n%s\n", ft_strncpy(str2, "!!!!", 4));
	checker(str1, str2, ft_cmp_s);
	strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //set args
	// now len < len(src)
	printf("strncpy() opt2 (len < len(src) YEAL CH3RRY) out:\n%s\n", strncpy(str1, "YEAH", 3));
	printf("ft_strncpy() opt2 (len < len(src) - YEAL CH3RRY) out:\n%s\n", ft_strncpy(str2, "YEAH", 3));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset
	// now len > len(src)
	printf("strncpy() opt2 (len > len(src) YEAH) out:\n%s\n", strncpy(str1, "YEAH", 5));
	printf("ft_strncpy() opt2 (len > len(src) YEAH) out:\n%s\n", ft_strncpy(str2, "YEAH", 5));
	checker(str1, str2, ft_cmp_s);
	ft_strcpy(str1, S_TEST); ft_strcpy(str2, S_TEST); //reset

	yellow() ; printf("\n ...GO FT_STRCAT...\n"); reset();	//FT_STRCAT
	printf("strcat() ok out:\n%s\n", strcat(str24, "ORLY!?"));
	printf("ft_strcat() ok out:\n%s\n", ft_strcat(str242, "ORLY!?"));
	checker(str24, str242, ft_cmp_s);
	strcpy(str24, "Almost empty..."); strcpy(str242, "Almost empty..."); //set args
	// now no s2	
	//printf("strcat() s2 = NULL out:\n%s\n", strcat(str24, NULL));
	//printf("ft_strcat() s2 = NULL out:\n%s\n", ft_strcat(str242, NULL));

	yellow() ; printf("\n ...GO FT_STRNCAT...\n"); reset();	//FT_STRNCAT
	printf("strncat() ok out:\n%s\n", strncat(str24, "ORLY!?", 6));
	printf("ft_strncat() ok out:\n%s\n", ft_strncat(str242, "ORLY!?", 6));
	checker(str24, str242, ft_cmp_s);
	strcpy(str24, "Almost empty..."); strcpy(str242, "Almost empty..."); //set args
	// now n < len (s2)
	printf("strncat() n < len(s2) out:\n%s\n", strncat(str24, "ORLY!?", 2));
	printf("ft_strncat() n < len(s2) out:\n%s\n", ft_strncat(str242, "ORLY!?", 2));
	checker(str24, str242, ft_cmp_s);
	strcpy(str24, "Almost empty..."); strcpy(str242, "Almost empty..."); //set args
	/*
	yellow(); printf("\n ...GO FT_STRLCAT...\n"); reset();	//FT_STRLCAT
	ft_cmp_s = (int (*)(void *, void *))intcmp; //set func
	n1 = strlcat(str24, "!!!!", 20); n2 = ft_strlcat(str242, "!!!!", 20);
	printf("strlcat() out:\n%i\n", n1); printf("ft_strlcat() out:\n%i\n", n2);
	checker((char *)&n1, (char *)&n2, ft_cmp_s);
	strncpy(str24, "Almost empty...", 5); strncpy(str242, "Almost empty...", 23); //set args

	// now let's go size < len(src)
	checker((char *)&n1, (char *)&n2, ft_cmp_s);
	strcpy(str1, S_TEST); strcpy(str2, S_TEST); //reset
	ft_cmp_s = (int (*)(void *, void *))strcmp; //reset func
*/


	return (0);
}
