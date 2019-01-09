/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:29:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/09 14:45:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void	obf_print_usage(void)
{
	_MSG("Missing files or flags for obfuscate.\n\n");
	_MSG("Program usage:\n");
	_MSG("\tFirst argument should be flags.(more info in README.md)\n");
	_MSG("\tAll arguments after first argument - files for obfuscating\n");
	_MSG("\tAfter correct work of program you can find file with name 'obf_*file_name*'\n");
	_MSG("\tExample: ./obfuscation -oo *file_name1*.cfg *file_name2*.cfg\n");	
}

int			main(int argc, char *argv[])
{
	const fptr_flags	flag[] = {&obf_flag_doall, &obf_flag_wss_concat, &obf_flag_wss_ccrot, &obf_flag_wss};
	t_file				*file;
	int					fd;
	int					i = NEG;
	int					fselector;

	--argc;
	++argv;
	if (!argc || argc < OBF_ARGS_MIN)
	{
		obf_print_usage();
		exit(EXIT_FAILURE);
	}
	_NOTIS_MSG(_ERRNO_FLAG_PARSING_, fselector = obf_flags_parsing(argv[OBF_ARGS_FLAG]));
	--fselector;
	while (++i < argc - 1)
	{
		write(1, "\t", _RSIZEOF(1)); _MSG(argv[i + 1]); write(1, ":\n", _RSIZEOF(2));
		_NOTIS_MPE(_ERRNO_FILE_OPENING_, !(!(fd = open(argv[i + 1], O_RDONLY)) || fd < 0));
		_NOTIS_MSG(_ERRNO_FILE_READING_, file = obf_file_reader(&fd, argv[i + 1]));
		_NOTIS_MSG(_ERRNO_FILE_OBFUSCT_, flag[fselector](&file));
		_NOTIS_MSG(_ERRNO_FILE_OSAVING_, obf_file_save(file, _FILE_SAVE_NAME(argv[i + 1])));
		obf_file_free(file);
	}
	system("leaks obf");
}
