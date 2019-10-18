#include <iostream>
using namespace std;
#define ElemType int

typedef struct LNode {
	ElemType data;
	struct LNode* next;

}LNode, *Linklist;

int List_Insert(Linklist l, int i, ElemType e)
{
	Linklist p = l;

	int j = 0;
	while (j < i - 1 && p) { p = p->next; ++j; }//ָ���ƶ���i-1λ��//��ʱp->nextָ���i��Ԫ��

	if (!p || j > i - 1) return 0;//iС��1���ߴ��ڱ���1

	Linklist new_data = (Linklist)malloc(sizeof(LNode));
	new_data->data = e;
	new_data->next = p->next;
	p->next = new_data;
	l->data++;

	return 0;

}//�ڴ�ͷ���������iλ��֮ǰ����ֵ

int List_Deletesert(Linklist l, int i, ElemType *e)
{
	Linklist p = l;
	Linklist q;

	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}//��ʱp->nextָ���i��Ԫ��
	if (!p->next || j > i - 1) return 0;	
	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	l->data--;
	return 1;


}//�ڴ�ͷ����������ɾ����i��Ԫ�ز���e��������ֵ

void List_Visit(Linklist p)
{
	int size = p->data;
	cout << "������:"<< size << endl;
	p = p->next;

	for (int i = 1; i <= size; i++)
	{
		cout << p->data << endl;
		p = p->next;
	}
}//����������ʾ����

void CreateList_L(LNode *L, int n)
{
	//��λ������n��Ԫ�ص�ֵ,��������ͷ�����Ա�L
	//L = (Linklist)malloc(sizeof(LNode));�Ѿ����ⲿ������һ��ָ�벻��Ҫ�ڴ˴��ظ�����ָ��
	L->next = NULL;
	L->data = 0;
	for (int i = n; i > 0; --i)
	{
		Linklist p = (Linklist)malloc(sizeof(LNode));//�����µĽ��
		printf_s("�������%d��Ԫ��ֵ:", i);
		scanf_s("%d",&(p->data));
		p->next = L->next;
		L->next = p;
		L->data++;
	}
}

void MergeList_L(Linklist la, Linklist lb, Linklist lc)
{
	Linklist pa = la->next;
	Linklist pb = lb->next;
	Linklist pc = lc;

	lc->data = la->data + lb->data;//�ܳ���
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else
		{
			pc->next = pb; pc = pb; pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;

	free(la);
	free(lb);

}//��֪la lb ����ֵ�ǵݼ����� �����ϲ���һ��ֵ�ǵݼ�����



int main()
{
	//Linklist list = (Linklist)malloc(sizeof(LNode));
	//list->data = 0;
	//for (int i = 1; i <= 10; i++) List_Insert(list, i, i);
	//List_Visit(list);

	//ElemType j = 0;
	//List_Deletesert(list, 5, &j);
	//List_Visit(list);

	//cout << "ɾ��Ԫ��Ϊ:"<<j << endl;
	Linklist lsit1 = (Linklist)malloc(sizeof(LNode));
	Linklist lsit2 = (Linklist)malloc(sizeof(LNode));
	Linklist lsit3 = (Linklist)malloc(sizeof(LNode));
	CreateList_L(lsit1, 5);
	CreateList_L(lsit2, 4);
	MergeList_L(lsit1, lsit2, lsit3);
	//List_Visit(lsit1);
	//List_Visit(lsit2);
	List_Visit(lsit3);


	return 0;

}