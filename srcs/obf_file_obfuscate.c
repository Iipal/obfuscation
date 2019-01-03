/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_obfuscate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:53:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/03 21:46:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void	obf_lines_concat(string *dest, string src)
{
	*dest = strcat(*dest, src);
		if ((*dest)[strlen(*dest) - 1] != ';')
			*dest = strcat(*dest, ";");
}

bool		obf_file_obfuscate(t_file *file, cstring dst_file)
{
	string	temp;
	long	i = NEG;
	int		fd;

	_MSG(_MSG_START_CONCAT_);
	_NOTIS_FMSG(_ERR_INF_MEM_ALLOC_, temp = (string)malloc(sizeof(char) * (OBF_LINE_LENGTH + 1)));
	_NOTIS_FMSG(_ERR_INF_FILE_REOPEN_, !(!(fd = open(dst_file, O_RDWR | O_CREAT, 0644)) || fd < 0));
	ft_bzero(temp, sizeof(char) * (OBF_LINE_LENGTH + 1));
	while (++i < file->lines)
		if (strlen(temp) + strlen(file->tab[i]) < OBF_LINE_LENGTH)
			obf_lines_concat(&temp, file->tab[i]);
		else
		{
			write(fd, temp, sizeof(char) * strlen(temp));
			write(fd, "\n", sizeof(char));
			ft_bzero(temp, sizeof(char) * (OBF_LINE_LENGTH + 1));
			obf_lines_concat(&temp, file->tab[i]);
		}
	if (*temp)
		write(fd, temp, sizeof(char) * strlen(temp));
	ft_strdel(&temp);
	close(fd);
	_MSGN(_MSG_END_OK_);
	return (true);
}
