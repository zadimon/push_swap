/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:01:52 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/01 18:45:35 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				flag;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				next;
	int				flag;
	int				mid;
	int				max;
	int				newmid;
	int				count;
}					t_data;

void	ft_exit(void);
t_stack	*ft_pushswaponearg(char *s);
t_stack	*ft_pushswap(t_stack *stack);
int		ft_isspace(int c);
int		ft_isstr(char *s);
int		ft_atol(char *s);
t_stack	*ft_stacknew(int num);
t_stack	*ft_createlist(int argc, char **argv);
t_stack	*ft_fromonearg(int len, char **str);
void	ft_stackclear(t_stack *stack);
t_stack	*ft_parsearg(int argc, char **argv);
void	ft_createindex(t_stack **stack, int *sorted);
int		ft_stacksize(t_stack *stack);
int		ft_stackfind(t_stack *stack, int index);
int		ft_findmax(t_stack *stack);
void	ft_swap(t_stack *first, t_stack *second, t_stack **stack, char c);
void	ft_rotate(t_stack **stack, char c);
void	ft_revrot(t_stack **stack, char c);
t_stack	*ft_push2(t_stack **a, t_stack **b);
void	ft_push(t_stack **a, t_stack **b, char c);
t_stack	*ft_revorrot(t_stack *stack, int index, char c);
t_stack	*ft_sort3(t_stack *stack, char c);
t_stack	*ft_sort5(t_stack *stack);
t_stack	*ft_sort(t_stack *stack);
t_data	*ft_datanew(void);
void	ft_sortb(t_stack **a, t_stack **b, t_data *data);
int		ft_mfindmax(t_stack *stack);
void	ft_fullb(t_stack **a, t_stack **b, t_data *data);
void	ft_fullbandsort(t_stack **a, t_stack **b, t_data *data);
void	ft_canrotateboth(t_stack **a, t_stack **b, t_data *data);
void	ft_secondfullb(t_stack **a, t_stack **b, t_data *data);
void	ft_checkfirstina(t_stack **a, t_data *data);
void	ft_checksecondina(t_stack **a, t_data *data);
void	ft_checkfirstinbfora(t_stack **a, t_stack **b, t_data *data);
void	ft_checksecondinbfora(t_stack **a, t_stack **b, t_data *data);
void	ft_checkfirstinb(t_stack **a, t_stack **b, t_data *data);
void	ft_checklastinb(t_stack **a, t_stack **b, t_data *data);
void	ft_emptyb(t_stack **a, t_stack **b, t_data *data);
void	ft_reversea(t_stack **a, t_stack **b, t_data *data);
void	ft_sortpt2(t_stack **a, t_stack **b, t_data *data);

/*---bonus---*/

char	*get_next_line(int fd);
char	*ft_getline(char **s, int rs);
char	*ft_gstrjoin(char *s1, char *s2);
char	*ft_gstrdup(char *src);
char	*ft_gsubstr(char const *s, unsigned int start, size_t len);
size_t	ft_gstrlen(const char *s);
char	*ft_gstrchr(const char *s, int c);
void	ft_parsecom(char *s, t_stack **a, t_stack **b);
t_stack	*ft_parseargforchecker(int argc, char **argv);
t_stack	*ft_oneargforchecker(char *s);
t_stack	*ft_fromoneargforchecker(int len, char **str);
void	ft_parserotate(char *s, t_stack **a, t_stack **b);
void	ft_parsereverserotate(t_stack **a, t_stack **b);
void	ft_canswapb(t_stack **b);
int		ft_checksorted(t_stack *a);
void	ft_printres(t_stack *b, int sorted);

#endif