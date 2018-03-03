#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next; 
}LNdde;

int init(LNode *&L)
{
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;
	return 1;
}

int isEmpty(LNode *&L)
{
	if(L->next==NULL)
		return 1;
	else
		return 0;
}

int push(LNode *&L,int x)
{
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=x;
	s->next=NULL;
	s->next=L->next;
	L->next=s;
	return 1;
}

int pop(LNode *&L,int &x)
{
	LNode *s;
	s=L->next;
	x=s->data;
	L->next=s->next;
	free(s);
}

int print(LNode *L)
{
	LNode *s=L->next;
	while(s!=NULL)
	{
		cout<<s->data<<setw(5);
		s=s->next;
	}
	return 1;
}
int main()
{
	LNode *L;
	init(L);
	int x;
	push(L,10);push(L,100);pop(L,x);
	print(L);
	return 1;
}























