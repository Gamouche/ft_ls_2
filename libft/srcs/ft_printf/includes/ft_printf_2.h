/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:03:54 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/15 15:30:36 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_2_H
# define FT_PRINTF_2_H

# include <stdarg.h>
# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <ft_printf_struct.h>
# include <ft_printf.h>

# define SUCCESS 0
# define ERROR -1
# define END 1

int			ft_conv_s(char **ret, t_arg *arg);
int			ft_conv_p(char **ret, t_arg *arg);
int			ft_conv_d(char **ret, t_arg *arg);
int			ft_conv_o(char **ret, t_arg *arg);
int			ft_conv_u(char **ret, t_arg *arg);
int			ft_conv_x(char **ret, t_arg *arg);
int			ft_conv_c(char **ret, t_arg *arg);
int			ft_conv_k(char **ret, t_arg *arg);
int			ft_conv_n(char **ret, t_arg *arg);
int			ft_conv_b(char **ret, t_arg *arg);
int			ft_conv_w(char **ret, t_arg *arg, int size, int size_exposant);
int			ft_conv_f(char **ret, t_arg *arg);
int			ft_conv_e(char **ret, t_arg *arg);
int			ft_conv_g(char **ret, t_arg *arg);
int			ft_conv_r(char **ret, t_arg *arg, va_list ap);
int			ft_conv_modulo(char **ret, t_arg *arg);
int			ft_conv_invalid(char **ret, t_arg *arg);
int			ft_calcul_zero_ap(t_arg *arg);
int			calcul_exposant(t_arg *arg);
void		ft_flag_zero_neg_e(char *s, char *n, t_arg *arg);
void		ft_flag_space_plus_e(char *s, char *n, t_arg *arg);
int			ft_flags_e(char **nr, char *nn, t_arg *arg);
char		*ft_fill_rest_e(char *cpy, int exposant, int precision, t_arg *arg);
void		ft_deplace(char **str, int minus, int point, int new_len);
int			ft_precision_e(char **new_nb, t_arg *arg);
int			ft_put_width(char **tab, t_arg *arg, int *i, int nbb);
int			ft_print_twob(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_threeb(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_fourb(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_oneb(char **ret, unsigned int wch, t_arg *arg);
int			ft_regle_zero(char **ret, t_arg *arg);
void		ft_fill_str_ud(char **str, long long nb, int *len, t_arg *arg);
int			ft_init_conv_bigs(char **ret, t_arg *arg);
void		ft_precision_f(char *str, int p);
char		*right_justify_f(char *str, int width);
char		*left_justify_f(char *str, int width);
int			ft_flags_f(char **str, int sign, t_arg *arg);
char		*ft_arrondis_f(char *s, int p, int loop);
char		ft_getheight(t_arg *arg);
int			ft_length_cs(t_arg *argi);
int			ft_add_conv_s(char **ret, t_arg *arg);
int			ft_add_conv_bigc(char **ret, t_arg *arg);
int			ft_checknull_bigs(char **ret, t_arg *arg, wchar_t **x);
int			ft_add_conv_bigs(char **ret, t_arg *arg, wchar_t *x, int cmpt);
int			ft_strlenw_bigs(wchar_t wch);
char		**ft_strw_cpy(char **str, int start, char *tmp);
void		ft_check_nbcar(t_arg *arg, int *nbcar, wchar_t *x, int *strl);
int			ft_init_conv_bigs(char **ret, t_arg *arg);
int			ft_strlenw(wchar_t wch);
char		*ft_replace_stars(char *cpy, long long nb_len, int total, int *i);
int			ft_forest(char **ret, t_arg *arg, va_list ap);
int			ft_checkconv(char **ret, t_arg *arg, va_list ap);
void		ft_initarg(t_arg *arg);
int			ft_check(char **ret, char *str, va_list ap, t_arg *arg);
int			ft_parse(char **retour, const char *format, va_list ap, t_arg *arg);
int			ft_cleanstars(char **str, va_list ap);
char		*ft_strfreejoin(char *s1, const char *s2, int size_s2, t_arg *arg);
int			ft_color(char **str, t_arg *arg);
void		ft_init_color(t_color *color);

long long	ft_2arg(int arg1, int arg2);
int			ft_get2arg(long long arg, int n);
unsigned	ft_abs(int nb);
char		*ft_int_to_base(long long n, char *base);
char		*ft_int_to_nbase(long n, char *base, int size);
long long	ft_base_to_int(char *n, char *base);

#endif
