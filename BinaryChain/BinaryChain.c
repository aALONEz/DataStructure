#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int BTDataType;

typedef struct BTNode
{
	struct BTNode* left;//左子节点
	struct BTNode* right;//右子节点
	BTDataType val;
}BTN;

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
	BTN* nd7 = CreateBTNode(6);

	nd1->left = nd2;
	nd1->right = nd4;

	nd2->left = nd3;

	nd4->left = nd5;
	nd4->right = nd6;

	nd6->left = nd7;

	return nd1;
}

void BT_PreOrder(BTN* root)
{
	//首先判断当前节点是否为NULL
	if (root == NULL)
	{
		printf("N ");
		return;//为NULL直接返回
	}

	//不为空,就先访问根节点
	printf("%d ", root->val);
	//在访问左子树根节点
	BT_PreOrder(root->left);
	//再访问右子树根节点
	BT_PreOrder(root->right);
}

void BT_MiddleOrder(BTN* root)
{
	//首先判断当前节点是否为NULL
	if (root == NULL)
	{
		printf("N ");
		return;//为NULL直接返回
	}

	//不为空,就先访问左子树根节点
	BT_MiddleOrder(root->left);
	//再访问根节点
	printf("%d ", root->val);
	//再访问右子树根节点
	BT_MiddleOrder(root->right);
}

void BT_PostorderOrder(BTN* root)
{
	//首先判断当前节点是否为NULL
	if (root == NULL)
	{
		printf("N ");
		return;//为NULL直接返回
	}

	//不为空,就先访问左子树根节点
	BT_PostorderOrder(root->left);
	//再访问右子树根节点
	BT_PostorderOrder(root->right);
	//再访问根节点
	printf("%d ", root->val);
}

int BT_Size(BTN* root)
{
	//先判断是否是空树
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + BT_Size(root->left) + BT_Size(root->right);//根节点加左右子树的节点个数
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
		//时间复杂度过高
		//return (TreeHeight(root->left) > TreeHeight(root->right) ? TreeHeight(root->left) : TreeHeight(root->right)) + 1;

		//时间复杂度较低
		int left = BT_Height(root->left);
		int right = BT_Height(root->right);
		//需要返回的值要保存，不建议直接调用函数进行返回，尤其是递归中
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

	//不等于NULL，且k > 1说明第k层在子树里面

	return BT_KLevel(root->left, k - 1) + BT_KLevel(root->right, k - 1);
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

	return 0;
}
