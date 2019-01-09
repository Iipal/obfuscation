/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obfuscation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:28:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 00:42:32 by tmaluh           ###   ########.fr       */
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

# define OBF_ARGS_MIN		2
# define OBF_ARGS_FLAG		0

/*
**	'o':	option for obfuscate.
**	'w':	option for delete whitespaces.
**	'r':	option for rename variables.
*/

# define FLAGS_QTY			4

# define FLAGS_SPACES		'w'
# define FLAGS_RENAME		'r'
# define FLAGS_CONCAT		'o'
# define FLAGS_FAKING		'f'

# define OBF_LINE_LENGTH	510
# define OBF_FAKE_ALIAS_LEN	(OBF_LINE_LENGTH - 16)
# define COMMENTARY			"//"
# define CC_ROT				13

# define VPREF_QTY			5
# define VPREF_OWL			"OWL_"
# define VPREF_OWLPLAY		"OWLPLAY_"
# define VPREF_OWLECHO		"OWLECHO_"
# define VPREF_PLUSOWL		"+OWL_"
# define VPREF_MINUSOWL		"-OWL_"

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

typedef enum	e_bool { false, true }	bool;
typedef struct	s_file
{
	strtab	tab;
	int		lines;
}				t_file;
typedef bool (*fptr_flags)(t_file**);

t_file			*obf_file_reader(int *fd, cstring file_name);
t_file			*obf_file_cut_whitespaces(t_file *file);
t_file			*obf_file_concat(t_file *file);
bool			obf_file_ccrot(t_file *file);
void			obf_file_fake(t_file *file);

bool			obf_flag_wss(t_file **file);
bool			obf_flag_ccrot(t_file **file);
bool			obf_flag_concat(t_file **file);
bool			obf_flag_fake(t_file **file);

bool			obf_file_save(t_file *file, string src_file_name);
void			obf_file_free(t_file *file);

#endif
