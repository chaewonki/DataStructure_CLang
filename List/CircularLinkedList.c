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


// 노드를 동적으로 생성하는 프로그램
ListNode* create_node(element data, ListNode *link)
{
	ListNode *new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}


// 리스트의 항목 출력
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

// 원형 연결 리스트에 처음 삽입하는 함수
// phead : 리스트의 헤드 포인터의 포인터
// node : 삽입될 노드
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

// 원형 연결 리스트 삽입 알고리즘
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