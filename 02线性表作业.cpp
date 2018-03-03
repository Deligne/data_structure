#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

typedef struct LNode 
{
	int data;
	struct LNode *next;
}LNode;

/*º¯ÊýÉùÃ÷
*/
void printL(LNode *L);
int createList(LNode *&L,int n);
void FindMin(int A[],int &i);
void partition(LNode *&L,LNode *&A,LNode *&B);
void deletere(LNode *&L)
{
	LNode *p,*r=L;
	r=r->next;
	p=r->next;
	while(p!=NULL)
	{
		while(p->data==r->data)
		{
			r->next=p->next;
			free(p);
			p=r->next;
		}
		r=r->next;
		p=r->next;
	}
}
int main()
{
	LNode *L;
	createList(L,10);
	printL(L->next);
	cout<<setw(50)<<"finished."<<endl;
	LNode *A,*B;
	partition(L,A,B);
	printL(A->next);
	printL(B->next);
	return 1;
}



void partition(LNode *&L,LNode *&A,LNode *&B)
{
	B=(LNode*)malloc(sizeof(LNode));
	A=(LNode*)malloc(sizeof(LNode));
	LNode *a=A,*b=B,*p=L->next;
	while(p!=NULL)
	{
		if(p->data%2==0)
		{
			a->next=p;
			a=p;
		}
		else
		{
			b->next=p;
			b=p;
		}
		p=p->next;
	}
	a->next=NULL;
	b->next=NULL;
}
int createList(LNode *&L,int n)
{
	srand((unsigned int)time(NULL));
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;
	int i;
	LNode *s=L;
	for(i=1;i<=n;i++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=rand()%100;
		cout<<s->data<<"  "; 
		s->next=L->next;
		L->next=s; 
	}
	return 1;	
 } 
void printL(LNode *L)
{
	if(L!=NULL)
	{
		printL(L->next);
		cout<<L->data<<", "; 
	}
}//Using stack and recurion to output a reverted squence 

void FindMin(int A[],int &i)
{
	i=0;
	while(i%10<9)
	{
		if(A[i/10]>A[i%10])
		{
			i=i%10*10+i%10;
		}
		i+=1;
	}
	i=i%10;
}















