
#include "stdio.h"
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

using namespace std;
 


typedef struct QNode {//定义元素
	float ang;
	float dis;
	struct QNode* next;
}QNode,* QueuePtr;

typedef struct {
	QueuePtr front;//头指针
	QueuePtr behind;//尾指针
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

	queue->behind->next = p;//因为第一次queue->behind和queue->front共用同一块内存所以第一次入队时queue->front->next也指向这个元素
	queue->behind = p;

	return 1;

}

int Out_Queue(LinkQueue* queue, float* angle, float* distance)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (queue->front == queue->behind)return 0;//队列为空

	p = queue->front->next;

	*angle = p->ang;
	*distance = p->dis;

	queue->front->next = p->next;
	if (queue->behind == p) queue->behind = queue->front;
	free(p);
	return 1;//取出成功

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
{	//声明一个队列
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
		cout << "角度:" << real_angle << "  " << "距离:" << real_distance << endl;
		cout << i << endl;
	}*/

	Destory_Queue(queue);

	return 0;
}