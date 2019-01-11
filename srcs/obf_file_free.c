/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:52:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/11 17:41:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

void	obf_file_free(t_file *file)
{
	int	i = NEG;

	while (++i < file->lines)
		ft_strdel(&(file->tab[i]));
	free(file->tab);
	free(file);
}
