#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_ends - checks if ends the same through recursion backwards
 * @head: pointer to first node of one list
 * @ret: pointer to last node of the list
 * Return: 1 if they are same, 0 if they are not
 */
int check_ends(listint_t *head, listint_t **ret)
{
	int tmp = 0;

	if (head->next == NULL)
	{
		tmp = 1;
	}
	else
	{
		tmp = check_ends(head->next, ret);
	}
	tmp = tmp & (head->n == (*ret)->n);
	*ret = (*ret)->next;
	return (tmp);
}
/**
 * is_palindrome - checks if linked list is palindrome
 * @head: pointer to first node of one list
 * Return: 1 if they are same, 0 if they are not
 */
int is_palindrome(listint_t **head)
{
	if (!head)
		return (1);

	return (check_ends(*head, head));
}
