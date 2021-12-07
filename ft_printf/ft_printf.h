/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:13 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/07 21:29:09 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	check_type(char *string, va_list args);
void	next_arg(char c, int *char_print, va_list args);
int		ft_putnbr_fd(int n, int fd, int count);
int		ft_putunsnbr_fd(unsigned int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_iterative_power(int nb, int power);
int		oct_to_dec(int n);
#endif