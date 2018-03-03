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
//顺序栈类型定义

int initSqStack(SqStack &S)
{
	S.top=-1;
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

int convert10to2(int n)
{
	SqStack S;
	initSqStack(S);
	while(n)
	{
		push(S,n%2);
		n=n/2;
	}
	print(S);
	return 1;
}//十转二进制 

int fabs(float f)
{
	if(f>=0)
		return f;
	else
		return -f;
}
int sqrt(float A,float p,float e)
{
	if(fabs(p*p-A)<e)
	{
		cout<<p<<endl;
		return p;
	}
	else
		return sqrt(A,(p+A/p)/2,e);	
} 

int main()
{
	convert10to2(7);
	sqrt(15,4,0.001);
	return 1;
}





























































