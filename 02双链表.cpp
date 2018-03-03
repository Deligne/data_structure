#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

typedef int ElemType;

typedef struct DLNode
{
	ElemType data;
	struct DLNode *prior;
	struct DLNode *next;
 }DLNode;//DLNode 类型,DLNode* 对应的指针类型 
int createDlistR(DLNode *&L,int a[],int n)
{
	DLNode *r,*s;
	L=(DLNode*)malloc(sizeof(DLNode));
	r=L;
	r->next=NULL;
	r->prior==NULL;
	int i;
	for(i=0;i<n;i++)
	{
		s=(DLNode*)malloc(sizeof(DLNode));
		s->data=a[i];
		s->prior=r;
		r->next=s;
		r=s;
	} 
	r->next=NULL;
	return 1;
}

DLNode* getElem(DLNode *L,int x)//返回指针类型 
{
	DLNode *r;
	r=L->next;
	while(r!=NULL)
	{
		if(r->data==x)
			break;
		r=r->next;
	}
	return r;
}

int print(DLNode *L)
{
	DLNode *r;
	r=L->next;
	while(r!=NULL)
	{
		printf("%d, ",r->data);
		r=r->next;
	}
	return 1;
}

int ListDelete(DLNode *L)
{
	DLNode *r=L->next;
	L->next=r->next;
	r->prior=L;
	free(r);
	return 1;
}

int ListInsert(DLNode *L,int x)
{
	DLNode *r=(DLNode*)malloc(sizeof(DLNode));
	r->data=x;
	r->next=L->next;
	r->prior=L;
	L->next=r;
	r->next->prior=L;
	return 1;
}
int main()
{
	int a[5]={1,2,3,4,5};
	DLNode *L;
	createDlistR(L,a,5);
	ListDelete(L);
	ListInsert(L,6);
	print(L);
	printf("%d",getElem(L,3));
}






















