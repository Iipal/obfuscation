/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obf_file_fake.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 00:06:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 14:23:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/obfuscation.h"

/*
**	Junk func for correct parser work.
*/

void obf_file_fake(t_file *file) {if (file) {_MSG(_MSG_START_FAKEING_); _MSGN(_MSG_OK_);}}