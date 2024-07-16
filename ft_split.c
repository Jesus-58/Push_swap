/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:09:59 by jesumore          #+#    #+#             */
/*   Updated: 2024/04/15 20:09:59 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char *string, char c)
{
	int		words;
	bool	trigger;

	words = 0;
	while (*string)
	{
		trigger = false;
		while (*string && *string == c)
			string++;
		while (*string && *string != c)
		{
			if (!trigger)
			{
				words++;
				trigger = true;
			}
			string++;
		}
	}
	return (words);
}

static char	*ft_get_word(char *string, char c)
{
	static int	actual = 0;
	char		*word;
	int			length;
	int			i;

	length = 0;
	i = 0;
	while (string[actual] == c)
		actual++;
	while (string[actual + length] && (string[actual + length] != c))
		length++;
	word = malloc((size_t)length * sizeof(char) + 1);
	if (word == NULL)
		return (NULL);
	while (string[actual] && (string[actual] != c))
		word[i++] = string[actual++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *string, char c)
{
	char	**array;
	int		words_count;
	int		i;

	i = 0;
	words_count = ft_count_words(string, c);
	if (!words_count)
		exit(1);
	array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (array == NULL)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			array[i] = malloc(sizeof(char));
			if (array[i] == NULL)
				return (NULL);
			array[i++][0] = '\0';
			continue ;
		}
		array[i++] = ft_get_word(string, c);
	}
	array[i] = NULL;
	return (array);
}
