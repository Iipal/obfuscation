/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:52:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 15:57:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

void	obf_file_free(t_file *file)
{
	long	i = NEG;

	while (++i < file->lines)
		ft_strdel(&(file->tab[i]));
	free(file->tab);
	file->tab = NULL;
	free(file);
}