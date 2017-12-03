/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:30:50 by cholm             #+#    #+#             */
/*   Updated: 2017/12/03 21:21:36 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

//Fonction qui permet d'afficher un caractere

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//Fonction pour transformer le char passe en parametre en un int 

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

//Fonction pour trouver le milieu de la pyramide (la colonne vertebrale)

int 	ft_get_col(int size)
{
	int i;
	int j;
	int col;
	int x;

	i = 1;
	j = 1;
	x = 1;
	while (j < size)
	{
		x += 2;
		j++;
	}
	col = ((x * 7) / 2) + 1;
	printf("col -> %d\n", col);
	return (col);
}

//Fonction pour calculer la hauteur de la pyramide

int 	ft_get_lines(int size)
{
	int i;
	int line;

	i = 1;
	if (size == 1)
		line = 3;
	if (size > 1)
	{
		line = 3;
		while (i < size)
		{
			line += 3 + i;
			i++;
		}
	}
	return (line);
}


//Fonction pour calculer la largeur de la pyramide

int 	ft_get_cols(int size)
{
	int i;
	int cols;
	int j;

	i = 1;
	j = 1;
	cols = 7;
	while (i < size)
	{
		j += 2;
		i++;
	}
	cols *= j;
	return (cols);
}

//Fonction qui affiche la pyramide

void	ft_sastantua(int size, int col)
{
	int i;
	int j;
	int l;
	int line;
	int cols;
	int colonne;


	i = 0;
	j = 0;
	l = 1;
	colonne = col;
	line = ft_get_lines(size);
	cols = ft_get_cols(size);
	while (i < line)
	{
		while (j < cols)
		{
			ft_putchar('@');
			if (j == 0)
			{
				while (j < colonne - 2)
				{
					ft_putchar('+');
					j++;
				}
			}
			if (j == colonne - 2)
			{
				ft_putchar('#');
				j++;
				while (j < cols - 2)
				{
					ft_putchar('+');
					j++;
				}

			}
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}

}

int		main(int argc, char **argv)
{
	int nbr;
	int number;
	int col;


	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		col = ft_get_col(nbr);
		ft_sastantua(nbr, col);
	}
	else
		ft_putchar('\n');
	return (0);
}
