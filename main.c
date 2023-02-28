/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orios-me <orios-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:10:37 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/02/26 17:40:14 by orios-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_search_result(int comb[4], const int rows[24][4], int input[16]);
void	ft_print_comb(int comb[4], const int rows[24][4]);
int		ft_debug_cmd(int argc, char *arg, int input[16]);
void	ft_print_error(int error_code);

int	main(int argc, char **argv)
{
	int			error;
	int			input[16];
	int			comb[4];
	const int	rows[24][4] = {{1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, \
		{1, 3, 4, 2}, {1, 4, 2, 3}, {1, 4, 3, 2}, {2, 1, 3, 4}, \
		{2, 1, 4, 3}, {2, 3, 1, 4}, {2, 3, 4, 1}, {2, 4, 1, 3}, \
		{2, 4, 3, 1}, {3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1, 4}, \
		{3, 2, 4, 1}, {3, 4, 1, 2}, {3, 4, 2, 1}, {4, 1, 2, 3}, \
		{4, 1, 3, 2}, {4, 2, 1, 3}, {4, 2, 3, 1}, {4, 3, 1, 2}, \
		{4, 3, 2, 1}};

	error = ft_debug_cmd(argc, argv[1], input);
	if (error != 0)
		write(2, "Error\n", 6);
	else
	{
		if (ft_search_result(comb, rows, input))
			ft_print_comb(comb, rows);
		else
			write(2, "Error\n", 6);
	}
}
