#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "assert.h"
#pragma once
#define MAX 3
typedef int SQDateType;//��ʼ��˳���

typedef struct SeqList{

     SQDateType* arr;//���鳤��
    SQDateType size;//��Ч���ݵĸ���
    SQDateType capacity;//�洢�ռ������
}SL;



void SeqListInit(SL *ps1);//��ʼ�����Ա�
void SeqListCheckCapacity(SL* ps);//���ӿռ䣻
void SeqListPushBack(SL* ps,SQDateType x);//β�壻
void SeqListPrint(SL* ps);//��ӡ˳���
void SeqListPushFront(SL*ps,SQDateType x);//ͷ��
void SeqListPopBack(SL*ps);//βɾ
void SeqListFront(SL*ps);//ͷɾ
void SeqListInsert(SL* ps,int pos,SQDateType x);//������λ�ò��룻
void SeqListDelete(SL* ps,int pos);//������λ��ɾ����
int  SeqListFind(SL* ps,SQDateType x);//����˳���ĳ��Ԫ��
void SeqListModity(SL* ps,int pos,SQDateType x);//�޸�ĳ��Ԫ��
void SeqListDestory(SL* ps);//�������Ա�