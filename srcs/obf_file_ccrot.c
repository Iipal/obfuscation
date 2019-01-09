/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_ccrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:30:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/09 14:37:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

static void	obf_inlines_ccrot(string line_start, cstring vpref_search)
{
	int	i = NEG;

	if (!line_start)
		return ;
	while (line_start[++i] && !isblank(line_start[i]) && line_start[i] != '\"' && line_start[i] != ';')
		if (islower(line_start[i]))
			(line_start[i] + CC_ROT > 'z')
				? (line_start[i] = 'a' + (line_start[i] + CC_ROT - 'z'))
				: (line_start[i] += CC_ROT);
		else if (isupper(line_start[i]))
			(line_start[i] + CC_ROT > 'Z')
				? (line_start[i] = 'A' + (line_start[i] + CC_ROT - 'Z'))
				: (line_start[i] += CC_ROT);
	obf_inlines_ccrot(ft_strcasestr(line_start + i, vpref_search), vpref_search);
}

bool		obf_file_ccrot(t_file *file)
{
	cstring	vprefs[] = {VPREF_OWL, VPREF_OWLPLAY, VPREF_OWLECHO,
							VPREF_PLUSOWL, VPREF_MINUSOWL};
	string	temp;
	int		i = NEG;
	int		j;

	_MSG(_MSG_START_VARSCCR_);
	while (++i < file->lines && (j = NEG))
		while (++j < VPREF_QTY)
			if ((temp = ft_strcasestr(file->tab[i], vprefs[j])))
				obf_inlines_ccrot(temp, vprefs[j]);
	_MSGN(_MSG_OK_);
	return (true);
}
