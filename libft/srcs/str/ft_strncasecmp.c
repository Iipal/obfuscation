/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:06:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/08 13:18:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_ctype.h"

int		ft_strncasecmp(cstring s1, cstring s2, size_t n)
{
	ustring	us1;
	ustring	us2;

	us1 = (ustring)s1;
	us2 = (ustring)s2;
	if (n)
		while (n--)
		{
			if (ft_tolower(*us1) != ft_tolower(*us2))
				return (ft_tolower(*us1) - ft_tolower(*us2));
			if (*us1++ == '\0')
				break ;
			us2++;
		}
	return (0);
}
