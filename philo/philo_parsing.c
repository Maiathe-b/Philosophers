#include "philosophers.h"

int	check_number(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (!ft_isdigit(s[i++]))
			return (0);
	}
	return (1);
}

int	check_valid(int	ac, char **value)
{
	int	i;

	i = 0;
	if(ac < 4 || ac > 5)
		return (0);
	while (value && value[i])
	{
		if(!check_number(value[i++]))
			return (0);
	}
}

int	parsing(int	ac, char **value)
{
	int	
}