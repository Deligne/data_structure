#include<iostream>
#include<cstdlib>
#include<iomanip>//Ԥ���� 
#define MAX 50//define max=50 
using namespace std;
typedef bool STATUS;//���� 
typedef int other;//Node *BT=(Node*)malloc(sizeof(Node))�����.����NODE��С���ڴ������ҵ�ַ����ֵ��BT 
typedef struct Node
{
	int data;//������==��ַ,*(name+1)ȡ�õڶ���ֵ,����name[1].�ڵ�ַ�ڵ�δ��ֵΪ0,Խ�������ֵ(2293120��) 
	struct Node *next;//node
}Node;

void printA(int A[],int l,int r)
{
	for(int i=l;i<=r;++i)
		cout<<A[i];
}

void reverse(int R[],int l,int r)
{
	int temp,i=l,j=r; 
	while(i<j)
	{
		temp=R[i];
		R[i]=R[j];
		R[j]=temp;
		++i;
		--j;
	}
	printA(R,l,r);
}

void reverse0(int R[],int l,int r)
{
	int temp,i=l,j=r; 
	for(i,j;i<j;++i,--j)
	{
		temp=R[i];
		R[i]=R[j];
		R[j]=temp;
	}
	printA(R,l,r);
}

void RCR(int A[],int n,int p)
{
	if(p>=n||p<=0)
		cout<<"ERROR"<<endl;
	else
	{
		reverse(A,0,p-1);
		reverse(A,p,n-1);
		reverse(A,0,n-1);	
	} 
}

bool f(int a)
{
	if(a>0)
		return 1;
	return 0;
}

void chan(Node *&c)//*c��cָ���뺯��,*&c��ָ��c���� 
{
	Node A;
	c=&A;
}
int main()
{
	Node N;
	Node *p=&N;
	Node *i=(Node*)malloc(sizeof(Node));
	int K[]={1,2,3,4,5};
	int *k=K;
	cout<<&N<<p<<endl;
	cout<<K<<k<<endl;
	Node *c=NULL;
	cout<<endl<<c;//ָ��0����ڴ����� 
	cout<<&c<<"*c��ַ"<<endl; //Ҫ�ı�ĳ��ֵ��Ҫ�������ַ,�ı�*c����*&c 
	chan(c);//�������鼴�Ǵ����ַ, 
	cout<<c<<endl;
	int A[3]={1,2,3};
	int *a=A;
	cout<<a[1]<<endl;
	cout<<*(a+1)<<endl;
	cout<<f(1)<<endl;
	int S[]={100,20};
	int D[2];
	cout<<endl<<D[1]<<endl<<D[2]<<endl;
	cout<<S[10]<<endl<<S[0]<<endl<<A[4];
}

