/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:14:14 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:35:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_ctype.h"

int		ft_toupper(int c)
{
	return ((c >= 'a' && c <= 'z') ? c -= 32 : c);
}
