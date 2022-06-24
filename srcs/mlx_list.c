/**
 * @file mlx_list.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-24
 *
 */

#include "mlx_internal.h"

t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lst_add_back(t_list **alst, t_list *new)
{
	t_list	*llast;

	if (!*alst)
		*alst = new;
	else
	{
		llast = lst_last(*alst);
		llast->next = new;
	}
}

t_list	*lst_new(char *s)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->next = 0;
		list->s = s;
	}
	return (list);
}

void	lst_del_one(t_list *lst, void (*del)(void*))
{
	if (del)
		(*del)(lst->s);
	free(lst);
}

void	lst_clear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*p;

	if (!lst)
		return ;
	l = *lst;
	while (l)
	{
		p = l;
		l = l->next;
		lst_del_one(p, del);
	}
	*lst = 0;
}

char	**cpy_list_to_char(t_list *list, int list_length)
{
	char	**data;
	int		i;

	data = malloc((list_length + 1) * sizeof(char *));

	if (!data)
		return (NULL);
	i = -1;
	while (list)
	{
		data[++i] = list->s;
		list = list->next;
	}
	data[++i] = NULL;
	return (data);
}
