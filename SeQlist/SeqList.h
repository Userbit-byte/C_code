#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "assert.h"
#pragma once
#define MAX 3
typedef int SQDateType;//初始化顺序表

typedef struct SeqList{

     SQDateType* arr;//数组长度
    SQDateType size;//有效数据的个数
    SQDateType capacity;//存储空间的容量
}SL;



void SeqListInit(SL *ps1);//初始化线性表
void SeqListCheckCapacity(SL* ps);//增加空间；
void SeqListPushBack(SL* ps,SQDateType x);//尾插；
void SeqListPrint(SL* ps);//打印顺序表；
void SeqListPushFront(SL*ps,SQDateType x);//头插
void SeqListPopBack(SL*ps);//尾删
void SeqListFront(SL*ps);//头删
void SeqListInsert(SL* ps,int pos,SQDateType x);//在任意位置插入；
void SeqListDelete(SL* ps,int pos);//在任意位置删除；
int  SeqListFind(SL* ps,SQDateType x);//查找顺序表某个元素
void SeqListModity(SL* ps,int pos,SQDateType x);//修改某个元素
void SeqListDestory(SL* ps);//销毁线性表