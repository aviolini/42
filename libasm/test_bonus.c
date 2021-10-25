/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:14:01 by arrigo            #+#    #+#             */
/*   Updated: 2021/04/29 03:52:30 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"


int	ft_list_size_list(t_list *begin)
{
	int i;

	i = 0;
	if (begin == NULL)
		return (0);
	while (begin != NULL)
	{
		i++;
		begin = (begin)->next;
	}
	return (i);
}

void	ft_list_print_list(t_list **begin)
{
	/*	PASSANDO IL PARAMETRO CON SINGOLO PUNTATORE IL VLORE NELLE LISTE NON CAMBIA,
		PASSANDOGLIELO CON DOPPIO IL PRIMO PRINT ANDAVA BENE MA IL SECONDO AVEVA GLI ELEMENTI
		SCAMBIATI IN QUANTO IL PUNTATORE PER STAMPARE AVANZAVA E AGGIORNAVA LA SUA POSIZIONE,
		QUINDI ESSENDO SOTTO UN PUNTATORE DoPPIO TUTTO RIMANE SALVATO.
		QUINDI QUANDO SI CAMBIA UN PARAMETRO OK PUNTATORE DOPPIO MA QUANDO SI STAMPA E CONSIGLIABILE 
		PUNTATORE SINGOLO IN QUANTO LEGGE E BASTA, OPPURE IL TEMPORANEO.
	*/
	int				c;
	int				size_list;
	int				i;
	int				len;
	unsigned char	*one_byte;
	t_list			*temp;
///////////////////////////////////////////////////PER UNA GIUSTA STAMPA OGNI LISTA DEVE TERMINARE CON IL PTR->NEXT
	temp = *begin;
	c = -1;
	if (temp)
	{
		len = sizeof(*temp);
		size_list = ft_list_size_list(temp);
		printf("\n===>SIZE LIST: %d nodes",size_list);
		printf("\n===>SIZE NODES: %d bytes each node",len);
		printf("\n===>START LIST\n_____________|\n|\n");
		while (temp)
			{
				c++;
				i = -1;
				one_byte = (unsigned char *)(temp);
				//printf("|\n|   index this_element: %d\n", c);
				printf("|-->address this_element(%d) = %p",c , temp);
			//	printf("|-->addr_next_element(%d) = %p\n", c + 1,((temp)->next));
				while (++i < len)
				{	
					if (i + 8 == len)
						printf("\n____addr_next_element(%d) = ", c+1);// + 1,((temp)->next));
					else if (i%8 == 0)
					{
						printf("\n    data: ");
						//printf("");
					}
					else 
						printf("-");
										printf("%x",one_byte[i]);
				}
				printf("\n|\n");
				
				
				//printf("    this_element(%d).data = %d\n", c, *(int *)((temp)->data));
			//printf("    address this_element(%d).data = %p\n", c, (int *)((temp)->data));

				temp = (temp)->next;
				//printf("|\n");
			}
		printf("|___END LIST<===\n\n");
	}
	else 
		printf("\nLIST EMPTY\n");
	return;
}

void	ft_list_print_list_elegant(t_list *begin)
{
	int	c;
	int	size_list;

	c = 0;
	if (!begin)
	{
		printf("\nLIST EMPTY\n");
		return;
	}
	size_list = ft_list_size_list(begin);
	printf("\n===>SIZE LIST: %d elements",size_list);
	printf("\n===>START LIST\n_____________|\n|\n");
	while (begin)
		{
			c++;
			printf("|   index this_element: %d\n", c);
			printf("|-->address this_element(%d) = %p\n",c , begin);
			printf("    this_element(%d).data = %s\n", c, (char *)((begin)->data));
			printf("    address this_element(%d).data = %p\n", c, (char *)((begin)->data));
			printf("____addr_next_element(%d) = %p\n", c + 1,((begin)->next));
			printf("|\n");
			begin = (begin)->next;
		}
	printf("|___END LIST<===\n\n");		
	return ;
}

t_list	*ft_list_add_node(void *data)
{
	t_list *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_list_set_last_node(t_list **begin)
{
	t_list *temp;

	temp = *begin;
	if (!temp)
		return (NULL);
	if (!(temp->next))
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_list	*ft_list_add_node_after_this_node(t_list *this_node, void *data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	
	new_node->next = this_node->next;
	this_node->next = new_node;
	new_node->data = data;
	return (new_node);
}

void	ft_list_add_node_back_list(t_list **begin,void *data)
{
	ft_list_add_node_after_this_node(ft_list_set_last_node(begin), data);
}

void	ft_list_add_node_front_list(t_list **begin,void *data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->next = *begin;
	new->data = data;
	*begin = new;
}

void	ft_list_del_list(t_list **begin)
{
	t_list *temp;
	t_list *temp2;

	temp = *begin;
	temp2 = *begin;
	while (temp2)
	{
		temp2 = temp2->next;
		free (temp);
		temp = temp2;
	}
	*begin = NULL;
}

void	ft_list_zero_node(t_list *node)
{
	int				len;
	int				i;
	unsigned char	*one_byte;

	i = -1;
	len = sizeof(*node);
	one_byte = (unsigned char *)node;
	while ( ++i < len - 8)
		one_byte[i] = 0x0;
}

int	ft_list_mov_node(t_list *dest, t_list *src)
{	
	int				len;
	int				i;
	unsigned char	*one_byte_dest;
	unsigned char	*one_byte_src;

	if (!dest || !src)
		return (0);
	one_byte_dest = (unsigned char *)dest;
	one_byte_src = (unsigned char *)src;
	i = -1;
	len = sizeof(*src);
	while (++i < len)
	one_byte_dest[i] = one_byte_src[i];
	free(src);
	return (1);
}

void	ft_list_del_node_by_data(t_list **begin,void *data)
{
	t_list	*temp;

	if (!begin || *begin || !data)
		return;
	temp = *begin;
	if ((*begin)->next == NULL)		/*PROTEZIONE SE RIMANE UN SOLO ELEMENTO*/
	{								/*NELLA LISTA LO CANCELLA DIRETTAMENTE*/				
		free(*begin);
		*begin = NULL;
		return ;
	}
	while (temp)
	{
		if (temp->next->next == NULL)
		{
			free(temp->next);
			temp->next = NULL;
			return;
		}	
		if ((temp)->data == data)
		{	
			ft_list_mov_node(temp,(temp)->next);
			return;	
		}
		temp = (temp)->next;
	}
	return ;
}

void 	ft_list_zero_list(t_list **begin)
{
	t_list *temp;
	
	temp = *begin;
	while (temp)
		{
			ft_list_zero_node(temp);
			temp = temp->next;
		}
}

t_list	*ft_list_find_node_by_data(t_list *begin, void *data)
{
	if (!begin || !data)
		return (NULL);
	while (begin)
	{
		if (begin->data != data)
			begin =  begin->next;
		else
			return (begin);
	}
	return (NULL);
}

t_list *ft_list_set_next_node(t_list *node)
{
	node = node->next;
	return (node);
}

int		ft_strcomp(char *s1, char *s2)
{
	unsigned int	x;
	int				res;

	x = 0;
	while (s1[x] || s2[x])
	{
		if (s1[x] != s2[x])
		{
			res = (s1[x] - s2[x]);
			return (res);
		}
		else
			x++;
	}
	return (0);
}

void	ft_list_swap(t_list **begin, t_list *node1, t_list *node2)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*temp3;	

	//SE DEVE FARE UNO SWAP PRIMO-SECONDO ELEMENTO VA IN SEG, SE IL PRIMO GIA 
	//E' ORDINATO IN QUANTO E' IL PIU PICCOLO TUTTO OK

	if (!node1 || !node2)
		return;
	temp = *begin;
	temp2 = *begin;
	printf(" ciao\n");
	//		printf(" r: %d\n",r);

//	if (temp->next == node1)
//		{
//			temp = begin;
//			temp2 = *begin;
//		}
//	else 
//	{
		while (temp->next != node1)
			temp = temp->next;
		while (temp2->next != node2)
			temp2 = temp2->next;
//	}	
	//	printf("----swap:----- \n");
	//	printf("temp data: %s \n",(char *)temp->data );
	//	printf("temp2 data: %s \n",(char *)temp2->data );
	//	printf("---------------\n");
	temp->next = node2;
	temp2->next = node1;
	temp3 = node1->next;
	node1->next = node2->next;
	node2->next = temp3;
	return ;
}

void	ft_list_sort_ascending(t_list **begin)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;
	int		r;
	int		size;
	
	temp = *begin;
	temp2 = temp->next;
	size = ft_list_size_list(*begin);
	i = -1;

	while (++i < size-1)
	{
		if (!temp || !temp2)
			return ;
		r = ft_strcomp((temp)->data, temp2->data);
		//r = (*(int *)temp->data - *(int *)temp2->data);
	//	printf("-----sort: ---\n");
	//	printf(" r: %d\n",r);
	//	printf("temp data: %s \n",(char *)temp->data );
	//	printf("temp2 data: %s \n",(char *)temp2->data );
	//	printf("--------------\n");
		if (r > 0)
		{
			ft_list_swap(begin, temp, temp2);
			//	ft_list_print_list_elegant(*begin);

			temp = *begin;
			temp2 = temp->next;
			i = -1;
		}
		temp = temp->next;
		temp2 = temp->next;
	}
}

int main()
{



	t_list	**begin;
	t_list	*first; 
	t_list *second;
	t_list *third;
	t_list *fourth;
	t_list *five;

	

	int		num;
	int		num2;
	int		num3;
//	int		size;
	//int		num4;
	(void)first;
	(void)second;
	(void)third;
	(void)fourth;
	(void)five;

	begin = (t_list **)malloc(sizeof(t_list *));
	num = 4;
	num2 = 6;
	num3 = 2;
	char s1[6] = "\t\tCBC";
	char s2[6] = "\t\tABC";
	char s3[6] = "\t\tBBC";
	char s4[6] = "\t\tDBC";
	//num4 = 8;
	//int size_list = 0;
	
//	first = ft_list_add_node(s1);
//	begin = ft_list_add_node(&num);
//	*begin = first;
	*begin = NULL;
//	second = ft_list_add_node_after_this_node(first,s2);
//	third = ft_list_add_node_after_this_node(second,s3);
//	ft_list_add_node_after_this_node(third,s3);
	
//	size_list = ft_list_size(begin);
//	printf("\n==>SIZE LIST : %d\n",size_list);
	ft_list_push_front(begin, s4);
	ft_list_push_front(begin, s3);
	ft_list_push_front(begin, s2);
	ft_list_push_front(begin, s1);
	printf("begin: %p \n\n",begin);
	ft_list_print_list_elegant(*begin);
	printf("--------------------\n");
	//int r = ft_strcmp((*begin)->data, (*begin)->next->data);
	ft_list_sort(begin,&strcmp);
//	printf("r: %d\n",r);
	ft_list_print_list_elegant(*begin);
//	ft_list_sort_ascending(begin);
//	ft_list_print_list_elegant(first);

//	ft_list_print_list(begin);
//t_list_push_front(begin, &num2);
//	size_list = ft_list_size(begin);
//	printf("\n==>SIZE LIST : %d\n",size_list);
//	ft_list_print_list(begin);
//	
//	ft_list_del_all_nodes(begin);
//	free(begin);
	//printf("\n---END---\n");
	return (0); 
}