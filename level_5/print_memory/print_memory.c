/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:08:24 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/27 16:52:51 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_byte(unsigned char c)
{
    char c_1;
    char c_16;

    c_16 = '0';
    while (c >= 16)
    {
        if (c_16 == '9')
            c_16 = 'a';
        else
            c_16++;
        c -= 16;
    }
    c_1 = '0';
    while (c > 0)
    {
        if (c_1 == '9')
            c_1 = 'a';
        else
            c_1++;
        c--;
    }
    write(1, &c_16, 1);
    write(1, &c_1, 1);
}

void    print_line_hex(unsigned char *s, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        print_byte(s[i]);
        i++;
        if (!(i % 2))
            write(1, " ", 1);
    }
    while (i < 16)
    {
        write(1, "  ", 2);
        i++;
        if (!(i % 2))
            write(1, " ", 1);
    }
}

void    print_line_char(unsigned char *s, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (' ' <= s[i] && s[i] < '~')
            write(1, &(s[i]), 1);
        else
            write(1, ".", 1);
        i++;
    }
}

void	print_memory(const void *addr, size_t size)
{
    unsigned char *arr;
    int i;

    arr = (unsigned char *)addr;
    i = 0;
    while (i + 16 < (int)size)
    {
        print_line_hex(&(arr[i]), 16);
        print_line_char(&(arr[i]), 16);
        write(1, "\n", 1);
        i += 16;
    }
    print_line_hex(&(arr[i]), (int)size - i);
    print_line_char(&(arr[i]), (int)size - i);
    write(1, "\n", 1);
}