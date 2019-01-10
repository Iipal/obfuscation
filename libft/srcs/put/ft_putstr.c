/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:36:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 10:38:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_put.h"

void	ft_putstr(char const *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar(s[i++]);
}
