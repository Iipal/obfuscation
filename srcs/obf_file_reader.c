/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:46:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/27 19:20:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/obfuscation.h"

t_file	*obf_file_reader(int *fd, cstring file_name)
{
	t_file	*source_file;
	string	temp;
	long	i = ZERO;

	_MSG(_MSG_START_READ_);
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, source_file = (t_file*)malloc(sizeof(t_file)));
	source_file->lines = ZERO;
	while (ft_gnl(*fd, &temp) > ZERO && ++(source_file->lines))
	{
		if (strlen(temp) >= 510)
		{
			_MSG("error: Line "); ft_putnbr(source_file->lines); _MSGN(" has 510 or more symbols:");
			write(1, temp, 42);
			_MSGN("...");
			ft_strdel(&temp);
			exit(EXIT_FAILURE);
		}
		ft_strdel(&temp);
	}
	close(*fd);
	_NOTIS_NMSG(_ERR_INF_FILE_EMPTY_, source_file->lines);
	_NOTIS_NMSG(_ERR_INF_MEM_ALLOC_, source_file->tab = (strtab)malloc(sizeof(string) * source_file->lines));
	_NOTIS_NMSG(_ERR_INF_FILE_REOPEN_, !(!(*fd = open(file_name, O_RDONLY)) || *fd < 0));
	while (ft_gnl(*fd, &temp) > ZERO)
	{
		source_file->tab[i++] = strdup(temp);
		ft_strdel(&temp);
	}
	close(*fd);
	_MSGN(_MSG_OK_);
	return (source_file);
}