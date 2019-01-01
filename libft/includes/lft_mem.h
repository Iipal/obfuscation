/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_mem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:15:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 17:07:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MEM_H
# define LFT_MEM_H

# include "lft_str.h"

# define _PVOID	typedef	void*	pvoid

_PVOID;

void	ft_bzero(pvoid, size_t);
void	ft_memdel(pvoid*);

pvoid	ft_memset(pvoid, int, size_t);
pvoid	ft_memcpy(pvoid, const pvoid, size_t);
pvoid	ft_memccpy(pvoid, const pvoid, int, size_t);
pvoid	ft_memmove(pvoid, void const*, size_t);
pvoid	ft_memchr(const pvoid, int, size_t);
pvoid	ft_memalloc(size_t);

int		ft_memcmp(const pvoid, const pvoid, size_t);

#endif
