#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list
 * @head: pointer to first node in the list
 * @n: value of second node in the list
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_node(listint_t **head, int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (*head);
}

/**
 * reverse - makes a reversed copy of a list
 * @head_ref: pointer to first node of a reversed list
 * @head: pointer to first node of original list
 * Return: None
 */
void reverse(listint_t **head_ref, listint_t **head)
{
	listint_t *tmp = *head;

	while (tmp)
	{
		add_node(head_ref, tmp->n);
		tmp = tmp->next;
	}
}

/**
 * compare_lists - compares original and reversed list
 * @head1: first node of one list
 * @head2: first node of other list
 * Return: 1 if they are same, 0 if they are not
 */
int compare_lists(listint_t *head1, listint_t *head2)
{
	listint_t *temp1 = head1;
	listint_t *temp2 = head2;

	while (temp1 && temp2)
	{
		if (temp1->n == temp2->n)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			return (0);
	}

	/* both are empty so they are the same*/
	if (temp1 == NULL && temp2 == NULL)
		return (1);

	/* one list is not NULL, so they are different */
	return (0);
}

/**
 * is_palindrome - checks if linked list is palindrome
 * @head: pointer to first node of one list
 * Return: 1 if they are same, 0 if they are not
 */
int is_palindrome(listint_t **head)
{
	listint_t *head1 = NULL;
	int ret;

	if (!(*head) || !((*head)->next))
		return (1);
	reverse(&head1, head);
	ret = compare_lists(*head, head1);
	return (ret);
}
