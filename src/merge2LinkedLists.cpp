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


struct node *merge2LinkedLists(struct node *p, struct node *q)
{
	struct node *t, *prev, *head;
	if (!p && !q)
		return NULL;
	if (!p)
		return q;
	if (!q)
		return p;
	if (p->num > q->num)
	{
		head = q;
		t = q;
		q = q->next;
	}
	else
	{
		head = p;
		t = p;
		p = p->next;
	}
	while (p && q)
	{
		if (p->num > q->num)
		{
			t->next = q;
			t = q;
			q = q->next;
		}
		else if (p->num < q->num)
		{
			t->next = p;
			t = p;
			p = p->next;
		}
		else
		{
			t->next = p;
			t = p;
			p = p->next;
			t->next = q;
			t = q;
			q = q->next;
		}
	}
	if (q)
		t->next = q;
	else 
		t->next = p;
	return head;
}