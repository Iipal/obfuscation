/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obfuscation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:28:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 03:31:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBFUSCATION_H
# define OBFUSCATION_H

# include "../libft/includes/libft.h"
# include <strings.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>

# define NEG			-1
# define ZERO			0

# define OBF_LINE_LENTH	510

# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSGN(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_FMSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_NMSG(msg, ex) if (!(ex)) { _MSG(msg); return (NULL); }
# define _NOTIS_N(ex) if (!(ex)) return (NULL)

# define _COMMENTARY_			"///"

# define _ERR_FILE_OPENING_		"Failed opening source file"
# define _ERR_FILE_READING_		"File reading error."
# define _ERR_FILE_INVALID_		"File validating error."
# define _ERR_FILE_CONCATE_		"Obfuscate processing error."

# define _ERR_INF_MEM_ALLOC_	"Memory allocating error \\ "
# define _ERR_INF_FILE_EMPTY_	"Empty file \\ "
# define _ERR_INF_FILE_REOPEN_	"Failed file re-opening \\ "
# define _ERR_INF_FILE_O_COMM_	"Only comments in file \\ "

# define _MSG_START_READ_		"Source file reading: "
# define _MSG_START_VALID_		"File validating: "
# define _MSG_START_CONCAT_		"Obfuscating: "
# define _MSG_END_OK_			"OK."

typedef enum	e_bool { false, true }	bool;

typedef struct	s_file
{
	strtab	tab;
	long	lines;
}				t_file;

#endif
