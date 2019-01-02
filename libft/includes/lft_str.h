/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:09:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 17:11:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_STR_H
# define LFT_STR_H

# include <string.h>
# include <stdlib.h>

# define _STR		typedef char*			string
# define _CSTR		typedef const char*		cstring
# define _USTR		typedef unsigned char*	ustring
# define _UCHAR		typedef unsigned char	uchar
# define _STRTAB	typedef char**			strtab

_STR;
_CSTR;
_USTR;
_UCHAR;
_STRTAB;

void	ft_strdel(string*);
void	ft_strclr(string);
void	ft_striter(string, void (*f)(string));
void	ft_striteri(string, void (*f)(unsigned int, string));

int		ft_atoi(string);
int		ft_atoi_base(cstring, int);
int		ft_strcmp(cstring, cstring);
int		ft_strncmp(cstring, cstring, size_t);
int		ft_strequ(char const*, char const*);
int		ft_strnequ(char const*, char const*, size_t);
int		ft_count_if(char const*, char const);

size_t	ft_strlen(cstring);
size_t	ft_strlcat(string, cstring, size_t);
size_t	ft_strlcpy(string, cstring, size_t);

string	ft_itoa(int);
string	ft_strdup(cstring);
string	ft_strndup(cstring, size_t);
string	ft_strcpy(string, cstring);
string	ft_strncpy(string, cstring, size_t);
string	ft_strcat(string, cstring);
string	ft_strncat(string, cstring, size_t);
string	ft_strchr(cstring, int);
string	ft_strrchr(cstring, int);
string	ft_strstr(cstring, cstring);
string	ft_strnstr(cstring, cstring, size_t);
string	ft_strnew(size_t);
string	ft_strmap(char const*, char (*f)(char));
string	ft_strmapi(char const*, char (*f)(unsigned int, char));
string	ft_strsub(char const*, unsigned int, size_t);
string	ft_strjoin(char const*, char const *);
string	ft_strtrim(char const*);
strtab	ft_strsplit(char const*, char);

#endif
