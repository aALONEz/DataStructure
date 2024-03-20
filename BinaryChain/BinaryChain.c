#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int BTDataType;

typedef struct BTNode
{
	struct BTNode* left;//���ӽڵ�
	struct BTNode* right;//���ӽڵ�
	BTDataType val;
}BTN;

#include "Queue.h"

BTN* CreateBTNode(BTDataType val)
{
	BTN* newBTN = (BTN*)malloc(sizeof(BTN));
	if (newBTN == NULL)
	{
		perror("CreateBTNode:malloc");
		return NULL;
	}
	newBTN->left = NULL;
	newBTN->right = NULL;
	newBTN->val = val;
	return newBTN;
}

BTN* CreateBT(void)
{
	BTN* nd1 = CreateBTNode(1);
	BTN* nd2 = CreateBTNode(2);
	BTN* nd3 = CreateBTNode(3);
	BTN* nd4 = CreateBTNode(4);
	BTN* nd5 = CreateBTNode(5);
	BTN* nd6 = CreateBTNode(6);
	BTN* nd7 = CreateBTNode(7);

	nd1->left = nd2;
	nd1->right = nd4;

	nd2->left = nd3;

	nd4->left = nd5;
	nd4->right = nd6;

	nd2->right = nd7;

	return nd1;
}

void BT_PreOrder(BTN* root)
{
	//�����жϵ�ǰ�ڵ��Ƿ�ΪNULL
	if (root == NULL)
	{
		printf("N ");
		return;//ΪNULLֱ�ӷ���
	}

	//��Ϊ��,���ȷ��ʸ��ڵ�
	printf("%d ", root->val);
	//�ڷ������������ڵ�
	BT_PreOrder(root->left);
	//�ٷ������������ڵ�
	BT_PreOrder(root->right);
}

void BT_MiddleOrder(BTN* root)
{
	//�����жϵ�ǰ�ڵ��Ƿ�ΪNULL
	if (root == NULL)
	{
		printf("N ");
		return;//ΪNULLֱ�ӷ���
	}

	//��Ϊ��,���ȷ������������ڵ�
	BT_MiddleOrder(root->left);
	//�ٷ��ʸ��ڵ�
	printf("%d ", root->val);
	//�ٷ������������ڵ�
	BT_MiddleOrder(root->right);
}

void BT_PostorderOrder(BTN* root)
{
	//�����жϵ�ǰ�ڵ��Ƿ�ΪNULL
	if (root == NULL)
	{
		printf("N ");
		return;//ΪNULLֱ�ӷ���
	}

	//��Ϊ��,���ȷ������������ڵ�
	BT_PostorderOrder(root->left);
	//�ٷ������������ڵ�
	BT_PostorderOrder(root->right);
	//�ٷ��ʸ��ڵ�
	printf("%d ", root->val);
}

int BT_Size(BTN* root)
{
	//���ж��Ƿ��ǿ���
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + BT_Size(root->left) + BT_Size(root->right);//���ڵ�����������Ľڵ����
	}
}

int BT_Height(BTN* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		//ʱ�临�Ӷȹ���
		//return (TreeHeight(root->left) > TreeHeight(root->right) ? TreeHeight(root->left) : TreeHeight(root->right)) + 1;

		//ʱ�临�ӶȽϵ�
		int left = BT_Height(root->left);
		int right = BT_Height(root->right);
		//��Ҫ���ص�ֵҪ���棬������ֱ�ӵ��ú������з��أ������ǵݹ���
		return (left > right ? left : right) + 1;
		
	}
}

int BT_KLevel(BTN* root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	//������NULL����k > 1˵����k������������

	return BT_KLevel(root->left, k - 1) + BT_KLevel(root->right, k - 1);
}

BTN* BT_Find(BTN* root, BTDataType val)
{
	//assert(root);//���ﲻ���ԼӶ��ԣ���Ϊ������Ҫָ��ΪNULL��ʱ��Ҫ����NULL�����������������˾ͻ�һֱ����
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == val)//�жϵ�ǰ�ڵ��ǲ���Ҫ���ҵ�ֵ
	{
		return root;
	}

	BTN* tmpBTN = NULL;
	tmpBTN = BT_Find(root->left, val);//�Ȳ���������
	if (tmpBTN == NULL)//�����������ˣ������ָ��Ͳ���ΪNULL��û���ҵ���ȥ��������
	{
		tmpBTN = BT_Find(root->right, val);
	}

	return tmpBTN;
}

BTN* CreatTree(char* buff, int n, int* pi)
{
	if (buff[*pi] == '#' || (*pi) == (n - 1))
	{
		(*pi)++;
		return NULL;
	}

	BTN* newroot = (BTN*)malloc(sizeof(BTN));
	if (newroot == NULL)
	{
		perror("CreatTree:malloc\n");
		exit(1);
	}
	//ǰ�򹹽�
	newroot->val = buff[(*pi)++];
	newroot->left = CreatTree(buff, n, pi);
	newroot->right = CreatTree(buff, n, pi);
	return newroot;
}

void BT_PreOrder_C(BTN* root)
{
	//�����жϵ�ǰ�ڵ��Ƿ�ΪNULL
	if (root == NULL)
	{
		printf("# ");
		return;//ΪNULLֱ�ӷ���
	}

	//��Ϊ��,���ȷ��ʸ��ڵ�
	printf("%c ", root->val);
	//�ڷ������������ڵ�
	BT_PreOrder_C(root->left);
	//�ٷ������������ڵ�
	BT_PreOrder_C(root->right);
}

void BT_Destroy(BTN* root)
{
	if (root == NULL)
	{
		return;
	}
	BT_Destroy(root->left);
	BT_Destroy(root->right);
	free(root);
}

void BT_LevelOrder(BTN* root)
{
	Queue q;
	QueueInit(&q);//��ʼ������
	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTN* front = QueueFront(&q);//ȡ��ͷ������
		QueuePop(&q);//������ͷ������
		printf("%d ", front->val);

		if (front->left)//������ӽڵ㲻ΪNULL�Ͳ������
		{
			QueuePush(&q, front->left);
		}
		if (front->right)//������ӽڵ㲻ΪNULL�Ͳ������
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");

	QueueDestroy(&q);//���ٶ���
}

bool BT_IsComplete(BTN* root)
{
	Queue q;
	QueueInit(&q);//��ʼ������
	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTN* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)//������һ��NULL������
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))//�жϺ�������Ƿ��зǿգ���Ϊ��ȫ�������������Ĳ�����ֽ��棬����������ַǿվͲ�����ȫ������
	{
		BTN* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)//��NULL��˵��������ȫ������
		{
			printf("Incomplete Binary Tree\n");
			QueueDestroy(&q);
			return false;
		}
	}
	printf("Complete Binary Tree\n");//����ִ�е�����˵����һ��NULL֮����涼��NULL

	QueueDestroy(&q);//���ٶ���
	return true;
}

int main()
{
	BTN* root = CreateBT();

	BT_PostorderOrder(root);
	printf("\n");
	printf("%d\n", BT_Size(root));
	printf("%d\n", BT_Size(root));
	printf("%d\n", BT_Size(root));

	printf("%d\n", BT_Height(root));

	printf("%d\n", BT_KLevel(root, 4));

	if (BT_Find(root, 4))
	{
		printf("�ҵ��ˣ���\n");
	}
	else
	{
		printf("û���ҵ�����\n");
	}

	BT_LevelOrder(root);
	BT_IsComplete(root);


	char buff[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int i = 0;
	int length = strlen(buff);
	BTN* root_C = CreatTree(buff, length, &i);
	BT_PreOrder_C(root_C);

	BT_Destroy(root_C);
	root_C = NULL;
	BT_Destroy(root);
	root = NULL;

	return 0;
}



