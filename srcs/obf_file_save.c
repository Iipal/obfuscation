/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:55:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/15 10:16:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

bool		obf_file_save(t_file *file, string src_file_name)
{
	string	file_name;
	int		i = NEG;
	int		fd;

	_FILE_SAVE_PREF_GENERATE(file_name, src_file_name, _RSIZEOF(strlen(_FILE_SAVE_PREF_) + strlen(src_file_name) + 1));
	_MSG("Saving to file \'"); _MSG(file_name); write(1, "\': ", _RSIZEOF(3));
	_NOTIS_FMSG(_ERR_INF_FILE_SAVING_, !(!(fd = open(file_name, O_RDWR | O_CREAT, 0644)) || fd < 0));
	while (++i < file->lines)
	{
		write(fd, file->tab[i], _RSIZEOF(strlen(file->tab[i])));
		write(fd, "\n", _RSIZEOF(1));
	}
	close(fd);
	ft_strdel(&file_name);
	_MSGN(_MSG_OK_);
	return (true);
}
