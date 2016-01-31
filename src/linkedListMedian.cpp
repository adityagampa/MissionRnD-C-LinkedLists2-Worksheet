/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head)
{
	if (!head)
		return -1;
	struct node *temp = head, *s = head, *p = head;
	while (temp != NULL)
	{
		if (!temp->next)
			break;
		temp = temp->next->next;
		p = s;
		s = s->next;
	}
	if (!temp)
		return (s->num + p->num) / 2;
	return s->num;
}
