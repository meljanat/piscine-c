#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			char *hex = "0123456789abcdef";
			unsigned char c = (unsigned char)str[i];
			write(1, "\\", 1);
			write(1, &hex[c / 16], 1);
			write(1, &hex[c % 16], 1);
		}
		i++;
	}
}