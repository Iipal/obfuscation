/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:03:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 10:39:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_put.h"

void	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
}
