/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:25:32 by pmelis            #+#    #+#             */
/*   Updated: 2023/04/18 13:20:42 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
#ft_putchr():	Writes a character to the standard output.

#Parameters:	char c

#Return:		int -- amount of chr printed

#How it works:	returns the return value of the write function after c is
				passed trough.
*/

int	ft_putchr(char c)
{
	return (write(1, &c, 1));
}

/*
#ft_putstr():	Writes a string to the standard output.

#Parameters:	char *args

#Return:		int i -- amount of chr printed

#How it works:	if args is null, writes (null) and returns 6 for the printed chr
				if not a while loop prints each chr and increases the counter.
				finally returns the counter.
*/

int	ft_putstr(char *args)
{
	int	i;

	i = 0;
	if (!args)
		return (write(1, "(null)", 6));
	while (args[i])
		ft_putchr(args[i++]);
	return (i);
}

/*
#ft_putnbr():	Writes a number to the standard output.

#Parameters:	int n

#Return:		int i -- amount of chr printed

#How it works:	if n == min_int writes it and returns amount of chr. if n < 0
				it writes (-) and calls itself with the +n. else if n > 0,
				it will check if n > 10 and call itself with (n / 10), and does
				this until it has 1 digit and writes it as a chr. finally
				returns i.
*/

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		i += ft_putchr('-');
		i += ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			i += ft_putnbr(n / 10);
		i += ft_putchr(n % 10 + '0');
	}
	return (i);
}

/*
#ft_putunsigned():	Writes an unsigned int to the standard output.

#Parameters:		unsigned int u

#Return:			int i -- amount of chr printed

#How it works:		if u > 10, it will call itself with (u / 10) until u has
					1 digit and it will print it as a chr. finally returns i.
*/

int	ft_putunsigned(unsigned int u)
{
	int	i;

	i = 0;
	if (u >= 10)
		i += ft_putunsigned(u / 10);
	i += ft_putchr(u % 10 + '0');
	return (i);
}

/*
#ft_puthex():	it can print a number or a pointer in hexadecimal format.

#Parameters:	unsigned long n
				char c

#Return:		int i -- amount of chr printed

#How it works:	first it checks the format, if it is uppercase it will set s
				as uppercase, if not it will set it as lowercase base string.
				if it is a pointer it writes "0x" first and reset c for next
				function call. if n < 16, it will print the corresponding spot
				on s, else it will call itself with (n / 16) until n < 16.
				finally returning i.
*/

int	ft_puthex(unsigned long n, char c)
{
	int		i;
	char	*s;

	i = 0;
	if (c == 'X')
		s = "0123456789ABCDEF";
	else
		s = "0123456789abcdef";
	if (c == 'p')
	{
		i += ft_putstr("0x");
		c = 0;
	}
	if (n < 16)
		i += ft_putchr(s[n]);
	else
	{
		i += ft_puthex(n / 16, c);
		i += ft_puthex(n % 16, c);
	}
	return (i);
}
