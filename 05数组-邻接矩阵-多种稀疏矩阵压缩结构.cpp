#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
#define M 4
#define N 5
using namespace std;

typedef struct Node
{
	int data;
	int col;
	struct Node *next;
}Node;

void trsmat(int A[][MAXSIZE],int B[][MAXSIZE],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			B[j][i]=A[i][j];
		}
	}
 }//矩阵转置,为了突出重点.设置MAXSIZE可以避免输入检查
 
void plus(int C[][MAXSIZE],int A[][MAXSIZE],int B[][MAXSIZE],int m,int n)
{
	int i=0,j=0;
	for(i;i<m;i++)
	{
		for(j;j<n;j++)
		{
			C[i][j]=A[i][j]+B[i][j];
		}
	}
}//加

void mutmat(int C[][MAXSIZE],int A[][MAXSIZE],int B[][MAXSIZE],int m,int n)
{
	int i=0,j=0,k=0;
	for(i;i<m;i++)
	{
		for(j;j<n;j++)
		{
			C[i][j]=0;
			for(int h=0;h<n;++h)
				C[i][j]+=A[h][j]*B[i][h];
		}
	}
}//乘 h

void createTribleMatrix(float A[][MAXSIZE],int m,int n,float B[][3])
{
	int k=1;
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(A[i][j]!=0)
			{
				B[k][0]=A[i][j];
				B[k][1]=i;
				B[k][2]=j;
				++k;	
			}
		}		
	}
	B[0][0]=k-1;
	B[0][1]=m;
	B[0][2]=n; 
}//三元组表示稀疏矩阵 


void print(float B[][3])
{
	int i,j;
	for(i=0;i<B[0][1];++i)
	{
		for(j=0;j<B[0][2];++j)
		{
			int flag=0,k;
			for(k=1;k<=B[0][0];++k)
			{
				if(i==(int)B[k][1]&&j==(int)B[k][2])
				{
					cout<<B[k][0]<<" ";
					flag=1;
					break;
				}
			 } 
			if(flag==0)
				cout<<"0";
		}
		cout<<endl;
	}
}//输出

void createAdd(float Matrix[][MAXSIZE],float B[][2],int m,int n)
{
	int i,j,k=1;
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			if(Matrix[i][j]!=0)
			{
				int add=(i-1)*n+j;
				B[k][0]=Matrix[i][j];
				B[k][1]=add;
				++k;
			}
		}
	}
	B[0][0]=k-1;
	B[0][1]=0;
}//伪地址矩阵 

void nearMatrix(float Matrix[][MAXSIZE],int A[],int m,int n)
{
	int i,j;
	for(i=0;i<m;++i)
	{
		A[i]=NULL;
	}
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			if(Matrix[i][j]!=0)
			{
				Node *s=(Node*)malloc(sizeof(Node));
				s->data=Matrix[i][j];
				s->col=j;
				Node *r=A[i];
				while(r!=NULL)
				{
					r=r->next; 
				}
				s->next=r->next;
				r->next=s;
			}
		}
	 } 
}//创建邻接矩阵



 

int main()
{
	float Matrix[2][MAXSIZE];
	Matrix[0][0]=1;
	Matrix[0][1]=0;
	Matrix[1][0]=1;
	Matrix[1][1]=1;
	float B[4][3];
	createTribleMatrix(Matrix,2,2,B);
	print(B);
	return 1;
}


