/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_cut_whitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:50:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 16:32:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void		obf_inline_blank_comments(string line)
{
	long	i = NEG;
	string	temp = NULL;

	temp = strstr(line, _COMMENTARY_);
	if (temp)
		while (temp[++i])
			temp[i] = ' ';
}

static string	obf_line_cut_whitespaces(string line)
{
	string	out;
	long	i = ZERO;
	long	end = strlen(line);
	long	start = ZERO;
	char	temp[end + 1];

	bzero(temp, sizeof(char) * (end + 1));
	while (line[start] && ft_isblank(line[start]))
		++start;
	while (end > 0 && ft_isblank(line[end - 1])) 
		--end;
	while (start < end)
		if (ft_isblank(line[start]))
		{
			temp[i++] = ' ';
			while (start < end && ft_isblank(line[start]))
				++start;
		}
		else
			temp[i++] = line[start++];
	free(line);
	out = strdup(temp);
	return (out);
}

static bool 	obf_line_validating(string line)
{
	long	empty_line = ZERO;
	long	len = ZERO;
	long	i = NEG;

	if (ft_strnstr(line, _COMMENTARY_, strlen(_COMMENTARY_)))
		return (false);
	else
	{
		len = strlen(line);
		while (line[++i])
			if (ft_isblank(line[i]))
				++empty_line;
		if (empty_line == len)
			return (false);
	}
	return (true);
}

t_file			*obf_file_cut_whitespaces(t_file *file)
{
	t_file	*out_file;
	long	valid_lines = ZERO;
	long	i = NEG;
	long	j = ZERO;

	_MSG(_MSG_START_VALID_);
	while (++i < file->lines)
 		if (obf_line_validating(file->tab[i]))
			++valid_lines;
	_NOTIS_NMSG(_ERR_INF_FILE_O_COMM_, valid_lines);
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, out_file = (t_file*)malloc(sizeof(t_file)));
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, out_file->tab = (strtab)malloc(sizeof(string) * valid_lines));
	out_file->lines = valid_lines;
	i = NEG;
	while (++i < file->lines)
		if (obf_line_validating(file->tab[i]))
		{
			out_file->tab[j] = strdup(file->tab[i]);
			obf_inline_blank_comments(out_file->tab[j]);
			out_file->tab[j] = obf_line_cut_whitespaces(out_file->tab[j]);
			++j;
		}
	obf_file_free(file);
	_MSGN(_MSG_END_OK_);
	return (out_file);
}

