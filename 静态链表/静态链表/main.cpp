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
	//�����ھ�̬���е�һ���Ҵ��e��λ��
	int i = S[0].cur;
	while (i && S[i].data != e) i = S[i].cur;
	return i;
	

}

void InitSpace(SLinkList& space)
{
	//����Ϊ����space����������һ����������,space[0].curΪͷָ��
	//"0"Ϊͷָ��
	for (int i = 0; i < MAXSIZE - 1; ++i)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
}

int malloc_sl(SLinkList space)
{
	int i = space[0].cur;
	//���ÿռ�����ǿ�,�򷵻ط���Ľ���±�,���򷵻�Ϊ��
	//���������ͷָ����Զָ����һ�����е�Ԫ
	if (space[0].cur) space[0].cur = space[i].cur;
	return i;
}

void free_sl(SLinkList space,int k)
{
	//���±�ΪK�Ŀ��н����յ���������
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void difference(SLinkList& space, int& S)
{
	//�������뼯��A��B��Ԫ��,��һλ����space�н�����ʾ����
	//SΪͷָ��
	//������A��Ԫ��,������B��Ԫ��,��A��û�������A��������A��ɾ��
	InitSpace(space);
	S = malloc_sl(space);//S��ʾͷ���
	int r = S;//r��ʾָ��S��ǰ�����
	int m; int n; 
	cout << "������m:";
	scanf_s("%d", &m);
	cout << "������n:";
	scanf_s("%d", &n);
	cout << endl;

	int i;//�α�
	for (int j = 1; j <=m; ++j)
	{
		i = malloc_sl(space);
		cout << "������m��" << j << "��Ԫ��" << endl;
		scanf_s("%d",&space[i].data);
		space[r].cur = i; r = i;//���뵽��β
	}//for
	space[r].cur = 0;//β�����ָ��Ϊ��
	
	int b;
	for (int j = 1; j <= n; j++)
	{
		cout << "������n��" << j << "��Ԫ��" << endl;
		scanf_s("%d", &b);
		int p = S;//�α�
		int k = space[S].cur;//��һ�����
		while (k != space[r].cur && b != space[k].data)
		{
			p = k; k = space[k].cur;
		}//while
		if (k == space[r].cur)//��ǰ���в�����Ԫ��,�������
		{
			i = malloc_sl(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}//if
		else//��Ԫ���Ѿ��ڱ���,ɾ��֮
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
	int header;//ͷָ��
	difference(list, header);
	
	cout << endl << "������:" << endl;;
	while (list[header].cur)
	{
		cout << list[header].data<<endl;
		header = list[header].cur;
	}
	return 0;
}