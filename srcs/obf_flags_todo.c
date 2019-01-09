/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_flags_todo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:21:37 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/09 14:40:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

bool	obf_flag_doall(t_file **file)
{
	_NOTIS_MSG(_ERRNO_FILE_INVALID_, *file = obf_file_cut_whitespaces(*file));
	_NOTIS_MSG("", obf_file_ccrot(*file));
	_NOTIS_MSG(_ERRNO_FILE_OBFUSCT_, *file = obf_file_concat(*file));
	return (true);
}

bool	obf_flag_wss_concat(t_file **file)
{
	if (*file)
		printf("-wc\n");
	return (true);
}

bool	obf_flag_wss_ccrot(t_file **file)
{
	if (*file)
		printf("-wr\n");
	return (true);
}

bool	obf_flag_wss(t_file **file)
{
	if (*file)
		printf("-wo\n");
	return (true);
}

// _NOTIS_MSG(_ERRNO_FILE_INVALID_, file = obf_file_cut_whitespaces(file));
// _NOTIS_MSG(_ERRNO_FILE_OBFUSCT_, file = obf_file_concat(file));
