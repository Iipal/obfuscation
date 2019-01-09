/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obfuscation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:28:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/09 14:11:47 by tmaluh           ###   ########.fr       */
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
**	'-all':	delete whitepsaces, obfuscate & rename
**	'-wc':	delete whitespaces and concatenate all lines without rename.
**	'-wr':	delete whitespaces and rename without concatenate all lines.
**	'-wo':	delete whitespaces without rename and without concatenate all lines.
*/

# define FLAGS_QTY			4
# define FLAGS_ALL			"-all"
# define FLAGS_WC			"-wc"
# define FLAGS_WR			"-wr"
# define FLAGS_WO			"-wo"

# define OBF_LINE_LENGTH	510
# define COMMENTARY			"///"
# define CC_ROT				13

# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSGN(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_FMSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_NMSG(msg, ex) if (!(ex)) { _MSG(msg); return (NULL); }
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)

# define _RSIZEOF(len) sizeof(char) * (len)

# define _FILE_SAVE_PREF_	"obf_"
# define _FILE_SAVE_NAME(src_file) src_file = strcat(strdup(_FILE_SAVE_PREF_), src_file)

typedef enum	e_bool { false, true }	bool;
typedef struct	s_file
{
	strtab	tab;
	int		lines;
}				t_file;

int				obf_flags_parsing(string flag);

t_file			*obf_file_reader(int *fd, cstring file_name);
t_file			*obf_file_cut_whitespaces(t_file *file);
t_file			*obf_file_concat(t_file *file);
bool			obf_file_save(t_file *file, string file_name);

void			obf_file_free(t_file *file);

#endif
