#define LIST_INIT_SIZE 100//初始分配量
#define LISTINCREMENT 10//线性表存储空间分配增量
#define ElemType  int

#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;//线性表结构体定义


int InitList(SqList* L)
{
	
	//构造空的线性表
	L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);//分配空间

	cout << "start" << endl;
	if (!L->elem) return 0;
	L->length = 0;//当前长度0
	L->listsize = LIST_INIT_SIZE;//存储容量

	return 1;
}//初始化线性表

int ListInsert(SqList* L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1) return 0;

	if(L->length>=L->listsize)//存满了增加分配空间
	{
		ElemType *newbase = (ElemType*)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) return 0;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}

	ElemType* q = &L->elem[i - 1];//先记录下要插入位置的指针地址
	ElemType* p;//创建一个移动的指针
	for (p = &(L->elem[L->length - 1]); p >= q; p--)* (p + 1) = *p;//从列表尾部开始移动指针并且将后一个元素等于前一个元素直到移动到q指针位置

	*q = e;
	L->length++;
	return 1;


}//在某一个元素前插入新元素

int ListDelete(SqList* L, int i, ElemType* e)
{
	if (i<1 || i>L->length) return 0;
	*e = L->elem[i - 1];
	ElemType* p;

	for (p = &(L->elem[i - 1]); p < &(L->elem[L->length - 1]); p++) * p = *(p+1);
	L->length--;
	return 1;

}//线性表删除元素

void LiseVist(SqList* list)
{
	std::cout << "线性表长度:" << (*list).length << std::endl;

	for (int i = 0; i < list->length; i++)
	{
		cout << "第" << i + 1 << "个元素为:" << list->elem[i] << endl;
	}
}

int MergeList(SqList* la, SqList* lb,SqList *lc)
{
	ElemType *pa = la->elem;
	ElemType *pb = lb->elem;

	ElemType *pa_last = la->elem + la->length - 1;
	ElemType *pb_last = lb->elem + lb->length - 1;

	lc->listsize = lc->length = lb->length + la->length;
	ElemType* pc = lc->elem = (ElemType*)malloc(lc->listsize * sizeof(ElemType));
	if (!lc->elem) { return 0; }

	while (pa <= pa_last && pb <= pb_last)//归并
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;

	}
	while (pa <= pa_last)
	{
		*pc++ = *pa++;

	}
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}
	return 1;


	
}//归并递增序列

SqList *list1 = (SqList *)malloc(sizeof(SqList));
SqList* list2 = (SqList*)malloc(sizeof(SqList));
SqList* list3 = (SqList*)malloc(sizeof(SqList));
int main()
{

	if (InitList(list1)&& InitList(list2)&&InitList(list3))
	{
		std::cout << "初始化线性表成功" << std::endl;
	}
	else 
	{
		std::cout << "初始化线性表失败" << std::endl;
	}
	for (int i = 0; i <15; i++)
	{
		ListInsert(list1, i+1, i);
		ListInsert(list2, i+1, i+5);
	}
	LiseVist(list1);
	LiseVist(list2);

	//int num = 0;

	//if (!ListDelete(list1,5, &num)) { cout << "索引错误" << endl; }
	//else {
	//	cout<<"删除的元素为:"<<num<<endl;
	//}
	//LiseVist(list1);

	MergeList(list1, list2, list3);

	LiseVist(list3);


	return 0;
}