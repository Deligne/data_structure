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

typedef struct
{
	int data[MAXSIZE];
	int left;
	int right;	
}ShStack;

int initSh(ShStack &S)
{
	S.left=0;S.right=MAXSIZE-1;
	return 1;
 } 

int pushSh(ShStack &S,int s,int x)
{
	if(s!=0||s!=1)
		return 0;
	if(S.left+1==S.right)
		return 0;
	if(s==0)
	{
		S.data[++S.left]=x;
	}
	else
	{
		S.data[--S.right]=x;
	}
	return 1;
}
//实现共享栈 


int init(SqStack &S)
{
	S.top=-1;
	return 1;
}

int isEmpty(SqStack S)
{
	if(S.top==-1)
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

int print(SqStack S)
{
	int i=S.top;
	for(i;i>=0;i--)
	{
		cout<<S.data[i]<<setw(5);
	}
	return 1;
}
int main()
{
	SqStack S;
	int e;
	init(S);
	push(S,100);
	push(S,101);
	pop(S,e);
	print(S);
	ShStack S1;
	initSh(S1);
	pushSh(S1,0,10);
	return 1;
}



























