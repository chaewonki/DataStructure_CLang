#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

//���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	if (*phead == NULL) // ���� ����Ʈ�� ���
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL)	//p�� NULL�̸� ù ��° ���� ����
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else     // p ������ ����
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

void display(ListNode *head)
{
	ListNode *p = head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

void display_recur(ListNode *head)
{
	ListNode *p = head;
	if (p !=NULL)
	{
		printf("%d->", p->data);
		display_recur(p->link);
	}
}

ListNode* search(ListNode *head, int x)
{
	ListNode *p;
	p = head;
	while (p != NULL)
	{
		if (p->data == x)return p;
		p = p->link;
	}
	return p; 
}

// ���� ����Ʈ�� �����Ѵ�.
ListNode* concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else
	{
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode *head)
{
	ListNode *p, *q, *r;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

// ��带 �������� �����ϴ� �Լ�
ListNode* create_node(element data, ListNode *link)
{
	ListNode *new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("�޸� �Ҵ� ����");
	new_node->data = data;
	new_node->link = link;
	return new_node;
}

int main(int argc, char* argv[])
{
	
	ListNode *list1 = NULL, *list2 = NULL;
	ListNode *p;

	printf("list1 = 30->20->10\n");
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));
	display(list1);

	printf("list1 = 20->10\n");
	remove_node(&list1, NULL, list1);
	display(list1);

	printf("list2 = 80->70->60\n");
	insert_node(&list2, NULL, create_node(60, NULL));
	insert_node(&list2, NULL, create_node(70, NULL));
	insert_node(&list2, NULL, create_node(80, NULL));
	display(list2);

	printf("list1 = list1 + list2\n");
	list1 = concat(list1, list2);
	display(list1);

	printf("reverse list1\n");
	list1 = reverse(list1);
	display(list1);

	printf("search for 20\n");
	p = search(list1, 20);
	printf("Ž������ : %d\n", p->data);

	return 0;

	//ListNode *p1;
	//p1 = (ListNode*)mallock(sizeof(ListNode));
	//p1->data = 10;
	//p1->link = NULL;

	//ListNode *p2;
	//p2 = (ListNode*)malloc(sizeof(ListNode));
	//p2->data = 20;
	//p2->link = NULL;
	//p1->link = p2;

	//free(p1);
	//free(p2);
	
}