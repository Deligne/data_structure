#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10

using namespace std;

typedef struct 
{
	int length;
	char data[MAXSIZE];
}SqList;

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

void reverseSqList(SqList &S)
{
	int temp,l=0,r=S.length-1;
	while(l<r)
	{
		temp=S.data[l];
		S.data[l]=S.data[r];
		S.data[r]=temp;
		++l;--r; 
	}
}

void printSqList(SqList S)
{
	for(int i=0;i<S.length;++i)
	{
		cout<<S.data[i]<<endl;
	}
}

int create(Node *&p,int A[],int n)
{
	p=(Node*)malloc(sizeof(Node));
	p->next=NULL;
	Node *s=p;
	for(int i=0;i<n;++i)
	{
		Node *r=(Node*)malloc(sizeof(Node));
		r->data=A[i];
		r->next=s->next;
		s->next=r;
		s=r;
	}
	return 1;
}

void printL(Node *p)
{
	Node *s=p->next;
	while(s!=NULL)
	{
		cout<<s->data<<endl;
		s=s->next;
	}
}

void printK(Node *p,int k,int &i)
{
	if(p==NULL)
		return;
	else
	{
		printK(p->next,k,i);
			i++;
			if(i==k)
				cout<<p->data<<endl;
	}
}

int main()
{
	SqList S;
	S.data[0]='a';
	S.data[1]='b';
	S.data[2]='c';
	S.length=3;
	Node *p;
	int A[]={1,2,3,4,5};
	create(p,A,5);
	printL(p);
	int u=0; 
	printK(p,1,u);
	return 1;	
} 
