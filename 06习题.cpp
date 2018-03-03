#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
using namespace std;

typedef struct BTNode
{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

int count(BTNode *p)
{
	int n1,n2;
	if(p==NULL)
		return 0;
	else
	{
		n1=count(p->lchild);
		n2=count(p->rchild);
		return n1+n2+1;
	}
}

int countLeaf(BTNode *p)
{
	if(p==NULL)
		return 0;
	else if(p->lchild==NULL&&p->rchild==NULL)
		return 1;
	else
	{
		n1=count(p->lchild);
		n2=count(p->rchild);
		return n1+n2;
	}
 } 
 
int link(BTNode *p,BTNode *head,BTNode *tail)
{
	if(p!=NULL)
	{
		if(p->lchild==NULL&&p->rchild==NULL)
		{
			if(head==NULL&&tail==NULL)
			{
			head=tail=p;
			}
			else
			{
			tail->rchild=p;
			tail=p;
			}	
		}
		link(p->lchild,head,tail);
		link(p->rchild,head,tail);
	}
}

void createBTree(char A[],BTNode *p)
{
	
}





































