
#include "stdio.h"
#include<iostream>

#define MODE 2//´úÂëÇÐ»»

#define ORDER 0//Ë³Ðò´æ´¢ÆÕÍ¨
#define ORDER_SHARE 1//Ë³Ðò´æ´¢¹²Ïí¿Õ¼ä
#define CHAINED 2//Á´Ê½´æ´¢µÄÕ»


#define maxsize 10
typedef int SElemType;

#if MODE==ORDER
/*Õ»µÄË³Ðò´æ´¢½á¹¹*/



typedef struct
{
	SElemType data[maxsize];
	int top;
}sqStack;

//ÈëÕ»
int Push(sqStack* S, SElemType e)
{
	if (S->top == maxsize - 1)
		return 0;
	else
		S->top++;

	S->data[S->top] = e;
	return 1;


}

int  Pop(sqStack* S, SElemType* e)
{
	if (S->top == -1)
		return 0;

	*e = S->data[S->top];

	S->top--;
	return 1;

}

int main()
{
	sqStack stack;
	stack.top = -1;
	Push(&stack, 32);
	Push(&stack, 21);
	Push(&stack, 45);
	Push(&stack, 39);
	int a, b, c, d;
	Pop(&stack, &a);
	Pop(&stack, &b);
	Pop(&stack, &c);
	Pop(&stack, &d);

	using namespace std;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;


	return 0;
}
//Ë³Ðò´æ´¢½á¹¹µÄÕ»

#elif MODE==ORDER_SHARE

typedef struct
{
	SElemType data[maxsize];
	int top1=-1;
	int top2= maxsize;

}SqDoubleStack;

int Push(SqDoubleStack* S, SElemType e,int stackNumber)
{
	if (S->top1 + 1 == S->top2)//Õ»Âú
		return 0;

	if (stackNumber == 1)
	{
		S->data[++S->top1] = e;
	}
	else if (stackNumber == 2)
	{
		S->data[--S->top2] = e;
	}
	return 1;
}

int Pop(SqDoubleStack* S, SElemType* e, int stackNumber)
{

	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return 0;
		else
			*e = S->data[S->top1--];
		return 1;
	}
	else if(stackNumber == 2)
	{
		if (S->top2 == 10)
			return 0;
		else
			*e = S->data[S->top2++];
		return 1;
	}
	
	return 1;
}
int main()
{
	SqDoubleStack stack;


	Push(&stack, 1, 1);
	Push(&stack, 2, 1);
	Push(&stack, 3, 1);
	Push(&stack, 4, 1);
	Push(&stack, 5, 1);

	Push(&stack, 1, 2);
	Push(&stack, 2, 2);
	Push(&stack, 3, 2);
	Push(&stack, 4, 2);
	Push(&stack, 5, 2);
	
	using namespace std;
	//cout << Push(&stack, 1, 2) << endl;
	//cout << Push(&stack, 1, 1) << endl;
	//cout << stack.data[0] << stack.data[1] << stack.data[2] << stack.data[3] << stack.data[4] << stack.data[5] << stack.data[6] << stack.data[7] << stack.data[8] << stack.data[9] << endl;

	int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0,j = 0;
	Pop(&stack, &a, 1);
	Pop(&stack, &b, 1);
	Pop(&stack, &c, 1);
	Pop(&stack, &d, 1);
	Pop(&stack, &e, 1);

	Pop(&stack, &f, 2);
	Pop(&stack, &g, 2);
	Pop(&stack, &h, 2);
	Pop(&stack, &i, 2);
	Pop(&stack, &j, 2);
	cout << a << b << c << d << e <<endl
		<< f << g << h << i << j << endl;



	return 0;
}
//Ë³Ðò´æ´¢µÄ¹²ÏíÕ»

#elif MODE==CHAINED

//Á´Ê½´æ´¢µÄÕ»
#endif