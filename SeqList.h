# ifndef _SeqList_H__//��ֹͷ�ļ��Ĵ�Ű���


#define MAX 100
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int DataType;

typedef struct SeqList
{
	DataType _data[MAX];//������ݵ�����
	DataType sz;//˳������Ԫ�ظ���
}SeqList;

void SeqListInit(SeqList* pSeq);//��ʼ��˳���
void PushBack(SeqList* pSeq, DataType d);//β������
void PopBack(SeqList*pSeq);//β��ɾ��
void SeqListPrint(SeqList *pSeq);//��ӡ˳���

void PushFront(SeqList* pSeq, DataType d);//ͷ������
void PopFront(SeqList* pSeq);//ͷ��ɾ��
int SLFind(SeqList* pSeq, DataType d);//����Ԫ��
void SLInsert(SeqList* pSeq, int pos,DataType d);//֪��λ�ò���
void Erase(SeqList* pSeq, int pos);//ָ��λ�õ�ɾ��
void Remove(SeqList*pSeq, DataType d);//ɾ��ָ��Ԫ��
//void FRemoveAll(SeqList* pSeq, DataType d);//ɾ�����е�ָ��Ԫ��
void SRemoveAll(SeqList* pSeq, DataType d);//ɾ�����е�ָ��Ԫ��
int Size(SeqList* pSeq);//����˳���Ĵ�С
int Empty(SeqList* pSeq);//˳����Ƿ�Ϊ��

//˳��������
void BubbleSort(SeqList* pSeq);//ð������
void BubbleSort_OP(SeqList* pSeq);//ð�������Ż���

void SelectSort(SeqList* pSeq);//ѡ������
void SelectSort_OP(SeqList* pSeq);//ѡ�������Ż���







////ѡ������
//void SelectSort(PSeqList pSeq);
////ѡ��������Ż�
//void SelectSortOP(PSeqList pSeq);
////���ֲ���
//int BinarySearch(PSeqList pSeq, DataType data);
////���ֲ��ҵݹ�д��
//int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);



#endif  _SeqList_H__