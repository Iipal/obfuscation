/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:29:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 11:17:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void	obf_print_usage(void)
{
	_MSG("Missing files or flags for obfuscate.\n\n");
	_MSG("Program usage:\n");
	_MSG("\tFirst argument should be flags.(more info in README.md)\n");
	_MSG("\tAll arguments after first argument - files for obfuscating\n");
	_MSG("\tAfter correct work of program you can find file with name 'obf_*your_file_name*'\n");
	_MSG("\tExample: ./obfuscation -oo *your_file_name1*.cfg *your_file_name2*.cfg ...\n");	
}

static bool	obf_flag_validate(string flags, string src_flags)
{
	if (*flags == FLAGS_FAKEING)
		_NOTIS_MSG(_ERRNO_FLAG_FAKEING_, ft_strnstr(src_flags, "w", (flags - src_flags)) && ft_strnstr(src_flags, "o", (flags - src_flags)));
	if (*flags == FLAGS_OBFUSCT)
		_NOTIS_MSG(_ERRNO_FLAG_OBFUSCT_, ft_strnstr(src_flags, "w", (flags - src_flags)));
	return (true);
}

static bool	obf_flags_parser(string flags, t_file **file)
{
	const fptr_flags	flags_funcs[] = {&obf_flag_obfusct, &obf_flag_ccrot, &obf_flag_wss, &obf_flag_fake};
	char				flags_all[] = {FLAGS_OBFUSCT, FLAGS_CAESARC, FLAGS_WHITESS, FLAGS_FAKEING};
	string				src_flags;
	bool				valid_flag;
	int					j = NEG;
	
	src_flags = flags;
	
	while (*flags == '-')
		++flags;
	while (*flags && (j = NEG))
	{
		while (++j < FLAGS_QTY)
			if (*flags == flags_all[j] && (valid_flag = true))
			{
				_NOTIS_F(obf_flag_validate(flags, src_flags));
				_NOTIS_MSG(_ERRNO_FILE_OBFUSCT_, flags_funcs[j](file));
			}
		(!valid_flag) ? (bool)printf("%c invalid option.\n", *flags) : (valid_flag = !valid_flag);
		++(flags);
	}
	return (true);
}

int			main(int argc, char *argv[])
{
	t_file				*file;
	int					i = NEG;
	int					fd;

	--argc;
	++argv;
	if (!argc || argc < OBF_ARGS_MIN)
		obf_print_usage();
	else
		while (++i < argc - 1)
		{
			write(1, "\t", _RSIZEOF(1)); _MSG(argv[i + 1]); write(1, ":\n", _RSIZEOF(2));
			_NOTIS_MPE(_ERRNO_FILE_OPENING_, !(!(fd = open(argv[i + 1], O_RDONLY)) || fd < 0));
			_NOTIS_MSG(_ERRNO_FILE_READING_, file = obf_file_reader(&fd, argv[i + 1]));
			_NOTIS_MSG(_ERRNO_FLAG_PARSING_, obf_flags_parser(*argv, &file));
			_NOTIS_MSG(_ERRNO_FILE_OSAVING_, obf_file_save(file, argv[i + 1]));
			obf_file_free(file);
		}
}
