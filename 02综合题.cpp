#include<iostream>
#include<cstdlib>
#include<iomanip>

#define MAXSIZE 10
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

int reverse(int A[],int n)
{
	int temp;
	for(int i=0;i<n/2;++i)
	{
		temp=A[i];
		A[i]=A[n-i-1];
		A[n-i-1]=temp;
	}
}

int deleteitoj(int A[],int n,int i,int j)
{
	int l=j-i+1;
	for(int k=j+1;k<n;++k)
	{
		A[k-l]=A[k];
	}
	n-=l;
}

int divide(int A[],int l,int r)
{
	int temp;
	temp=A[l];
	while(l<r)
	{
		while(i<j&&A[j]>=temp) --j;
		if(i<j)
		{
			A[i]=A[j];
			++i
		}
		while(i<j&&[i]<=temp) --i;
		if(i<j)
		{
			A[j]=A[i];
			--j;
		}
	}
	A[i]=temp;
}

void Reversel(Node *L)
{
	Node *p,*q;
	p=L->next;
	L->next=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
	}
}

int delmin(Node *p)
{
	Node *m;
	int min=p->next->data;
	p=p->next; 
	while(p->next!=NULL)
	{
		if(p->next->data<min)
		{
			min=p->next->data;
			m=p;
		}
		p=p->next;//找到前一个node 
	 } 
	 cout<<min<<endl; 
	Node *n=m->next;
	m->next=n->next;
	free(n);
}
int main()
{
	int A[5]={1,2,3,4,5};
	int n=5;
	reverse(A,5);
	for(int j=0;j<n;++j)
	{
		cout<<A[j]<<"   ";
	}
	cout<<endl;
	deleteitoj(A,5,1,3);
	for(int j=0;j<n-3;++j)
	{
		cout<<A[j]<<"   ";
	}
	int B[5]={3,1,5,2,4};
	divide(B,0,4);
	cout<<endl;
	for(int y=0;y<5;++y)
	{
		cout<<B[y]<<"   ";
	}
	Node *p=(Node*)malloc(sizeof(Node));
	Node *p1=(Node*)malloc(sizeof(Node));
	p1->data=5; 
	Node *p2=(Node*)malloc(sizeof(Node));
	p2->data=2;
	p->next=p1;p1->next=p2;p2->next=NULL;
	delmin(p);
	cout<<endl;
	int R[]={1,1,2,3,3,5,5};
} 
