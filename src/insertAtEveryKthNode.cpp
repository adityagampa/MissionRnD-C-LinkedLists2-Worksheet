/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int k) 
{
	if (!head)
		return NULL;
	struct node *pre = head,*temp=head;
	int z = k;
	while (temp)
	{
		z = k;
		while (z)
		{
			pre = temp;
			temp = temp->next;
			z--;
			if (!temp && z)
				return head;
		}
		struct node *p = (struct node *)malloc(sizeof(struct node));
		p->num = k;
		pre->next = p;
		p->next = temp;
	}
	return head;
}
