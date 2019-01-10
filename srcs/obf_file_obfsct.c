/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_obfsct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:53:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 10:42:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void	obf_lines_obfusct(string *dest, string src)
{
	*dest = strcat(*dest, src);
		if ((*dest)[strlen(*dest) - 1] != ';')
			*dest = strcat(*dest, ";");
}

/*
**	obf_concated_lines used for search how much memory need to allocate new t_file*
*/

static int	obf_obfuscted_lines(t_file *file)
{
	string	temp;
	int		i = NEG;
	int		concated_lines = ZERO;

	_NOTIS_F(temp = (string)malloc(_RSIZEOF(OBF_LINE_LENGTH + 1)));
	ft_bzero(temp, _RSIZEOF(OBF_LINE_LENGTH + 1));
	while (++i < file->lines)
		if (strlen(temp) + strlen(file->tab[i]) < OBF_LINE_LENGTH)
			obf_lines_obfusct(&temp, file->tab[i]);
		else
		{
			++concated_lines;
			ft_bzero(temp, _RSIZEOF(OBF_LINE_LENGTH + 1));
			obf_lines_obfusct(&temp, file->tab[i]);
		}
	if (*temp)
		++concated_lines;
	ft_strdel(&temp);
	return (concated_lines);
}

t_file		*obf_file_obfusct(t_file *file)
{
	t_file	*concated_file;
	string	temp;
	int		i = NEG;
	int		j = NEG;

	_MSG(_MSG_START_OBFUSCATE_);
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, concated_file = (t_file*)malloc(sizeof(t_file)));
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, concated_file->lines = obf_obfuscted_lines(file));
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, concated_file->tab = (strtab)malloc(sizeof(string) * concated_file->lines));
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, temp = (string)malloc(_RSIZEOF(OBF_LINE_LENGTH + 1)));
	ft_bzero(temp, _RSIZEOF(OBF_LINE_LENGTH + 1));
	while (++i < file->lines)
		if (strlen(temp) + strlen(file->tab[i]) < OBF_LINE_LENGTH)
			obf_lines_obfusct(&temp, file->tab[i]);
		else
		{
			concated_file->tab[++j] = strdup(temp);
			ft_bzero(temp, _RSIZEOF(OBF_LINE_LENGTH + 1));
			obf_lines_obfusct(&temp, file->tab[i]);
		}
	if (*temp)
		concated_file->tab[++j] = strdup(temp);
	ft_strdel(&temp);
	obf_file_free(file);
	_MSGN(_MSG_OK_);
	return (concated_file);
}
