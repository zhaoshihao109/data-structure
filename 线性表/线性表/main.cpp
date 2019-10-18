#define LIST_INIT_SIZE 100//��ʼ������
#define LISTINCREMENT 10//���Ա�洢�ռ��������
#define ElemType  int

#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;//���Ա�ṹ�嶨��


int InitList(SqList* L)
{
	
	//����յ����Ա�
	L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);//����ռ�

	cout << "start" << endl;
	if (!L->elem) return 0;
	L->length = 0;//��ǰ����0
	L->listsize = LIST_INIT_SIZE;//�洢����

	return 1;
}//��ʼ�����Ա�

int ListInsert(SqList* L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1) return 0;

	if(L->length>=L->listsize)//���������ӷ���ռ�
	{
		ElemType *newbase = (ElemType*)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) return 0;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}

	ElemType* q = &L->elem[i - 1];//�ȼ�¼��Ҫ����λ�õ�ָ���ַ
	ElemType* p;//����һ���ƶ���ָ��
	for (p = &(L->elem[L->length - 1]); p >= q; p--)* (p + 1) = *p;//���б�β����ʼ�ƶ�ָ�벢�ҽ���һ��Ԫ�ص���ǰһ��Ԫ��ֱ���ƶ���qָ��λ��

	*q = e;
	L->length++;
	return 1;


}//��ĳһ��Ԫ��ǰ������Ԫ��

int ListDelete(SqList* L, int i, ElemType* e)
{
	if (i<1 || i>L->length) return 0;
	*e = L->elem[i - 1];
	ElemType* p;

	for (p = &(L->elem[i - 1]); p < &(L->elem[L->length - 1]); p++) * p = *(p+1);
	L->length--;
	return 1;

}//���Ա�ɾ��Ԫ��

void LiseVist(SqList* list)
{
	std::cout << "���Ա���:" << (*list).length << std::endl;

	for (int i = 0; i < list->length; i++)
	{
		cout << "��" << i + 1 << "��Ԫ��Ϊ:" << list->elem[i] << endl;
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

	while (pa <= pa_last && pb <= pb_last)//�鲢
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


	
}//�鲢��������

SqList *list1 = (SqList *)malloc(sizeof(SqList));
SqList* list2 = (SqList*)malloc(sizeof(SqList));
SqList* list3 = (SqList*)malloc(sizeof(SqList));
int main()
{

	if (InitList(list1)&& InitList(list2)&&InitList(list3))
	{
		std::cout << "��ʼ�����Ա�ɹ�" << std::endl;
	}
	else 
	{
		std::cout << "��ʼ�����Ա�ʧ��" << std::endl;
	}
	for (int i = 0; i <15; i++)
	{
		ListInsert(list1, i+1, i);
		ListInsert(list2, i+1, i+5);
	}
	LiseVist(list1);
	LiseVist(list2);

	//int num = 0;

	//if (!ListDelete(list1,5, &num)) { cout << "��������" << endl; }
	//else {
	//	cout<<"ɾ����Ԫ��Ϊ:"<<num<<endl;
	//}
	//LiseVist(list1);

	MergeList(list1, list2, list3);

	LiseVist(list3);


	return 0;
}