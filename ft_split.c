/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:54:56 by martalop          #+#    #+#             */
/*   Updated: 2024/02/01 18:17:31 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	//funcion para contar palabras/strings de 's'
	
	int	word_count(char const *s, char c)
	{
		int i;
		int	count;
		int	words;

		i = 0;
		count = 0;
		words = 0;
		while (s[i] != '\0')
		{
			if (s[i] != c)
				count++;
			while (s[i] == c && count > 0) // pongo (count > 0) y no (count >= 0) por si 'c' estuviera en el inicio de 's'
			{
				count = 0; // reinicio el valor por si se repitiera 'c' dos veces, que cuente a partir de la ultima vez que lo encuentra
				words++;
			}
			i++;
		}
		if (count > 0) // si 's' no acaba con el caracter 'c', lo termina y entiende como palabra acabada
			words++;
		return (words);
	}
	//crear array de strings con malloc
	
	/*char	**array;

	*array = malloc((words + 1) * (sizeof(char *)));*/
	
	//funcion para contar el size de cada palabra y crear strings de cada tamano con malloc
	
	char	**ft_string_size(char **array, char const *s, char c)
	{
		int	i;
		int	x;
		int	ctr;

		i = 0;
		x = 0;
		ctr = 0;
		while (s[i] != '\0')
		{
			if (s[i] != c)
				ctr++;
			while ((s[i] == c && ctr > 0) || (s[i] != c && s[i + 1] == '\0'))
			{
				array[x] = malloc(sizeof(char) * (ctr + 1));
				if (!array[x])
					return (NULL);
				ctr = 0;
				x++;
			}
			i++;
		}
		return (array);
	}
	//copiar el contenido 's' en las nuevas strings
	
char	**ft_copy(char **array, char const *s, char c)
{
	int i;
	int	x;
	size_t	j;
	
	i = 0;
	x = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			array[x][j++] = s[i];
		if (s[i] != c && s[i + 1] == '\0')
			array[x][j] = '\0';
		else if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			array[x][j] = '\0';
			x++;
			j = 0;
		}
		i++;
	}	
	return (array);
}

	//liberar espacio sobrante con free
	
static char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return (NULL);
}


int	main(void)
{
	char const	*s;
	char	c;
	int	words;
	int i;
	char	**array;

	s = " hola como  estas";
	c = ' ';
	i = 0;
	words = 3;
	array = malloc((words + 1) * (sizeof(char *)));
	if (!array)
		return (0);
	ft_string_size(array, s, c);
	while (array)
	{
		printf("%s\n", array[i]);
		i++;
	}
	//printf("%s\n", ft_copy(array, s, c));
	return (0);
}
