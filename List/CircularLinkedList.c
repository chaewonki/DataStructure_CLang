#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode *link;
}ListNode;

void error(char *message)
{
	fprintf(stderr, "%s", message);
	exit(1);
}


// ��带 �������� �����ϴ� ���α׷�
ListNode* create_node(element data, ListNode *link)
{
	ListNode *new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}


// ����Ʈ�� �׸� ���
void display(ListNode *head)
{
	ListNode *p;
	if (head == NULL) return;

	p = head;
	do
	{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
}

// ���� ���� ����Ʈ�� ó�� �����ϴ� �Լ�
// phead : ����Ʈ�� ��� �������� ������
// node : ���Ե� ���
void insert_first(ListNode **phead, ListNode *node)
{
	if (*phead == NULL)
	{
		*phead = node;
		node->link = node;
	}
	else
	{
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}

// ���� ���� ����Ʈ ���� �˰���
void insert_last(ListNode **phead, ListNode *node)
{
	if (*phead == NULL)
	{
		*phead = node;
		node->link = node;
	}
	else
	{
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}

int main()
{
	ListNode *list1 = NULL;
	insert_first(&list1, create_node(10, NULL));
	insert_first(&list1, create_node(20, NULL));
	insert_last(&list1, create_node(30, NULL));
	display(list1);

	return 0;
}