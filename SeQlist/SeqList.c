//
// Created by user on 2022/11/19.
//
#include "SeqList.h"

void SeqListInit(SL *ps)//初始化空间
{
    ps->arr=NULL;
    ps->size=0;
    ps->capacity=0;
}

void SeqListCheckCapacity(SL* ps)//空间不够增加空间
{
    if(ps->size>=ps->capacity)
    {
        int newcapacity=ps->capacity==0 ? 4:ps->capacity*2;
        SQDateType* tmp=(SQDateType*)realloc(ps->arr,(ps->capacity*2)*sizeof(SQDateType));//动态申请空间
        if(tmp==NULL){
            printf("realloc fall\n");
            exit(-1);
        }
        else
        {
            ps->arr=tmp;
            ps->capacity=newcapacity;
        }
    }
}


//插入元素--尾插法
void SeqListPushBack(SL* ps,SQDateType x)
{
    SeqListCheckCapacity(ps);
    ps->arr[ps->size]=x;
    ps->size++;
}
//打印数据
void SeqListPrint(SL* ps)
{
    for(int i=0;i<ps->size;i++)
        printf("%d ",ps->arr[i]);

}

void SeqListPopBack(SL* ps)//删除元素实现--尾删
{
    assert(ps->size>0);
    ps->size--;
}
void SeqListFront(SL* ps)//头删--删除第start个元素
{
    int start=1;
    while (start<ps->size)
    {
        ps->arr[start-1]=ps->arr[start];
        ++start;
    }
    ps->size--;
}

void SeqListPushFront(SL* ps,SQDateType x)//头插法--在第1个元素位置插入元素；
{
    SeqListCheckCapacity(ps);
    SQDateType end=ps->size-1;
    for(int i=end;i>=0;i--)
    {
        ps->arr[i+1]=ps->arr[i];//将每个元素后移
    }
    ps->arr[0]=x;
    ps->size++;
}

void SeqListInsert(SL* ps,int pos,SQDateType x)//在任意位置插入；
{
    assert(pos<ps->size&&pos>0);//判断插入的位置是否合法；
    SeqListCheckCapacity(ps);
    int end=ps->size-1;//从最后一个元素的下标往后移
    for(int i=end;i>=pos;i--)
    {
        ps->arr[i+1]=ps->arr[i];
    }
    ps->arr[pos]=x;
    ps->size++;
}

void SeqListDelete(SL* ps,int pos)//在任意位置删除；
{
    assert(pos<ps->size);
    int start=pos+1;
    while (start<ps->size)
    {
        ps->arr[start-1]=ps->arr[start];
        ++start;
    }
    ps->size--;
}

int SeqListFind(SL* ps,SQDateType x)//查找顺序表某个元素
{

    for(int i=0;i<ps->size;i++)
    {
        if(ps->arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}

void SeqListModity(SL* ps,int pos,SQDateType x)//修改顺序表某个元素；
{
    assert(pos<ps->size);
    ps->arr[pos]=x;
}

void SeqListDestory(SL* ps)//销毁线性表
{
    free(ps->arr);
    ps->arr=NULL;
    ps->size=0;
    ps->arr=0;
}