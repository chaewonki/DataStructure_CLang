#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int key;
	struct TreeNode *left, *right;
}TreeNode;

// ��ȯ���� Ž�� �Լ�
TreeNode* search_recur(TreeNode *node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search_recur(node->left, key);
	else
		return search_recur(node->right, key);
}

// �ݺ����� Ž�� �Լ�
TreeNode* search(TreeNode *node, int key)
{
	while (node != NULL)
	{
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;		// Ž���� �������� ��� NULL ��ȯ
}

// key�� ���� Ž��Ʈ�� root�� �����Ѵ�.
// key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.
void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t;	// p�� �θ� ���, t�� ���� ���
	TreeNode *n;		// n�� ���ο� ���

	t = *root;
	p = NULL;
	
	// Ž���� ���� ����
	while (t != NULL)
	{
		if (key == t->key) return; // �̹�����
		p = t;
		if (key < p->key) t = p->left;
		else t = p->right;
	}

	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	// Ʈ�� ��� ����
	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL)	return;
	// ������ ����
	n->key = key;
	n->left = n->right = NULL;
	// �θ� ���� ����
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else
			p->right = n;
	else *root = n; 
}

void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key�� ���� ��� t�� Ž��, p�� t�� �θ� ���
	p = NULL;
	t = *root;

	// key�� ���� ��� t�� Ž���Ѵ�.
	while (t != NULL && t->key != key)
	{
		p = t;
		t = (key < p->key) ? p->left : p->right;
	}

	// Ž���� ����� ������ t�� NULL�̸� Ʈ�� �ȿ� key�� ����
	if (t == NULL)
	{
		printf("key is not in the tree");
		return;
	}

	// ù ��° ���: �ܸ� ����� ���
	if ((t->left == NULL) && (t->right == NULL))
	{
		if (p != NULL)
		{
			// �θ� ����� �ڽ� �ʵ带 NULL�� �����.
			if (p->left == t)
				p->left = NULL;
			else p->right = NULL;
		}
		else		// ���� �θ� ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = NULL;
	}

	// �� ��° ���: �ϳ��� �ڽĸ� ������ ���
	else if ((t->left == NULL) || (t->right == NULL))
	{
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL)
		{
			if (p->left == t)	// �θ� �ڽİ� ����
				p->left = child;
			else p->right = child;
		}
		else		// ���� �θ� ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = child;
	}
	// �� ��° ���: �� ���� �ڽ��� ������ ���
	else
	{
		// ������ ���� Ʈ������ �İ��ڸ� ã�´�.
		succ_p = t;
		succ = t->right;
		// �İ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = succ->left;
		}
		// �ļ����� �θ�� �ڽ��� ����
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		// �ļ��ڿ� ���� Ű ���� ���� ��忡 ����
		t->key = succ->key;
		// ������ �ļ��� ����
		t = succ;
	}
	free(t);
}

int main()
{
	return 0;
}