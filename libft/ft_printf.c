/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:58:58 by jole              #+#    #+#             */
/*   Updated: 2023/02/07 17:42:13 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, s);
	while (*s != 0)
	{
		while (*s == '%')
		{
			s++;
			if (*s == '%')
			{
				ret += ft_putchar((*s++));
				break ;
			}
			ret = print_argument(ap, s++, ret);
		}
		if (*s != '%' && *s != 0)
		{
			ft_putchar(*s++);
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}

int	print_argument(va_list ap, const char *s, int ret)
{
	char	*tmp;

	if (*s == 'c')
	{
		ret++;
		ft_putchar(va_arg(ap, int));
	}
	else if (*s == 's')
	{
		tmp = va_arg(ap, char *);
		if (!tmp)
		{
			ret += 6;
			write(1, "(null)", 6);
			return (ret = print_argument2(ap, s, ret));
		}
		ret += ft_strlen(tmp);
		ft_putstr(tmp);
	}
	return (ret = print_argument2(ap, s, ret));
}

int	print_argument2(va_list ap, const char *s, int ret)
{
	if (*s == 'p')
	{
		write(1, "0x", 2);
		ret += putnbr_base2((unsigned long long)va_arg(ap, char *), 16, 0) + 2;
	}
	else if (*s == 'd' || *s == 'i')
		ret += putnbr_base((int)va_arg(ap, int), 10, "0123456789abcdef");
	else if (*s == 'u')
		ret += putnbr_base2(va_arg(ap, unsigned int), 10, 0);
	else if (*s == 'x')
		ret += putnbr_base2(va_arg(ap, unsigned int), 16, 0);
	else if (*s == 'X')
		ret += putnbr_base2(va_arg(ap, unsigned int), 16, 1);
	return (ret);
}

int	putnbr_base(int n, int base, char *str)
{
	long	nb;
	int		ret;

	nb = n;
	ret = 1;
	if (nb < 0)
	{
		ret += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= base)
	{
		ret += putnbr_base(nb / base, base, str);
		ft_putchar(str[nb % base]);
	}
	if (nb < base)
		ft_putchar(str[nb % base]);
	return (ret);
}

int	putnbr_base2(unsigned long long nb, int base, int caps)
{
	unsigned long long	base2;
	const char			*s = "0123456789abcdef0123456789ABCDEF";
	int					ret;

	ret = 1;
	if (caps)
		s += 16;
	base2 = base;
	if (nb >= base2)
	{
		ret += putnbr_base2((nb / base), base, caps);
		ft_putchar(s[nb % base]);
	}
	if (nb < base2)
		ft_putchar(s[nb % base]);
	return (ret);
}
