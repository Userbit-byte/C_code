
#include "SeqList.h"
void TestSeqList()
{
    SL s1;
    SeqListInit(&s1);
    SeqListPushBack(&s1,1);
    SeqListPushBack(&s1,4);
    SeqListPushBack(&s1,5);
    SeqListPushBack(&s1,6);
    SeqListPushBack(&s1,7);
    SeqListPushFront(&s1,6);
    SeqListPushFront(&s1,6);
    SeqListPushFront(&s1,6);
    SeqListPushFront(&s1,6);
    SeqListPushFront(&s1,6);
    SeqListPrint(&s1);
    SeqListFront(&s1);
    printf("\n");
    SeqListPrint(&s1);
    printf("\n");
    SeqListInsert(&s1,2,60);//在下标为二的位置插入60
    SeqListPrint(&s1);
    SeqListDelete(&s1,2);
    printf("\n");
    SeqListPrint(&s1);//将下标为第二个位置的元素删除

    int ret=SeqListFind(&s1,5);//查找5的下标；

    printf("ret=%d\n",ret);
    s1.arr[9]=999;
    s1.size++;
    SeqListPrint(&s1);
    SeqListDestory(&s1);
}
void menu()
{
    printf("*************************\n");
    printf("**************************\n");
    printf("****************************\n");

}

int main()
{

    TestSeqList();
    return 0;
}