#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
using namespace std;


typedef struct BTNode
{
	char data;
	struct BTNode *leftChild;
	struct BTNode *rightChild;
}BTNode;

void preOrder(BTNode *p,char A[],int i)
{
	if(p!=NULL)
	{
		p->data=A[i];
		preOrder(p->leftChild,A,i+1);
		preOrder(p->rightChild,A,i+1);
	}
}

char Ancestor(char A[],int i,int j)
{
	while(i!=j)
	{
		if(i>j)
			i/=2;
		else
			j/=2;
	}
	return A[j];
} 

void assign(BTNode *p,char A[])
{
	int i=0;
	preOrder(p,A,i);
}

int main()
{
	char Tree[]={'0','a','b','c','d','e','f','g','h'};
	cout<<Ancestor(Tree,8,4)<<endl; 
	return 1;
}


