/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_concat_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:53:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 16:32:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/obfuscation.h"

t_file	*obf_file_concat(t_file *file)
{
	t_file	*concat_file = NULL;
	long	i = NEG;
	string	temp = (string)malloc(sizeof(char) * (OBF_LINE_LENTH + 1));

	bzero(temp, sizeof(char) * (OBF_LINE_LENTH + 1));
	_MSG(_MSG_START_CONCAT_);
	while (++i < file->lines)
	{
		if (strlen(temp) + strlen(file->tab[i + 1]) < OBF_LINE_LENTH)
		{
			temp = strcat(file->tab[i], file->tab[i + 1]);
		}
	}
	_NOTIS_N(concat_file);
	_MSG(_MSG_END_OK_);
	return (concat_file);
}
