/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_put.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/01 17:08:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_PUT_H
# define LFT_PUT_H

# include <unistd.h>

void	ft_putchar(char);
void	ft_putstr(char const*);
void	ft_putendl(char const*);
void	ft_putnbr(int);
void	ft_putchar_fd(char, int);
void	ft_putstr_fd(char const*, int);
void	ft_putendl_fd(char const*, int);
void	ft_putnbr_fd(int, int);

#endif
