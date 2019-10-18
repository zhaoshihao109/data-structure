
#include "stdio.h"
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

using namespace std;
 


typedef struct QNode {//����Ԫ��
	float ang;
	float dis;
	struct QNode* next;
}QNode,* QueuePtr;

typedef struct {
	QueuePtr front;//ͷָ��
	QueuePtr behind;//βָ��
}LinkQueue;

int init_Queue(LinkQueue* queue)
{
	queue->front = queue->behind = (QueuePtr)malloc(sizeof(QNode));
	if (!queue->front) return 0;
	queue->front->next = NULL;
	return 1;
}

int In_Queue(LinkQueue* queue, float angle, float distance)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) return 0;

	p->ang = angle;
	p->dis = distance;
	p->next = NULL;

	queue->behind->next = p;//��Ϊ��һ��queue->behind��queue->front����ͬһ���ڴ����Ե�һ�����ʱqueue->front->nextҲָ�����Ԫ��
	queue->behind = p;

	return 1;

}

int Out_Queue(LinkQueue* queue, float* angle, float* distance)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (queue->front == queue->behind)return 0;//����Ϊ��

	p = queue->front->next;

	*angle = p->ang;
	*distance = p->dis;

	queue->front->next = p->next;
	if (queue->behind == p) queue->behind = queue->front;
	free(p);
	return 1;//ȡ���ɹ�

}

int Destory_Queue(LinkQueue* queue)
{
	while (queue->front)
	{
		queue->behind = queue->front->next;
		free(queue->front);
		queue->front = queue->behind;
	}
	return 1;

}
float real_angle = 0;
float real_distance = 0;

int main()
{	//����һ������
	LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
	init_Queue(queue);

	int if_ok = 0;
	for (int i = 0; i < 10000*10000; i++)
	{
		if_ok = In_Queue(queue, i, i*10);
		if (!if_ok) i--;
	}
	int i = 0;
	/*while(Out_Queue(queue, &real_angle,&real_distance))
	{
		cout << "�Ƕ�:" << real_angle << "  " << "����:" << real_distance << endl;
		cout << i << endl;
	}*/

	Destory_Queue(queue);

	return 0;
}