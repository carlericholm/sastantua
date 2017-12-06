/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:30:50 by cholm             #+#    #+#             */
/*   Updated: 2017/12/06 20:40:03 by cholm            ###   ########.fr       */
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

void	ft_sastantua(int size)
{
	int i;
	int j;
	int s;
	int star;
	int x;
	int line;
	int cols;
	int temp;
	int colonne;


	i = 0;
	j = 0;
	s = 3 * size;
	star = 1;
	x = 0;
	temp = s;
	line = ft_get_lines(size);
	cols = ft_get_cols(size);
	colonne = (cols / 2) + 1;
   printf("colonne vertebrale -> %d\n", colonne);	
	while (i < line)
	{
		while (j < cols)
		{
			while (s > 0)
			{
				ft_putchar(' ');
				s--;
				j++;
			}
			ft_putchar('/');
			j++;
			while (x < star)
			{
				ft_putchar('*');
				x++;
				j++;
			}
			ft_putchar('\\');
			j++;
			while (j < cols)
			{
				ft_putchar(' ');
				j++;
			}
		}
		ft_putchar('\n');
		
		s = temp - (i + 1);
		x = 0;
		star += 2;
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
		ft_sastantua(nbr);
	}
	else
		ft_putchar('\n');
	return (0);
}
