#include "libft.h"

//int as parameter to support extended ASCII characters:
	// char =-128 to 127, overflow is possible
int	putchar_f(int c)
{
	int	count;

	count = write(1, &c, 1);
	return (count);
}

int	putstr_f(char *ptr)
{
	unsigned int	i;
	int				count;

	count = 0;
	i = 0;
	if (ptr == NULL)
		ptr = "(null)";
	while (ptr[i] != '\0')
	{
		if (write(1, &ptr[i], sizeof(char)) == -1)
			return (-1);
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

int	putaddress_f(unsigned long n)
{
	unsigned long	base;
	char			*hex;
	int				count;

	hex = "0123456789abcdef";
	base = 16;
	count = 0;
	if (n >= base)
	{
		count = putaddress_f(n / base);
		count = count + putchar_f(hex[n % base]);
		if (count == -1)
			return (-1);
	}
	else
	{
		if (putchar_f(hex[n]) == -1)
			return (-1);
		else
			count++;
	}
	return (count);
}

int	putnbr_f(long n, unsigned short base, bool isuppercase)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	if (isuppercase == true)
		hex = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		count = putchar_f('-');
		return (putnbr_f(-n, base, isuppercase) + count);
	}
	if (n < base)
		return (putchar_f(hex[n]));
	else
	{
		count = putnbr_f(n / base, base, isuppercase);
		count = count + putnbr_f(n % base, base, isuppercase);
	}
	return (count);
}