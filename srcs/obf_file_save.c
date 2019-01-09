/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:55:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/09 15:08:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

bool	obf_file_save(t_file *file, string src_file_name)
{
	int		i = NEG;
	int		fd;
	string	file_name;

	file_name = ft_strdup(_FILE_SAVE_PREF_);
	file_name = ft_strcat(file_name, src_file_name);
	_MSG("Saving to file \'"); _MSG(file_name); write(1, "\': ", _RSIZEOF(3));
	_NOTIS_FMSG(_ERR_INF_FILE_REOPEN_, !(!(fd = open(file_name, O_RDWR | O_CREAT, 0644)) || fd < 0));
	while (++i < file->lines)
	{
		write(fd, file->tab[i], _RSIZEOF(strlen(file->tab[i])));
		write(fd, "\n", sizeof(char));
	}
	close(fd);
	ft_strdel(&file_name);
	_MSGN(_MSG_OK_);
	return (true);
}
