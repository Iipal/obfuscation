/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 23:57:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/08 13:56:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_ctype.h"

string	ft_strcasestr(cstring s, cstring find)
{
	char	c;
	char	sc;
	size_t	len;

	if ((c = *find++)) {
		c = ft_tolower(c);
		len = ft_strlen(find);
		do
		{
			do
			{
				if (!(sc = *s++))
					return (NULL);
			} while (ft_tolower(sc) != c);
		} while (ft_strncasecmp(s, find, len));
		s--;
	}
	return ((string)s);
}
