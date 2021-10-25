/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:39:39 by hpark             #+#    #+#             */
/*   Updated: 2020/06/25 13:39:40 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTIL_H
# define LIBFT_UTIL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
size_t	ft_wordcount(char const *s1, char const c);
size_t	ft_checklen(char const *s1, char const c);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_info(char **info, char const *s, char c);
char	*ft_strjoin_point(char const *s1, char const *s2);
void	free_info(char **info, char const *s, char c);
int		ft_rgb(int r, int g, int b);
void	ft_free(char *s_res);

#endif
