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

int init(SqStack &S)
{
	S.top=-1;
	return 1;
}

int match(char exp[],SqStack &L)
{
	int i=1;
	char stack(MAXSIZE);int toop=-1;//初始化 栈 
	while(exp[i]!=NULL)
	{
		if(exp[i]=='(')
			push(L,exp[i]);
		elseif(exp[i]==')')
		{
			if(L.top==-1)
				return -1;//判断是否还有'(' 
			pop(L);
		}
		++i;
	}
	if(L.top==-1)
		return 1;
	else
		return 0;
}//利用顺序栈匹配'()'

int op(int a,char op,int b)
{
	if(op=='+') return a+b;
	if(op=='-')	return a-b;
	if(op=='*') return a*b;
	if(op=='/')
	{
		if(b==0)
		{
			cout<<"ERROR:divided by 0"<<endl;
			return 0;
		}
		else
			return a/b;
	}
}
 
int com(char exp[])
{
	char stack[MAXSIZE];top=-1;//init
	char op;
	int i,a,b,c;
	for(i=0;exp[i]!='0';++i)
	{
		if(exp[i]>='0'&&exp[i]<='9')
		{
			stack[++top]=exp[i]-'0';
		}
		else
		{
			op=exp[i];
			a=stack[top--];
			b=stack[top--];
			c=op(a,op,b);
			satck[++top]=c;
		}
	}
	return stack[top];
 }//后缀 
  

int main()
{
	return 1;
 } 










































