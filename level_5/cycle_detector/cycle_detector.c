/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:15:31 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/27 17:34:12 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int        cycle_detector(const t_list *list)
{
    t_list *current;
    t_list *next;

    current = (t_list *)list;
    next = list->next;
    while (next)
    {
        if (current == next)
            return (1);
        current = current->next;
        next = next->next;
        if (next)
            next = next->next;
    }
    return (0);
}
