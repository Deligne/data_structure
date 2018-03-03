#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

int merge(LNode *&A,LNode *&B,LNode *&C)
{
	LNode *p=A->next,*q=B->next;//p,qΪ��ʼ�ڵ��ָ�� 
	LNode *r;
	C=A;
	C->next=NULL;
	free(B);
	r=C;
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<q->data)
		{
			r->next=p;
			r=r->next;
			p=p->next;
		}
		else
		{
			r->next=q;
			r=r->next;
			q=q->next;
		}//�Ƚ�,���� 
	}
	r->next=NULL;
	if(p!=NULL)
		r->next=p;
	if(q!=NULL)
		r->next=q;
}

int createLNodeR(LNode *&C,int a[],int n)
{
	LNode *s,*r;
	int i;
	C=(LNode*)malloc(sizeof(LNode));
	C->next=NULL;
	r=C;//r, Cָ��ͷ��� 
	for(i=0;i<n;i++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=a[i];
		r->next=s;
		r=r->next;
	}
	r->next=NULL;
	return 1;
}//β�巨

int createLNodeF(LNode *&C,int a[],int n)
{
	LNode *s;
	int i;
	C=(LNode*)malloc(sizeof(LNode));
	C->next=NULL;
	s=C;
	for(i=0;i<n;i++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=a[i];
		s->next=C->next;
		C->next=s;
	}
	return 1;
 } 

int print(LNode *C)
{
	LNode *p;
	p=C;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d, ",p->data);
	}
}

int searchAndDelete(LNode *&C,int e)
{
	LNode *p,*r;
	p=C;
	while(p->next!=NULL)
	{
		if(p->next->data==e)
			break;
		p=p->next;
	}//����
	if(p->next==NULL)
		return 0;
	else
	{
		r=p->next;
		p->next=p->next->next;
		free(r);
		return 1;
	}//ɾ�� 
}


int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={6,7,8,9,10};
	LNode *C,*B,*T;
	createLNodeR(C,a,5);
	print(C);
	createLNodeF(B,b,5);
	print(B);
	merge(C,B,T);
	print(T);
	searchAndDelete(C,3);
	print(C); 
	return 1;	
}






















































