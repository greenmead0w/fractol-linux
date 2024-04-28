#include <limits.h>
#include "libft.h"

// The (unsigned long) cast is neccessary to tell the compiler to 
//treat the pointer as a number
static	int	printf_router(char format, va_list *ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = putchar_f(va_arg(*ap, int));
	else if (format == 's')
		count = putstr_f(va_arg(*ap, char *));
	else if (format == 'p')
	{
		count = putstr_f("0x");
		count = count + putaddress_f((unsigned long)va_arg(*ap, void *));
	}
	else if (format == 'd' || format == 'i')
		count = putnbr_f((long)va_arg(*ap, int), 10, false);
	else if (format == 'u')
		count = putnbr_f((long)va_arg(*ap, unsigned int), 10, false);
	else if (format == 'x')
		count = putnbr_f((long)va_arg(*ap, unsigned int), 16, false);
	else if (format == 'X')
		count = putnbr_f((long)va_arg(*ap, unsigned int), 16, true);
	else
		count = putchar_f(format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count = count + printf_router(*(++format), &ap);
			if (count == -1)
				return (-1);
		}
		else
		{
			count = count + write(1, format, 1);
			if (count == -1)
				return (-1);
		}
		format++;
	}
	va_end(ap);
	return (count);
}