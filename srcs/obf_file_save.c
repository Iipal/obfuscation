/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:55:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 15:20:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void	obf_generate_fake_command(string *line, int fd)
{
	static char	curr_letter;
	size_t		line_len;

	if (!curr_letter)
		curr_letter = 'a';
	if ((line_len = strlen(*line)) < OBF_FAKE_ALIAS_MAXLEN)
	{
		write(fd, "ALIAS \"", _RSIZEOF(7));
		line_len += 8;
		while (line_len++ < OBF_LINE_LENGTH - 7)
			write(fd, &curr_letter, _RSIZEOF(1));
		write(fd, "\" \"", _RSIZEOF(3));
		line_len += 2;
		while(line_len++ < OBF_LINE_LENGTH - 2)
			write(fd, &curr_letter, _RSIZEOF(1));
		write(fd, "\";", _RSIZEOF(2));
		++curr_letter;
		if (curr_letter == 'z' + 1)
			curr_letter = 'A';
		else if (curr_letter == 'Z' + 1)
			curr_letter = 'a';
	}
}

bool		obf_file_save(t_file *file, string src_file_name)
{
	string	file_name;
	int		i = NEG;
	int		fd;

	_FILE_SAVE_PREF_GENERATE(file_name, src_file_name, _RSIZEOF(strlen(_FILE_SAVE_PREF_) + strlen(src_file_name) + 1));
	_MSG("Saving to file \'"); _MSG(file_name); write(1, "\': ", _RSIZEOF(3));
	_NOTIS_FMSG(_ERRNO_FILE_OPENING_, !(!(fd = open(file_name, O_RDWR | O_CREAT, 0644)) || fd < 0));
	while (++i < file->lines)
	{
		write(fd, file->tab[i], _RSIZEOF(strlen(file->tab[i])));
		if (file->generate_fake)
			obf_generate_fake_command(&(file->tab[i]), fd);
		write(fd, "\n", _RSIZEOF(1));
	}
	close(fd);
	ft_strdel(&file_name);
	_MSGN(_MSG_OK_);
	return (true);
}
