#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10

using namespace std;
typedef struct 
{
	int data[MAXSIZE];
	int top; 
}SqStack;
//栈数据结构

int init(SqStack &A,SqStack &B)
{
	A.top=B.top=-1;
	return 1; 
}

int isEmpty(SqStack S)
{
	if(S.top==-1)
		return 1;
	else
		return 0;
} 

int queueEmpty(SqStack &A,SqStack &B)
{
	if(isEmpty(A)&&isEmpty(B))
		return 1;
	else
		return 0;
}

int pop(SqStack &S,int &x)
{
	if(S.top==-1)
		return 0;//check overflow
	x=S.data[S.top--];
	return 1;
}

int push(SqStack &S,int x)
{
	if(S.top==MAXSIZE-1)
		return 0;//check overflow
	S.data[++S.top]=x;
	return 1;
}

int enQueue(SqStack &A,SqStack &B,int x)
{
	int y;
	if(A.top==MAXSIZE-1)
	{
		if(!isEmpty(B))
			return 0;
		else
		{
			while(!isEmpty(A))
			{
				pop(A,y);
				push(B,y);
			}
			push(A,x);
		}
	}
	else
	{
		push(A,x);
		return 1;
	}
	return 1;
}

int deQueue(SqStack &A,SqStack &B,int &x)
{
	int y;
	if(!isEmpty(B))
	{
		pop(B,y);
	}
	else
	{
		if(isEmpty(A))
			return 0;
		else
		{
			while(!isEmpty(A))
			{
				pop(A,y);
				push(B,y);
			}
			pop(B,x);
			return 1; 
		} 
	}
}

int main()
{
	SqStack A,B;
	int x;
	init(A,B);
	enQueue(A,B,10);
	deQueue(A,B,x);
	cout<<x;
	return 1;
}






























































