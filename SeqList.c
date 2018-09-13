#include"SeqList.h"
void SeqListInit(SeqList* pSeq)//初始化顺序表
{
	//1.assert
	assert(pSeq);
	//2.//顺序表的数组都初始化为0
	memset(pSeq->_data, 0, MAX);
	pSeq->sz = 0;
}
void PushBack(SeqList* pSeq, DataType d)//尾部插入
{
	//2.assert
	assert(pSeq);
	//2.判满
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满\n");
		return ;
	}
	//3.插入元素
	pSeq->_data[pSeq->sz] = d;
	pSeq->sz++;
}
void PopBack(SeqList*pSeq)//尾部删除
{
	//1.asert
	assert(pSeq);
	//2.判断顺序表是否为空
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	//3.删除
	pSeq->sz--;
}
void SeqListPrint(SeqList *pSeq)//打印顺序表
{
	//1.assert
	assert(pSeq);
	//判空
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	//3.打印
	int i; 
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->_data[i]);
	}
	printf("\n");
}
void PushFront(SeqList* pSeq, DataType d)//头部插入
{
	//1.assert
	assert(pSeq);
	//2.判满
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满\n");
		return;
	}
	//3.插入
	int i = pSeq->sz;
	while (i--)//让数组的第一个位置留出来，
	{
		pSeq->_data[i + 1] = pSeq->_data[i];
	}
	pSeq->_data[0] = d;//头插法是从下标为0的地方插入的
	pSeq->sz++;
}
void PopFront(SeqList* pSeq)//头部删除
{
	//1.assert
	assert(pSeq);
	//2.判空
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	//3.删除
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		pSeq->_data[i] = pSeq->_data[i + 1];
	}
	pSeq->sz -- ;
}
int SLFind(SeqList* pSeq, DataType d)//查找元素
{
	//1.assert
	assert(pSeq);
	//2.判空
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return -1;
	}
	//3.查找
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->_data[i] == d)
			return d;
	}
	return 0;
}
void SLInsert(SeqList* pSeq, int pos, DataType d)//知道位置插入
{
	//1.assert
	assert(pSeq);
	//2.判满
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满\n");
		return;
	}
	//插入
	int i =0 ;
	for (i = pSeq->sz; i >= pos; i--)//注意：因为在pos之前插入。所以需要把顺序的最后一位依次向后移动一位，当等于pos时停止
	{
		pSeq->_data[i + 1] = pSeq->_data[i];
	}
	pSeq->_data[pos] = d;//把插入的值放在pos的位置
	pSeq->sz++;
}
void Erase(SeqList* pSeq, int pos)//指定位置的删除
{
	//1.assert
	assert(pSeq);
	//判空
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	//删除,直接删除法，用后边的直接覆盖前边的元素
	int i = 0;
	for (i = pos; i < pSeq->sz; i++)
	{
		pSeq->_data[i] = pSeq->_data[i + 1];
	}
	pSeq->sz--;
}
void Remove(SeqList*pSeq, DataType d)//删除指定元素
{
	//1.assert
	assert(pSeq);
	//判空
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	//删除
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->_data[i] == d)
		{
			for (j = i; j <=pSeq->sz; j++)
			{
				pSeq->_data[j] = pSeq->_data[j + 1];
			}
			pSeq->sz--;
			return;
		}
	}
	printf("要删除的元素不存在\n");
}
void FRemoveAll(SeqList* pSeq, DataType d)//方法一：删除所有的指定元素，委婉覆盖法
{
	//1.assert
	assert(pSeq);
	//2.判空
	if (pSeq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	//3.删除,遇到要删除的数让后边的数直接依次向前移动一位，不用return就可以把相同的数删除完
	int i = pSeq->sz;
	int j = 0;
	while (i--)
	{
		if (pSeq->_data[i] == d)
		{
			for (j = i; j < pSeq->sz; j++)
			{
				pSeq->_data[j] = pSeq->_data[j + 1];
			}
			pSeq->sz--;
		}
	}
}
void SRemoveAll(SeqList* pSeq, DataType d)//方法二：删除所有的指定元素，直接暴力删除法（遇到要删除的直接覆盖）
{
	assert(pSeq);
	int i = 0;
	int count = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->_data[i] != d)//找到不删除的数据
		{
			pSeq->_data[count++] = pSeq->_data[i];//直接在原来的表上进行
		}
	}
	pSeq->sz = count;//给定顺序表的元素个数
}

void CRemoveAll(SeqList* pSeq, DataType d)//方法二：删除所有的指定元素，动态开辟法（把不生成的数据复制到开辟的数组里）
{
	assert(pSeq);
	DataType *tmp=0;
	int i = 0;
	int count = 0;
	tmp = (DataType*)malloc(sizeof(DataType)*pSeq->sz);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->_data[i] != d)//把不删除的数据拷贝到开辟的数组里
		{
			tmp[count++] = pSeq->_data[i];
		}
	}
	memcpy(pSeq->_data, tmp, sizeof(DataType)*count);//把tmp中的元素拷贝到pSeq中
	pSeq->sz = count;//把元素个数给pSeq
	free(tmp);//动态开辟以后一定要释放
	tmp = NULL;//防止生成野指针
}
int Size(SeqList* pSeq)//返回顺序表的大小
{
	assert(pSeq);
	return pSeq->sz;//直接返回顺序表的大小
}
int Empty(SeqList* pSeq)//顺序表是否为空
{
	assert(pSeq);
	return pSeq->sz == 0 ? 0 : 1;//空返回0，非空返回1
}


void Swap(DataType *x1, DataType *x2)
{
	DataType tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}
void BubbleSort(SeqList* pSeq)//冒泡排序
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz - 1; i++)//外部循环：排序的趟数
	{
		for (j = 0; j < pSeq->sz - 1 - i; j++)//每一趟排序的次数
		{
			if (pSeq->_data[j]>pSeq->_data[j + 1])//当前一个数比后一个数大时
			{
				Swap(&pSeq->_data[j], &pSeq->_data[j + 1]);
			}
		}
	}
}
void BubbleSort_OP(SeqList* pSeq)//冒泡排序优化版
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < pSeq->sz - 1; i++)//外部循环：排序的趟数
	{
		flag = 0;//标记为0
		for (j = 0; j < pSeq->sz - 1 - i; j++)//每一趟排序的次数
		{
			if (pSeq->_data[j]>pSeq->_data[j + 1])//当前一个数比后一个数大时
			{
				Swap(&pSeq->_data[j], &pSeq->_data[j + 1]);
				flag = 1;//如果交换了，在标记为1
			}
		}
		if (flag == 0)//如果flag==0说明排序完成
			return;
	}
}
void SelectSort(SeqList* pSeq)//选择排序
{
	//1.assert
	assert(pSeq);
	//找出最大值
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz-1; i++)//排序的趟数
	{
		int max = 0;
		for (j = 0; j < pSeq->sz - i; j++)
		{
			if (pSeq->_data[max] < pSeq->_data[j])//找出最大值得下标
			{
				max = j;
			}
		}
		if (max != pSeq->sz - i - 1)//当max == pSeq->sz-i-1时说明排序完成
		{
			Swap(&pSeq->_data[max], &pSeq->_data[pSeq->sz-i-1]);//把最大值放在最后一个位置
		}
	}
}



