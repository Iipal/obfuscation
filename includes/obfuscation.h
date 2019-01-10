/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obfuscation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:28:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 15:00:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBFUSCATION_H
# define OBFUSCATION_H

# include "../libft/includes/libft.h"
# include "info_messages.h"
# include <strings.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>
# include <sys/stat.h>

# define NEG				-1
# define ZERO				0

/*
**	'o':	option for obfuscate.
**	'w':	option for delete whitespaces.
**	'r':	option for rename variables.
*/

# define OBF_ARGS_FLAG		0

# define FLAGS_QTY			4
# define FLAGS_WHITESS		'w'
# define FLAGS_CAESARC		'r'
# define FLAGS_OBFUSCT		'o'
# define FLAGS_FAKEING		'f'

# define COMMENTARY			"//"

# define CC_ROT				13

# define VPREF_QTY			5
# define VPREF_OWL			"OWL_"
# define VPREF_OWLPLAY		"OWLPLAY_"
# define VPREF_OWLECHO		"OWLECHO_"
# define VPREF_PLUSOWL		"+OWL_"
# define VPREF_MINUSOWL		"-OWL_"

# define OBF_LINE_LENGTH		510
# define OBF_FAKE_ALIAS_MAXLEN	(OBF_LINE_LENGTH - 16)

# define ARGS_MIN	2
# define _ARGS_ISVALID(ac, av, ufunc) { --ac; ++av; if (!ac || ac < ARGS_MIN) { ufunc(); return (false); } }

# define _RSIZEOF(len) sizeof(char) * (len)
# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSGN(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_FMSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_NMSG(msg, ex) if (!(ex)) { _MSG(msg); return (NULL); }
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)

# define _FILE_SAVE_PREF_	"obf_"
# define _FILE_SAVE_PREF_GENERATE(dest, src, len_sizeof) { \
	_NOTIS_FMSG(_ERR_INF_MEM_ALLOC_, dest = (string)malloc(len_sizeof)); \
	dest = (string)memset(dest, '\0', len_sizeof); \
	dest = strcat(dest, _FILE_SAVE_PREF_); dest = strcat(dest, src); }

typedef enum	e_bool { false, true }	bool;
typedef struct	s_file
{
	strtab	tab;
	int		lines;
	bool	generate_fake:1;
}				t_file;
typedef bool (*fptr_flags)(t_file**);

t_file			*obf_file_reader(int *fd, cstring file_name);
t_file			*obf_file_cut_whitespaces(t_file *file);
t_file			*obf_file_obfusct(t_file *file);
bool			obf_file_ccrot(t_file *file);
void			obf_file_fake(t_file *file);

bool			obf_flags_parser(string flags, t_file **file);

bool			obf_flag_wss(t_file **file);
bool			obf_flag_ccrot(t_file **file);
bool			obf_flag_obfusct(t_file **file);
bool			obf_flag_fake(t_file **file);

bool			obf_file_save(t_file *file, string src_file_name);
void			obf_file_free(t_file *file);

#endif
