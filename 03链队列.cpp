#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10

using namespace std;

typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode;

typedef struct 
{
	QNode *front;
	QNode *rear;
}LiQueue;
 
int init(LiQueue *&Q)
{
	Q=(LiQueue*)malloc(sizeof(LiQueue));
	Q->front=NULL;Q->rear=NULL;
	return 1; 
}

int push(LiQueue *Q,int x)
{
	QNode *s=(QNode*)malloc(sizeof(QNode));
	s->data=x;
	s->next=NULL;//INIT
	if(Q->rear==NULL)
		Q->front=Q->rear=s;
	else
	{
		Q->rear->next=s;
		Q->rear=s;
	}
	return 1;
} 

int pop(LiQueue *Q,int &x)
{
	QNode *r;
	if(Q->rear==NULL)
		return 0;
	else
		r=Q->front;
	x=r->data;
	if(Q->front->next=Q->rear)
		Q->front=Q->rear=NULL;
	else
		Q->front=r->next;
	free(r);
	return 1;
}

int main()
{
	LiQueue *Q;
	int x;
	init(Q);
	push(Q,10);
	push(Q,100);
	pop(Q,x);
	cout<<x; 
	return 1;
}

































 

