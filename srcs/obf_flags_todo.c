/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_flags_todo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:21:37 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/09 19:50:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

bool	obf_flag_wss(t_file **file)
{
	_NOTIS_MSG(_ERRNO_FILE_INVALID_, *file = obf_file_cut_whitespaces(*file));
	return (true);
}

bool	obf_flag_ccrot(t_file **file)
{
	_NOTIS_MSG(_ERRNO_FILE_ENCRYPT_, obf_file_ccrot(*file));
	return (true);
}

bool	obf_flag_concat(t_file **file)
{
	_NOTIS_MSG(_ERRNO_FILE_OBFUSCT_, *file = obf_file_concat(*file));
	return (true);
}
