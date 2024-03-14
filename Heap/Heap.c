#include "Heap.h"

/// <summary>
/// �ѵĳ�ʼ������
/// </summary>
/// <param name="php">�ѽṹ�������ָ��</param>
void HP_Init(HP* php)
{
	assert(php);
	php->val = NULL;
	php->size = 0;
	php->capacity = 0;
}

/// <summary>
/// �ѵ����ٺ���
/// </summary>
/// <param name="php">�ѽṹ�������ָ��</param>
void HP_Destroy(HP* php)
{
	assert(php);
	assert(php->val);

	free(php->val);
	php->val = NULL;
	php->size = 0;
	php->capacity = 0;
}

/// <summary>
/// �ڲ����õĽ�������
/// </summary>
/// <param name="val1">Ҫ����������1</param>
/// <param name="val2">Ҫ����������2</param>
static void Swap(HPDataType* val1, HPDataType* val2)
{
	HPDataType tmpval = *val1;
	*val1 = *val2;
	*val2 = tmpval;
}

/// <summary>
/// ��������֮�������ݱ��ֶѵ����Ե����ϵ����㷨
/// </summary>
/// <param name="val">�洢�����ݵ�����ָ��</param>
/// <param name="i">���һ����Ч���ݵ��±�</param>
static void AdjustUp(HPDataType* val, int i)
{
	while (i > 0)//����ֻ��Ҫ���ڣ�����Ҫ���ڵ���
	{
		//if (val[i] < val[(i - 1) / 2])//��С��
		if (val[i] > val[(i - 1) / 2])//����,������߼��Ƚϲ����Դ��ڵ���ֻ���Դ��ڣ�Ҫ��Ȼ�������ѭ�������統����²��������������������ֵ������Ǵ��ڵ��ھͻ���ѭ��
		{
			
			Swap(&(val[i]), &(val[(i - 1) / 2]));
			i = (i - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

/// <summary>
/// ɾ�����ݺ������ݱ��ֶ����Ե����µ����㷨
/// </summary>
/// <param name="val">�洢�����ݵ�����ָ��</param>
/// <param name="size">��ǰ�ѵĴ�С</param>
/// <param name="i">��ǰ�Ѷ����±�</param>
static void AdjustDown(HPDataType* val, int size, int i)
{
	int tmp = i * 2 + 1;
	while (tmp < size)//��һ���ڵ�������±곬�������С����ôҲ����˵������ڵ�û�������ӣ�����ڵ���һ��Ҷ�ӽڵ㡣
	{
		//����������������������С��
		//if (tmp + 1 < size && val[tmp + 1] < val[tmp])//��С��
		if (tmp + 1 < size && val[tmp + 1] > val[tmp])//����,tmp + 1 < size��Ϊ�˱�֤�����Һ��ӣ�����������Һ��ӾͿ϶�ֻ��������С����ֹ����Խ��
		{
			tmp += 1;
		}
		//if (val[tmp] < val[i])//��С��
		if (val[tmp] > val[i])//����
		{
			Swap(&(val[i]), &(val[tmp]));//���½���
			i = tmp;
			tmp = i * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

/// <summary>
/// �ѵĲ��뺯����β�壬������ٵ������ݣ������ݱ��ֶѵ�����
/// </summary>
/// <param name="php">Ҫ����Ķѣ����ݶѽṹ�������ָ��</param>
/// <param name="val">Ҫ�����ֵ</param>
void HP_Push(HP* php, HPDataType val)
{
	assert(php);
	//�ռ䲻������
	if (php->size >= php->capacity)
	{
		//capacity��ֵ��Ϊ0ʱ
		if (php->capacity)
		{
			php->capacity *= 2;
		}
		else
		{
			php->capacity = 4;
		}
		HPDataType* newHPDataType = (HPDataType*)realloc(php->val, sizeof(HPDataType) * php->capacity);
		if (newHPDataType == NULL)
		{
			perror("HP_Push:realloc");
			exit(1);
		}
		php->val = newHPDataType;
	}
	php->val[php->size++] = val;
	//���ϵ����㷨��Ҫ�ò������ݺ󱣳ֶѵ�����
	AdjustUp(php->val, php->size - 1);
}

/// <summary>
/// ���ضѶ���ֵ
/// </summary>
/// <param name="php">Ҫ�鿴�Ķѽṹ�������ָ��</param>
/// <returns>�Ѷ���ֵ�����ǲ������Ѷ�</returns>
HPDataType HP_Top(HP* php)
{
	assert(php);

	return php->val[0];
}

/// <summary>
/// �����Ѷ�
/// </summary>
/// <param name="php">Ҫ�����Ķѽṹ�������ָ��</param>
void HP_Pop(HP* php)
{
	assert(php);
	assert(php->size > 0);//Ҫ�����ݲſ���pop

	//����β����
	Swap(&(php->val[0]), &(php->val[php->size - 1]));
	//ɾ��βֵ
	php->size--;
	//���µ����㷨
	AdjustDown(php->val, HP_Size(php), 0);
}

/// <summary>
/// �ж�ָ�����Ƿ�Ϊ��
/// </summary>
/// <param name="php">Ҫ�鿴�Ķѽṹ�������ָ��</param>
/// <returns>�������ʾ������ǿյģ���֮���ؼپ��ǲ���</returns>
bool HP_Empty(HP* php)
{
	assert(php);

	return php->size == 0;
}

/// <summary>
/// ����ָ���ѵĴ�С
/// </summary>
/// <param name="php">Ҫ�鿴�Ķѽṹ�������ָ��</param>
/// <returns>ָ���ѵ���Ч���ݵĸ���</returns>
int HP_Size(HP* php)
{
	assert(php);

	return php->size;
}

void HP_InitArray(HP* php, HPDataType* arr, int size)
{
	php->val = (HPDataType*)malloc(sizeof(HPDataType) * size);
	if (php->val == NULL)
	{
		perror("HP_InitArray:malloc");
		exit(1);
	}
	memcpy(php->val, arr, sizeof(HPDataType) * size);
	php->capacity = php->size = size;

	////���Ͻ���
	//for (int i = 1; i < php->size; i++)
	//{
	//	AdjustUp(php->val, i);
	//}

	//���½���
	//���µ������㷨��һ��Ҫ��Ҫ��ǰ�ڵ������������Ҫ����ѵ����ʣ�ֻ�е�ǰ�ڵ㲻����ѵ�����
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->val, php->size, i);
	}
}

void HeapSort(int* a, int n)
{
	HP hp;
	HP_InitArray(&hp, a, n);
	//���Ѷ��������ε����������У���ʱ����Ǵ�Ѿ��ǽ���С�Ѿ�������
	int i = 0;
	while (!HP_Empty(&hp))
	{
		a[i++] = HP_Top(&hp);
		HP_Pop(&hp);
	}
	HP_Destroy(&hp);
}
