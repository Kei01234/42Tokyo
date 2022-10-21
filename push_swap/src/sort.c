/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 05:42:53 by kishigam          #+#    #+#             */
/*   Updated: 2022/10/21 09:33:48 by kishigam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	small_sort(t_stack **a, t_stack **b) // ソートがうまくいったかどうかで返り値を返すように変更してみるのあり
{
	int	size;

	if (stack_size(*a) < 2)
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_3_args(a);
	else
		sort_5_args(a, b);
}

void	stack_sorting(t_stack **a, t_stack **b)
{
	if ((stack_size(*a) < 4) || (stack_size(*a) == 5)) // なぜサイズが4未満か5のときで処理をわけたのか
		small_sort(a, b);
	else
		radix_sort(a, b);
}
