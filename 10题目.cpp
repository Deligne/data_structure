#include<iostream>
#include<cstdlib>
#include<iomanip>

#define MAXSIZE 10
using namespace std;

int FindMax(int A[],int n,int i)
{
	float max;
	if(i==n)
		return A[i];
	else
	{
		max=FindMax(A,n,i+1);
		if(A[i]>max)
			return A[i];
		else
			return max;
	}
}

float average(int A[],int n,int i)
{
	if(i==n)
		return A[i];
	else
	{
		return (A[i]+average(A,n,i+1)*(n-i))/(n-i+1);	
	}	
}

typedef struct BTNode{
	int data;
	struct BTNode *l;
	struct BTNode *r;
}BTNode;

void init(BTNode *&p)
{
	p=(BTNode*)malloc(sizeof(BTNode));
	p->data=10;
	BTNode *s;
	s=p;
	s->l=(BTNode*)malloc(sizeof(BTNode));
	s->l->data=9;
	s->l->l=NULL;
	s->l->r=NULL;
	s->r=(BTNode*)malloc(sizeof(BTNode));
	s->r->data=8;
	s->r->l=NULL;
	s->r->r=NULL;
}

void level(BTNode *p)
{
	if(p!=NULL)
	{
		BTNode *que[MAXSIZE];
		int front=0,rear=0;
		que[++rear]=p;
		BTNode *q;
		while(front!=rear)
		{
			front=(front+1)%MAXSIZE;
			q=que[front];
			cout<<q->data;
			if(q->l!=NULL)
			{
				rear=(rear+1)%MAXSIZE;
				que[rear]=q->l;
			}
			if(q->r!=NULL)
			{
				rear=(rear+1)%MAXSIZE;
				que[rear]=p->r;
			}
		}
	}
}

void pre(BTNode *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<endl;
		pre(p->l);
		pre(p->r);
	}
}

typedef struct 
{
	int v,a;
	int elem[MAXSIZE];
	int loc[][MAXSZIE];
}
 
int main()
{
	int A[]={1,2,3,4,2,3,6};
	cout<<FindMax(A,6,0);
	cout<<endl<<average(A,6,0)<<endl;
	BTNode *p;
	init(p);
	pre(p);
	level(p);
}
