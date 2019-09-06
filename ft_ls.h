/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:07:25 by dwisoky           #+#    #+#             */
/*   Updated: 2019/03/01 16:24:06 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include <time.h>
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include "libft/libft.h"

typedef struct		s_file
{
	char			*name;
	int				size_name;
	struct s_file	*next;
	struct s_file	*next_dir;
	struct stat		st;
	char			*path;
	char			*bit;
	char			*link;
}					t_file;

typedef struct		s_name
{
	char			*name;
	struct s_name	*next;
}					t_name;

int					create_dir(t_file **dir, t_file **file);
void				print_link(t_file *file);
void				free_file(t_file *file, t_file *dir);
char				*ft_buf(char *buf, int i, mode_t mode, char *name);
int					output(t_file **file, int words);
int					term();
char				*s_b(char *str, size_t sz);
char				*s_f(char *str, size_t sz, int f);
void				print_l(char *str, char *str1, char *str2, int i);
void				print_total(int tt, int flag);
void				lflag(t_file *file, int tt, int flag);
void				sort_merge(t_file **file, int flag);
void				cr_file(char *name, char *path, t_file **file, int flag);
int					create_file(char **av, int flag, t_file **file,
		t_file **dir);
int					parsing_flag(int ac, char **av, int *flag);
int					ls_error(char c, char *str);
char				*ft_strldup(char *str, t_file **file, int flag);
void				print(t_file **file, t_file **dir, int flag, int words);
int					print_one_file(t_file *file);

#endif
