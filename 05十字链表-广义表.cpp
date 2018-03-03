#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10

using namespace std;

typedef struct OLNode
{
	int row,col;
	struct OLNode *right,*down;
	float val;
}OLNode;//��ͨ���ṹ 

typedef struct{
	OLNode *rhead,*chead;
	int m,n,k;
}CrossList;//ͷ���ṹ

int creatCrossListMat(float A[][MAXSIZE],int m,int n,int k,CrossList &M) 
{
	if(M.chead)
		free(M.chead);	
	if(M.rhead)
		free(M.rhead);
	M.m=m;
	M.n=n;
	M.k=k;
	if(!(M.rhead=(OLNode*)malloc(sizeof(OLNode)*m)))
		return 0;
	if(!(M.chead=(OLNode*)malloc(sizeof(OLNode)*n)))
		return 0;	
	for(int i=0;i<m;++i)
	{
		M.rhead[i].right=NULL;
		M.rhead[i].down=NULL;
	}
	for(int i=0;i<n;++i)
	{
		M.chead[i].right=NULL;
		M.chead[i].down=NULL;
	}
	QLNode *temp[MAXSIZE];
	for(int i=0;i<n;++i)
	{
		temp[i]=&(M.rhead[i]);//����仯�������� 
	}
	for(int i=0;i<m;++j)
	{
		OLNode *c=&(M.rhead[i]);//��ĩ�ڵ� 
		for(int j=0;j<n;j++)
		{
			if(A[i][j]!=0)
			{
				OLNode *p=(OLNode*)malloc(sizeof(OLNode));
				p->row=i;
				p->col=j;
				p->val=A[i][j];
				p->down=NUL;
				p->right=NULL;
				c->right=p;
				c=p;
				temp[j]->down=p;
				temp[j]=p;
			}
		}
	}
	return 1;
}//����ʮ���������

//�����:Ԫ��Ϊԭ�ӻ��߹��������Ա���չ�ṹ

typedef struct 
{
	int data;
	int flag;
}Node;

typedef struct LNode
{
	int data;
	int flag;
	struct LNode *next;
}LNode;

void createG();
{
	
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 





































