/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obfuscation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:29:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 15:44:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void		obf_print_usage(void)
{
	_MSG("Not enought or too many arguments.\n\n");
	_MSG("Program usage:\n");
	_MSG("\tFirst argument: source file.\n");
	_MSG("\tSecond argument: destination file name.\n");
	_MSG("\n\tExample: ./obfuscation source.cfg destination.\n");
	_MSG("\nNote: Second argument file should not exist, it's will created by program.\n");
}

static t_file	*obf_file_reader(int fd, cstring file_name)
{
	t_file	*source_file;
	string	temp;
	long	i = ZERO;

	_MSG(_MSG_START_READ_);
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, source_file = (t_file*)malloc(sizeof(t_file)));
	source_file->lines = ZERO;
	while (ft_gnl(fd, &temp) > ZERO && ++(source_file->lines))
		free(temp);
	close(fd);
	_NOTIS_NMSG(_ERR_INF_FILE_EMPTY_, source_file->lines);
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, source_file->tab = (strtab)malloc(sizeof(string) * source_file->lines));
	_NOTIS_NMSG(_ERR_INF_FILE_REOPEN_, !(!(fd = open(file_name, O_RDONLY)) || fd < 0));
	while (ft_gnl(fd, &temp) > ZERO)
	{
		source_file->tab[i++] = strdup(temp);
		ft_strdel(&temp);
	}
	close(fd);
	_MSGN(_MSG_END_OK_);
	return (source_file);
}

static void		obf_free_file(t_file *file)
{
	long	i = NEG;

	while (++i < file->lines)
		ft_strdel(&(file->tab[i]));
	free(file->tab);
	file->tab = NULL;
	free(file);
}

static void		obf_blank_inline_comments(string line)
{
	long	i = NEG;
	string	temp = NULL;

	temp = strstr(line, _COMMENTARY_);
	if (temp)
		while (temp[++i])
			temp[i] = ' ';
}

static string	obf_cut_line_whitespaces(string line)
{
	string	out;
	long	i = ZERO;
	long	end = strlen(line);
	long	start = ZERO;
	char	temp[end + 1];

	bzero(temp, end + 1);
	while (line[start] && (isblank(line[start]) || line[start] == '\r'))
		++start;
	while (end > 0 && (isblank(line[end]) || line[end] == '\r'))
		--end;
	while (line[start])
		if (isblank(line[start]) || line[start] == '\r')
		{
			temp[i++] = ' ';
			while (isblank(line[start]) || line[start] == '\r')
				++start;
		}
		else
			temp[i++] = line[start++];
	free(line);
	out = strdup(temp);
	return (out);
}

static bool		obf_valid_line(string line)
{
	long	empty_line = ZERO;
	long	len = strlen(line);
	long	i = NEG;

	if (ft_strnstr(line, _COMMENTARY_, strlen(_COMMENTARY_)))
		return (false);
	else
	{
		while (line[++i])
			if (isblank(line[i]) || line[i] == '\r')
				++empty_line;
		if (empty_line == len)
			return (false);
	}
	return (true);
}

static t_file	*obf_cut_file_whitespaces(t_file *file)
{
	t_file	*out_file;
	long	valid_lines = ZERO;
	long	i = NEG;
	long	j = ZERO;

	_MSG(_MSG_START_VALID_);
	while (++i < file->lines)
 		if (obf_valid_line(file->tab[i]))
			++valid_lines;
	_NOTIS_NMSG(_ERR_INF_FILE_O_COMM_, valid_lines);
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, out_file = (t_file*)malloc(sizeof(t_file)));
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, out_file->tab = (strtab)malloc(sizeof(string) * valid_lines));
	out_file->lines = valid_lines;
	i = NEG;
	while (++i < file->lines)
		if (obf_valid_line(file->tab[i]))
		{
			out_file->tab[j] = strdup(file->tab[i]);
			obf_blank_inline_comments(out_file->tab[j]);
			out_file->tab[j] = obf_cut_line_whitespaces(out_file->tab[j]);
			++j;
		}
	obf_free_file(file);
	_MSGN(_MSG_END_OK_);
	return (out_file);
}

static t_file	*obf_concat_file(t_file *file)
{
	t_file	*concat_file = NULL;
	long	i = ZERO;

	_MSG(_MSG_START_CONCAT_);
	while (i < file->lines)
		++i;
	_NOTIS_N(concat_file);
	_MSG(_MSG_END_OK_);
	return (concat_file);
}

int				main(int argc, char const *argv[])
{
	t_file		*file;
	int			fd;

	--argc;
	++argv;
	if (!argc || argc < 2 || argc > 2)
	{
		obf_print_usage();
		exit(EXIT_FAILURE);
	}
	_NOTIS_MPE(_ERR_FILE_OPENING_, !(!(fd = open(*argv, O_RDONLY)) || fd < 0));
	_NOTIS_MSG(_ERR_FILE_READING_, file = obf_file_reader(fd, *argv));
	_NOTIS_MSG(_ERR_FILE_INVALID_, file = obf_cut_file_whitespaces(file));
	long i = 0;
	while (i < file->lines)
		printf("%s\n", file->tab[i++]);
	_NOTIS_MSG(_ERR_FILE_CONCATE_, file = obf_concat_file(file));
}
