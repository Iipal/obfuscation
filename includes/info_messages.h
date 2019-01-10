/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_messages.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:42:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 10:27:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_MESSAGES_H
# define INFO_MESSAGES_H

# define _ERRNO_FLAG_PARSING_	"What i must to do ?"
# define _ERRNO_FILE_OPENING_	"Failed opening source file"
# define _ERRNO_FILE_READING_	"File reading error."
# define _ERRNO_FILE_INVALID_	"File validating error."
# define _ERRNO_FILE_OBFUSCT_	"Obfuscate processing error."
# define _ERRNO_FILE_OSAVING_	"File saving error."
# define _ERRNO_FILE_ENCRYPT_	"Encryprint error."

# define _ERR_INF_MEM_ALLOC_	"Memory allocating error \\ "
# define _ERR_INF_FILE_EMPTY_	"Empty file \\ "
# define _ERR_INF_FILE_REOPEN_	"Failed file re-opening \\ "
# define _ERR_INF_FILE_O_COMM_	"Only comments in file \\ "
# define _ERR_INF_FLAG_ISNTEX_	" isn't exist. "

# define _MSG_START_FPARSE_		"Check flags: "
# define _MSG_START_READ_		"Source file reading: "
# define _MSG_START_CUTWSS_		"Cuting whitespace: "
# define _MSG_START_VARSCCR_	"Encrypting: "
# define _MSG_START_OBFUSCATE_	"Obfuscating: "
# define _MSG_OK_				"OK."

# define _ERRNO_FLAG_OBFUSCT_	"-o option cant be used before -w or without -w. Exit."
# define _ERRNO_FLAG_FAKEING_	"-f option cant be used before -w and -o or without -w and -o. Exit."

#endif
