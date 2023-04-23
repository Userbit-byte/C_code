//
// Created by user on 2022/11/19.
//
#include "SeqList.h"

void SeqListInit(SL *ps)//��ʼ���ռ�
{
    ps->arr=NULL;
    ps->size=0;
    ps->capacity=0;
}

void SeqListCheckCapacity(SL* ps)//�ռ䲻�����ӿռ�
{
    if(ps->size>=ps->capacity)
    {
        int newcapacity=ps->capacity==0 ? 4:ps->capacity*2;
        SQDateType* tmp=(SQDateType*)realloc(ps->arr,(ps->capacity*2)*sizeof(SQDateType));//��̬����ռ�
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


//����Ԫ��--β�巨
void SeqListPushBack(SL* ps,SQDateType x)
{
    SeqListCheckCapacity(ps);
    ps->arr[ps->size]=x;
    ps->size++;
}
//��ӡ����
void SeqListPrint(SL* ps)
{
    for(int i=0;i<ps->size;i++)
        printf("%d ",ps->arr[i]);

}

void SeqListPopBack(SL* ps)//ɾ��Ԫ��ʵ��--βɾ
{
    assert(ps->size>0);
    ps->size--;
}
void SeqListFront(SL* ps)//ͷɾ--ɾ����start��Ԫ��
{
    int start=1;
    while (start<ps->size)
    {
        ps->arr[start-1]=ps->arr[start];
        ++start;
    }
    ps->size--;
}

void SeqListPushFront(SL* ps,SQDateType x)//ͷ�巨--�ڵ�1��Ԫ��λ�ò���Ԫ�أ�
{
    SeqListCheckCapacity(ps);
    SQDateType end=ps->size-1;
    for(int i=end;i>=0;i--)
    {
        ps->arr[i+1]=ps->arr[i];//��ÿ��Ԫ�غ���
    }
    ps->arr[0]=x;
    ps->size++;
}

void SeqListInsert(SL* ps,int pos,SQDateType x)//������λ�ò��룻
{
    assert(pos<ps->size&&pos>0);//�жϲ����λ���Ƿ�Ϸ���
    SeqListCheckCapacity(ps);
    int end=ps->size-1;//�����һ��Ԫ�ص��±�������
    for(int i=end;i>=pos;i--)
    {
        ps->arr[i+1]=ps->arr[i];
    }
    ps->arr[pos]=x;
    ps->size++;
}

void SeqListDelete(SL* ps,int pos)//������λ��ɾ����
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

int SeqListFind(SL* ps,SQDateType x)//����˳���ĳ��Ԫ��
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

void SeqListModity(SL* ps,int pos,SQDateType x)//�޸�˳���ĳ��Ԫ�أ�
{
    assert(pos<ps->size);
    ps->arr[pos]=x;
}

void SeqListDestory(SL* ps)//�������Ա�
{
    free(ps->arr);
    ps->arr=NULL;
    ps->size=0;
    ps->arr=0;
}