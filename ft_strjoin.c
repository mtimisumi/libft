/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:33:28 by mmisumi           #+#    #+#             */
/*   Updated: 2025/01/02 15:41:57 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*newstring;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstring == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		newstring[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		newstring[i] = *s2;
		i++;
		s2++;
	}
	newstring[i] = '\0';
	return (newstring);
}
