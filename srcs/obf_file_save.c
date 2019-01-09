/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:55:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/09 23:47:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

bool	obf_file_save(t_file *file, string src_file_name)
{
	int		i = NEG;
	int		fd;
	size_t	file_name_sizeof = _RSIZEOF(strlen(_FILE_SAVE_PREF_) + strlen(src_file_name) + 1);
	string	file_name;

	file_name = (string)malloc(file_name_sizeof);
	file_name = (string)memset(file_name, '\0', file_name_sizeof);
	file_name = strcat(file_name, _FILE_SAVE_PREF_);
	file_name = strcat(file_name, src_file_name);
	_MSG("Saving to file \'"); _MSG(file_name); write(1, "\': ", _RSIZEOF(3));
	_NOTIS_FMSG(_ERRNO_FILE_OPENING_, !(!(fd = open(file_name, O_RDWR | O_CREAT, 0644)) || fd < 0));
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
