/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_flags_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:49:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/15 11:18:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static bool	obf_flag_validate(string flags, string src_flags)
{
	if (*flags == FLAGS_FAKEING)
		_NOTIS_MSG(_ERRNO_FLAGDEP_FAKEING_, ft_strnstr(src_flags, "w", (flags - src_flags))
										&& ft_strnstr(src_flags, "o", (flags - src_flags)));
		if (*flags == FLAGS_OBFUSCT)
		_NOTIS_MSG(_ERRNO_FLAGDEP_OBFUSCT_, ft_strnstr(src_flags, "w", (flags - src_flags)));
	return (true);
}

bool	obf_flags_parser(string flags, t_file **file)
{
	const fptr_flags	flags_funcs[] = {&obf_flag_obfusct, &obf_flag_ccrot, &obf_flag_wss, &obf_flag_fake};
	const char			flags_all[] = {FLAGS_OBFUSCT, FLAGS_CAESARC, FLAGS_WHITESS, FLAGS_FAKEING};
	string				src_flags;
	bool				valid_flag;
	int					j = NEG;
	
	src_flags = flags;
	if (*flags == '-')
		++flags;
	while (*flags && (j = NEG))
	{
		while (++j < FLAGS_QTY)
			if (*flags == flags_all[j] && (valid_flag = true))
			{
				_NOTIS_F(obf_flag_validate(flags, src_flags));
				(*flags == FLAGS_FAKEING) ? ((*file)->generate_fake = true) : ((*file)->generate_fake = false);
				_NOTIS_MSG(_ERRNO_FILE_OBFUSCT_, flags_funcs[j](file));
			}
		if (!valid_flag)
		{
			_MSG("ERROR: ");
			write(1, &(*flags), sizeof(char));
			_MSG(" is invalid option. \\ ");
			return (false);
		}
		else
			valid_flag = !valid_flag;
		++(flags);
	}
	return (true);
}
