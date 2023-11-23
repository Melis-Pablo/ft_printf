/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:22:08 by pmelis            #+#    #+#             */
/*   Updated: 2023/04/18 13:27:13 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>	//include va_start() va_arg(), va_arg, va_end 
# include <unistd.h>	//include write()

int				ft_putchr(char c);
int				ft_putstr(char *args);
int				ft_putnbr(int n);
int				ft_putunsigned(unsigned int u);
int				ft_puthex(unsigned long n, char c);
int				ft_printf_checker(char s, va_list *args, int *i);
int				ft_printf(const char *format, ...);

#endif
