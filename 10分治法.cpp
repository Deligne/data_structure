#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
#define M 4
#define N 5
using namespace std;


void print(int A[],int n,int i)
{
	if(n==0)
		return;
	else if(n==i)
		cout<<A[i]<<endl;
	else
	{
		cout<<A[i]<<endl;
		print(A,n,i+1);
	}
}

int divide(int A[],int l,int r)
{
	int temp=A[l];
	int i=l,j=r;
	while(i<j)
	{
		while(i<j&&A[j]>=temp)
		{
			--j;
		}
		A[j]=A[i];
		while(i<j&&A[i]<=temp)
		{
			++i;
		}
		A[i]=A[j];
	}
	A[i]=temp;
	return i;
}

void quickSort(int A[],int l,int r)
{
	int mid;
	if(l>=r)
		return;
	else
	{
		mid=divide(A,l,r);
		quickSort(A,l,mid-1);
		quickSort(A,mid+1,r);
	}
	print(A,4,0);
}

printB(BTNode *p)
{
	if(p==NULL)
		return;
	else
	{
		cout<<p;
		printB(p->lchild);
		printB(p->rchild);
	}
}

void printG(AGraph *v)
{
	visit[MAXSIZE];
	for(int i=0;i<v->n;i++) visit[i]=0;
	visit[v]=1;
	p=v-f;
	while(p!=null)
	{
		if(p.adjvex==0)
			visit(p);
		p=p->nextArc;
	}
}
int main()
{
	int A[]={5,2,3,4,1};
	quickSort(A,0,4);
}














