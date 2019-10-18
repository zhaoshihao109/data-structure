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
	while (j < i - 1 && p) { p = p->next; ++j; }//指正移动到i-1位置//此时p->next指向第i个元素

	if (!p || j > i - 1) return 0;//i小于1或者大于表长加1

	Linklist new_data = (Linklist)malloc(sizeof(LNode));
	new_data->data = e;
	new_data->next = p->next;
	p->next = new_data;
	l->data++;

	return 0;

}//在带头结点链表中i位置之前插入值

int List_Deletesert(Linklist l, int i, ElemType *e)
{
	Linklist p = l;
	Linklist q;

	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}//此时p->next指向第i个元素
	if (!p->next || j > i - 1) return 0;	
	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	l->data--;
	return 1;


}//在带头结点的链表中删除第i个元素并由e返回他得值

void List_Visit(Linklist p)
{
	int size = p->data;
	cout << "链表长度:"<< size << endl;
	p = p->next;

	for (int i = 1; i <= size; i++)
	{
		cout << p->data << endl;
		p = p->next;
	}
}//遍历链表显示长度

void CreateList_L(LNode *L, int n)
{
	//逆位序输入n个元素的值,建立带表头的线性表L
	//L = (Linklist)malloc(sizeof(LNode));已经在外部声明了一个指针不需要在此处重复声明指针
	L->next = NULL;
	L->data = 0;
	for (int i = n; i > 0; --i)
	{
		Linklist p = (Linklist)malloc(sizeof(LNode));//生成新的结点
		printf_s("请输入第%d个元素值:", i);
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

	lc->data = la->data + lb->data;//总长度
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

}//已知la lb 两个值非递减序列 将俩合并成一个值非递减序列



int main()
{
	//Linklist list = (Linklist)malloc(sizeof(LNode));
	//list->data = 0;
	//for (int i = 1; i <= 10; i++) List_Insert(list, i, i);
	//List_Visit(list);

	//ElemType j = 0;
	//List_Deletesert(list, 5, &j);
	//List_Visit(list);

	//cout << "删除元素为:"<<j << endl;
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