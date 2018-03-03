#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
using namespace std;

typedef struct TBTNode 
{
	char data;
	int ltag,rtag;
	struct TBTNode *lchild;
	struct TBTNode *rchild;	
}TBTNode;

void InThread(TBTNode *p,TBTNode *&pre)
{
	if(p!=NULL)
	{
		InThread(p->lchild,pre);
		if(p->lchild==NULL)
		{
			p->lchild=pre;
			p->ltag=1;
		}
	}
	if(pre!=NULL&&pre->rchild==NULL)
	{
		pre->rchild=p;
		pre->rtag=1;
	}
	pre=p;
	InThread(p->rchild,pre);
}

void createInThread(TBTNode *root)
{
	TBTNode *pre=NULL;
	if(root!=NULL)
	{
		pre->rchild=NULL;
		pre->rtag=0;
	}
}//创建中序线索二叉树

TBTNode *First(TBTNode *p)
{
	while(p->ltag==0)
		p=p->lchild;
	return p;	
} 

TBTNode *Next(TBTNode *p)
{
	if(p->rtag==0)
		return First(p->rchild);
	else
		return p->rchild;
}

void trave(TBTNode *root) 
{
	for(TBTNode *p=First(root);p!=NULL;p=Next(p))
		visit(p);	
}//遍历中序线索二叉树



















 












































