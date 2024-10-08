/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:47:15 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/07 23:47:26 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ans;
	int		i;

	i = ft_strlen(s);
	ans = (char *) malloc ((i + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ans[i] = s[i];
		i += 1;
	}
	ans[i] = '\0';
	return (ans);
}
