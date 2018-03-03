#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
using namespace std;

void move0toend(float A[],int n)
{
	for(int i=0,j=n-1;i<n;i++)
	{
		if(i>=j)
			break;
		if(A[i]!=0)
		{
			++i;
			while(A[j]==0)
			{
				--j;
			}
			A[i]=A[j];
			A[j]=0;
		}
	}
}

float radd(float A[],int n,int p)
{
	if(p==n-1)
		return A[p];
	else
		return (A[p]+radd(A,n,p+1))/n;
}

float findMax(float A[],int i,int j)
{
	float Max;
	if(i==j)
		return A[i];
	else{
		Max=findMax(A,i+1,j);
		if(A[i]>Max)
			return A[i];
		else
			return Max; 
	}
}

int main()
{
	float A[]={6,0,18,12,0,6};
	/*move0toend(A,6);
	for(int i=0;i<6;++i)
		cout<<A[i]<<endl;
	cout<<radd(A,6,0);
	cout<<endl;*/
	cout<<findMax(A,0,5);
	return 1;
	
}
