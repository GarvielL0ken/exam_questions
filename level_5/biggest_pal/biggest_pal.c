/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:56:20 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/27 17:13:53 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int    ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int     is_pal(char *s, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (s[i] != s[len])
            return (0);
        i++;
        len--;
    }
    return (1);
}

void    biggest_pal(char *s)
{
    int i;
    int len;
    int max;
    int start;

    i = 0;
    len = ft_strlen(s);
    max = 0;
    start = 0;
    while (len >= max && len)
    {
        if (is_pal(&s[i], len))
        {
            start = i;
            max = len;
        }
        len--;
        if (len < max)
        {
            i++;
            len = ft_strlen(&s[i]);
        }
    }
    i = 0;
    while (i <= max)
    {
        write(1, &(s[start + i]), 1);
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        biggest_pal(argv[1]);
    write(1, "\n", 1);
}