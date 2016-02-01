/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};


struct node *merge2LinkedLists(struct node *head, struct node *temp)
{
	struct node *prev = head, *m = head;
	int flag = 0;
	if (!temp)
		return head;
	if (!head)
		return temp;
	if (head->num > temp->num)
	{
		m = temp;
		temp = head;
	}
	while (m && temp)
	{
		if (temp->num < m->num && flag == 0)
		{
			prev->next = temp;
			prev = temp;
			temp = temp->next;
			flag = 1;
		}
		else if (flag && m->num < temp->num)
		{
			prev->next = m;
			prev = m;
			m = m->next;
			flag = 0;
		}
		else if (flag == 0)
		{
			prev = m;
			m = m->next;
		}
		else if (flag)
		{
			prev = temp;
			temp = temp->next;
		}

	}
	if (m)
	{
		prev->next = m;
	}
	else if (temp)
		prev->next = temp;
	return head;
}