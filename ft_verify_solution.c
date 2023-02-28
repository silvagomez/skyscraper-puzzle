/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orios-me <orios-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:57:02 by orios-me          #+#    #+#             */
/*   Updated: 2023/02/26 15:09:30 by orios-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_verify_top(int comb[4], const int rows[24][4], int input[16], int j)
{
	int	row;
	int	height;
	int	visible;
	int	i;

	i = -1;
	while (++i < 4)
	{
		row = 0;
		visible = 1;
		height = rows[comb[0]][++j];
		while (++row <= 3)
		{
			if (rows[comb[row]][j] > height)
			{
				height = rows[comb[row]][j];
				visible++;
			}
		}
		if (visible != input[i])
			return (0);
	}
	return (1);
}

int	ft_verify_down(int comb[4], const int rows[24][4], int input[16], int col)
{
	int	row;
	int	height;
	int	visible;
	int	i;

	i = 3;
	while (++i < 8)
	{
		row = 4;
		visible = 1;
		height = rows[comb[3]][++col];
		while (--row >= 0)
		{
			if (rows[comb[row]][col] > height)
			{
				height = rows[comb[row]][col];
				visible++;
			}
		}
		if (visible != input[i])
			return (0);
	}
	return (1);
}

int	ft_verify_left(int comb[4], const int rows[24][4], int input[16], int row)
{
	int	column;
	int	height;
	int	visible;
	int	i;

	i = 7;
	while (++i < 12)
	{
		column = 0;
		visible = 1;
		height = rows[comb[++row]][0];
		while (++column <= 3)
		{
			if (rows[comb[row]][column] > height)
			{
				height = rows[comb[row]][column];
				visible++;
			}
		}
		if (visible != input[i])
			return (0);
	}
	return (1);
}

int	ft_verify_right(int comb[4], const int rows[24][4], int input[16], int row)
{
	int	column;
	int	height;
	int	visible;
	int	i;

	i = 11;
	while (++i < 16)
	{
		column = 4;
		visible = 1;
		height = rows[comb[++row]][3];
		while (--column >= 0)
		{
			if (rows[comb[row]][column] > height)
			{
				height = rows[comb[row]][column];
				visible++;
			}
		}
		if (visible != input[i])
			return (0);
	}
	return (1);
}

int	ft_verify_solution(int comb[4], const int rows[24][4], int parameters[16])
{
	if ((ft_verify_top(comb, rows, parameters, -1)) && \
	(ft_verify_down(comb, rows, parameters, -1)) && \
	(ft_verify_left(comb, rows, parameters, -1)) && \
	(ft_verify_right(comb, rows, parameters, -1)))
	{
		return (1);
	}
	return (0);
}
