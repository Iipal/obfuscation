/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obfuscation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:29:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 15:59:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void	obf_print_usage(void)
{
	_MSG("Not enought or too many arguments.\n\n");
	_MSG("Program usage:\n");
	_MSG("\tFirst argument: source file.\n");
	_MSG("\tSecond argument: destination file name.\n");
	_MSG("\n\tExample: ./obfuscation source.cfg destination.\n");
	_MSG("\nNote: Second argument file should not exist, it's will created by program.\n");
}

int			main(int argc, char const *argv[])
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
	_NOTIS_MSG(_ERR_FILE_INVALID_, file = obf_file_cut_whitespaces(file));
	long i = 0;
	while (i < file->lines)
		printf("%s\n", file->tab[i++]);
	_NOTIS_MSG(_ERR_FILE_CONCATE_, file = obf_file_concat(file));
}
