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

void split2(Node *A,Node *&B)
{
	Node *p,*r,*q;
	B=(Node*)malloc(sizeof(Node));
	B->next=NULL;
	r=B;
	p=A;
	while(p->next!=NULL)
	{
		if(A->next->data%2==0)
		{
			q=p->next;
			p->next=q->next;
			q->next=NULL;
			r->next=q;
			r=q;
		}
		else
			p=p->next;
	}
} 

void FindMin(int A[],int &u,int N)
{
	u=A[0];
	while(u/10<=N-1)
	{
		if(u%10>A[u/10])
		{
			u=u-u%10;
			u=u+A[u/10];
		}
		u+=10;
	}
	u=u%10;
}

int major(int A[],int n)
{
	int count=1,temp=A[0];
	int i=1;
	while(i<n)
	{
		if(A[i]==temp)
		{
			++count;
		}
		else 
		if(count>0)
		{
			--count;
		}
		else
		{
			temp=A[i];
			count=1;
		}
		++i;
	}
	count=0;
	for(i=0;i<n;++i)
	{
		if(A[i]==temp)
			++count;
	}
	cout<<temp<<endl;
	if(count>n/2)
		return 1;
	else
		return 0;
}

int main()
{
	int A[5]={1,2,2,2,4};
	cout<<major(A,5);
}
























