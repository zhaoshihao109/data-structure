#include <iostream>
#define MAXSIZE 1000
#define ElemType int

typedef struct {
	ElemType data;
	int cur;
}SLinkList[MAXSIZE];

using namespace std;

int LocateElem(SLinkList S, ElemType e)
{
	//返回在静态表中第一个找打的e的位置
	int i = S[0].cur;
	while (i && S[i].data != e) i = S[i].cur;
	return i;
	

}

void InitSpace(SLinkList& space)
{
	//将以为数组space各分量连成一个备用链表,space[0].cur为头指针
	//"0"为头指针
	for (int i = 0; i < MAXSIZE - 1; ++i)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
}

int malloc_sl(SLinkList space)
{
	int i = space[0].cur;
	//备用空间链表非空,则返回分配的结点下标,否则返回为零
	//备用链表的头指针永远指向下一个空闲单元
	if (space[0].cur) space[0].cur = space[i].cur;
	return i;
}

void free_sl(SLinkList space,int k)
{
	//将下标为K的空闲结点回收到备用链表
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void difference(SLinkList& space, int& S)
{
	//依次输入集合A和B的元素,在一位数组space中建立表示集合
	//S为头指针
	//先输入A中元素,在输入B中元素,若A中没有则插入A若有则在A中删除
	InitSpace(space);
	S = malloc_sl(space);//S表示头结点
	int r = S;//r表示指向S当前最后结点
	int m; int n; 
	cout << "请输入m:";
	scanf_s("%d", &m);
	cout << "请输入n:";
	scanf_s("%d", &n);
	cout << endl;

	int i;//游标
	for (int j = 1; j <=m; ++j)
	{
		i = malloc_sl(space);
		cout << "请输入m第" << j << "个元素" << endl;
		scanf_s("%d",&space[i].data);
		space[r].cur = i; r = i;//插入到表尾
	}//for
	space[r].cur = 0;//尾部结点指针为空
	
	int b;
	for (int j = 1; j <= n; j++)
	{
		cout << "请输入n第" << j << "个元素" << endl;
		scanf_s("%d", &b);
		int p = S;//游标
		int k = space[S].cur;//第一个结点
		while (k != space[r].cur && b != space[k].data)
		{
			p = k; k = space[k].cur;
		}//while
		if (k == space[r].cur)//当前表中不存在元素,插入表中
		{
			i = malloc_sl(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}//if
		else//该元素已经在表中,删除之
		{
			space[p].cur = space[k].cur;
			free_sl(space,k);
			if (r == k) r = p;
			
		}//else


	}//for
	

}

int main()
{
	//SLinkList slink_list;
	//slink_list[0].cur = 1;
	//slink_list[1].data = 6;
	//slink_list[1].cur = 2;
	//slink_list[2].data = 7;
	//slink_list[2].cur = 0;

	//cout << LocateElem(slink_list, 7) << endl;

	SLinkList list = {0};
	int header;//头指针
	difference(list, header);
	
	cout << endl << "处理结果:" << endl;;
	while (list[header].cur)
	{
		cout << list[header].data<<endl;
		header = list[header].cur;
	}
	return 0;
}