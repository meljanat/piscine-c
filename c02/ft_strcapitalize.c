void	to_lowercase(char *str);
int		is_alpha(char c);
int		is_numeric(char c);
int		is_uppercase(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	tocap;

	i = 0;
	tocap = 1;
	to_lowercase(str);
	while (str[i] != '\0')
	{
		if (is_alpha(str[i]) || is_numeric(str[i]))
		{
			if (tocap && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			tocap = 0;
		}
		else
		{
			tocap = 1;
		}
		i++;
	}
	return (str);
}

void	to_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}