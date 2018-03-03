#include<iostream>
#include<cstdlib>
#include<iomanip>
#define MAX 50
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

int createS(Node *&p,int A[],int n)
{
	if(!(p=(Node*)malloc(sizeof(Node))))
		return 0;
	p->next=NULL;
	Node *c=p;
	for(int i=1;i<=n;++i)
	{
		Node *s=(Node*)malloc(sizeof(Node));
		s->next=c->next;
		s->data=A[i];
		c->next=s;
		c=s;
	}
	cout<<"created"<<endl;
	return 1;
}

void printS(Node *p)
{
	if(p->next==NULL)
		return;
	else
	{
		printS(p->next);
		cout<<p->data<<endl;
	}
}

void print(Node *p)
{
	if(p->next==NULL)
		return;
	Node *s=p->next;
	cout<<s->data<<endl;
	s=s->next;
}

int main()
{
	int A[6]={0,1,2,3,4,5};
	Node *p;
	createS(p,A,5);
	printS(p);
}
