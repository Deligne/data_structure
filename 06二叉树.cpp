#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
using namespace std;

typedef struct BTNode
{
	char data;
	struct BTNode *leftChild;
	struct BTNode *rightChild;
}BTNode;

void level(BTNode *p)
{
	BTNode *s;
	int que[MAXSIZE];
	int rear=0,front=0;
	if(p!=NULL)
	{
		que[++rear]=p;
		while(front!=rear)
		{
			front=(front+1)%MAXSIZE;
			s=que[front];
			visit(s);
			if(s->leftChild)
				que[++rear]=p->leftChild;
			if(s->rightChild)
				...		
		}	
	}	
}

void preOrder(BTNode *p)
{
	if(p!=NULL)
	{
		visit(p);
		preOrder(p->leftChild);
		preOrder(p->rightChild);
	}
}

void inOrder(BTNode *p)
{
	if(p!=NULL)
	{
		inOrder(p->leftChild);
		visit(p);
		inOrder(p->rightChild);
	}
}

void postOrder(BTNode *p)
{
	if(p!=NULL)
	{
		postOrder(p->leftChild);
		postOrder(p->rightChild);
		visit(p);
	}
}


int comp(BTNode *p)
{
	int A,B;
	if(p!=NULL)
	{
		A=comp(p->leftChild);
		B=comp(p->rightChild);
		return op(A,B,p->data);
	}
	else
	{
		return p->data-'0';
	}
	else
		return 0;
}
 
int getDepth(BTNode *p)
{
	int LD,RD;
	if(p==NULL)
		return 0;
	else
	{
		LD=getDepth(p->leftChild);
		RD=getDepth(p->rightChild);
		return (LD>RD?LD:RD)+1;
	 } 
}

void search(BTNode *p,BTNode &q,int key)
{
	if(p!NULL)
	{
		if(p->data==key)
		{
			q=p;
		}
		search(p->leftChild,q,key);
		if(q==NULL)
			search(p->rightChild,q,key);
	}
}

int searchK(BTNode *p,int k,int n)
{
	if(p!=NULL)
	{
		if(n==k)
		{
			cout<<p->data<<endl;
			return;
		}
		else
		{
			searchK(p->leftChild,k,n+1);
			search(p->rightChild,k,n+1);
		}
	}
}

void level(BTNode *p)
{
	int front.rear;
	BTNode *que[MAXSIZE];
	BTNode *q;
	front=rear=0;
	if(p!=NULL)
	{
		rear=(rear+1)%MAXSIZE;
		que[rear]=p;
		while(front!=rear)
		{
			front=(front+1)%MAXSIZE;
			q=que[front];
			visit(q);
			if(q->leftChild!=NULL)
			{
				rear=(rear+1)%MAXSIZE;
				que[rear]=q->leftChild;	
			}
			if(q->rightChild!=NULL)
			{
				rear=(rear+1)%MAXSIZE;
				que[rear]=q->rightChild;
			}
		}
	}
}//²ã´Î±éÀú

 















































