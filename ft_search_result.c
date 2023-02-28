/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orios-me <orios-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:48:43 by jaarteag          #+#    #+#             */
/*   Updated: 2023/02/26 18:13:08 by orios-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_verify_solution(int comb[4], const int rows[24][4], int parameters[16]);

int	ft_valid_comb(int row_num, int comb[4], const int rows[24][4])
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	while ((valid) && (i < row_num))
	{
		if ((rows[comb[i]][0] == rows[comb[row_num]][0]) || \
			(rows[comb[i]][1] == rows[comb[row_num]][1]) || \
			(rows[comb[i]][2] == rows[comb[row_num]][2]) || \
			(rows[comb[i]][3] == rows[comb[row_num]][3]))
				valid = 0;
		i++;
	}
	return (valid);
}

int	ft_fourth_row(int comb[4], const int rows[24][4], int input[16])
{
	int	i;
	int	found;

	found = 0;
	i = 0;
	while (!found && i < 23)
	{
		comb[3] = i;
		if (ft_valid_comb(3, comb, rows))
			found = ft_verify_solution(comb, rows, input);
		i++;
	}
	return (found);
}

int	ft_third_row(int comb[4], const int rows[24][4], int input[16])
{
	int	i;
	int	found;

	found = 0;
	i = 0;
	while ((!found) && (i < 23))
	{
		comb[2] = i;
		if (ft_valid_comb(2, comb, rows))
			found = ft_fourth_row(comb, rows, input);
		i++;
	}
	return (found);
}

//tests with all possible combinations for a valid solution
//if found returns found = 1 and the solution in comb[]
int	ft_search_result(int comb[4], const int rows[24][4], int input[16])
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while ((!found) && (i < 23))
	{
		j = 0;
		comb[0] = i;
		while ((!found) && (j < 23))
		{
			comb[1] = j;
			if (ft_valid_comb(1, comb, rows))
				found = ft_third_row(comb, rows, input);
			j++;
		}
		i++;
	}
	return (found);
}
