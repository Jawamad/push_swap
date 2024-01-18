/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmuller <florianmuller@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:46:07 by florianmull       #+#    #+#             */
/*   Updated: 2024/01/18 13:46:56 by florianmull      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *node)
{
	t_pile	*prevtemp;
	int 	value;

	prevtemp = node->previous;
	value = prevtemp->value;
	prevtemp->value = node->value;
	node->value = value;
}

void	push(t_pile **ntpush, t_pile **pushpile)
{
	t_pile	*temppushn;
	t_pile	*temppushp;
	t_pile	*tempnodepush;

	if (*ntpush)
	{
		temppushn = (*ntpush)->next;
		temppushp = (*ntpush)->previous;
		temppushp->next = temppushn;
		temppushn->previous = temppushp;
		tempnodepush = *ntpush;
		*ntpush = temppushp;
		if (*pushpile)
		{
			temppushn =	(*pushpile)->next;
			tempnodepush->next = temppushn;
			tempnodepush->previous = *pushpile;
		}
		else
		{
			tempnodepush->next = tempnodepush;
			tempnodepush->previous = tempnodepush;
		}
		*pushpile = tempnodepush;
	}
}

void	rotate(t_pile **node, int nbrot)
{
	int	i;

	i = 0;
	while (i != nbrot)
	{
		*node = (*node)->previous;
		i++;
	}
}