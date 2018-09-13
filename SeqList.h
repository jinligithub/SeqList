# ifndef _SeqList_H__//防止头文件的存放包含


#define MAX 100
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int DataType;

typedef struct SeqList
{
	DataType _data[MAX];//存放数据的数组
	DataType sz;//顺序表里的元素个数
}SeqList;

void SeqListInit(SeqList* pSeq);//初始化顺序表
void PushBack(SeqList* pSeq, DataType d);//尾部插入
void PopBack(SeqList*pSeq);//尾部删除
void SeqListPrint(SeqList *pSeq);//打印顺序表

void PushFront(SeqList* pSeq, DataType d);//头部插入
void PopFront(SeqList* pSeq);//头部删除
int SLFind(SeqList* pSeq, DataType d);//查找元素
void SLInsert(SeqList* pSeq, int pos,DataType d);//知道位置插入
void Erase(SeqList* pSeq, int pos);//指定位置的删除
void Remove(SeqList*pSeq, DataType d);//删除指定元素
//void FRemoveAll(SeqList* pSeq, DataType d);//删除所有的指定元素
void SRemoveAll(SeqList* pSeq, DataType d);//删除所有的指定元素
int Size(SeqList* pSeq);//返回顺序表的大小
int Empty(SeqList* pSeq);//顺序表是否为空

//顺序表的排序
void BubbleSort(SeqList* pSeq);//冒泡排序
void BubbleSort_OP(SeqList* pSeq);//冒泡排序优化版

void SelectSort(SeqList* pSeq);//选择排序
void SelectSort_OP(SeqList* pSeq);//选择排序优化版







////选择排序
//void SelectSort(PSeqList pSeq);
////选择排序的优化
//void SelectSortOP(PSeqList pSeq);
////二分查找
//int BinarySearch(PSeqList pSeq, DataType data);
////二分查找递归写法
//int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);



#endif  _SeqList_H__