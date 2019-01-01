/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:19:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 17:06:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_LST_H
# define LFT_LST_H

# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *, size_t);
void			ft_lstdelone(t_list**, void (*del)(void*, size_t));
void			ft_lstdel(t_list**, void (*del)(void*, size_t));
void			ft_lstadd(t_list**, t_list*);
void			ft_lstiter(t_list*, void (*f)(t_list*));
t_list			*ft_lstmap(t_list*, t_list *(*f)(t_list*));

#endif
