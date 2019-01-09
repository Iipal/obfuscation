/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_flags_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:38:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/09 19:21:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

int		obf_flags_parsing(string flag)
{
	cstring	flags[] = {FLAGS_ALL, FLAGS_WC, FLAGS_WR, FLAGS_WO, FLAGS_RO};
	int		i = NEG;

	_MSG(_MSG_START_FPARSE_);
	while (++i < FLAGS_QTY)
		if (!ft_strncasecmp(flag, flags[i], _RSIZEOF(strlen(flags[i]))))
		{
			_MSGN(_MSG_OK_);
			return (++i);
		}
	_MSG(flag);
	_MSG(_ERR_INF_FLAG_ISNTEX_);
	return (false);
}
