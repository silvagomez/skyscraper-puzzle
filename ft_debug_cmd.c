/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orios-me <orios-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:57:10 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/02/26 17:43:46 by orios-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	ft_check_for_error(int argc, char *arg)
{
	int		error;
	int		index_arg;

	index_arg = 0;
	error = 0;
	if (argc != 2)
		error = 1;
	else
	{
		if (ft_strlen(arg) != 31)
			error = 2;
	}
	while ((error == 0) && (index_arg < 31) && (arg[index_arg] != '\0'))
	{
		if (index_arg % 2 == 0)
		{
			if ((arg[index_arg] < '1') || (arg[index_arg] > '4'))
				error = 3;
		}
		else
			if (arg[index_arg] != ' ')
				error = 4;
		index_arg++;
	}
	return (error);
}

int	ft_debug_cmd(int argc, char *arg, int input[16])
{
	int		index_input;
	int		index_arg;
	int		error;

	error = ft_check_for_error(argc, arg);
	if (error == 0)
	{
		index_input = 0;
		index_arg = 0;
		while (index_input < 16)
		{
			input[index_input] = (arg[index_arg] - 48);
			index_input++;
			index_arg += 2;
		}			
	}
	return (error);
}
