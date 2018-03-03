#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10

using namespace std;

void insertSort(int A[],int n)
{
	for(int i=2;i<=n-1;++i)
	{
		int j=i;
		A[0]=A[i];
		while(j>1&&A[0]<A[j-1])
		{
			A[j]=A[j-1];
			--j;
		}
		A[j]=A[0];
	}
	for(int i=1;i<6;++i)
		cout<<A[i];	
} 

void insertMid(int A[],int n)
{
	for(int i=2;i<=n;++i)
	{
		A[0]=A[i];
		int mid,high=i,low=1;
		while(low<high)
		{
			mid=(low+high)/2;
			if(A[mid]>A[0])
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		for(int j=i;j>low;--j)
		{
			A[j]=A[j-1];
		}
		A[low]=A[0];
	}
	for(int i=1;i<6;++i)
		cout<<A[i];	
}

void bubbleSort(int A[],int n)
{
	int flag=1;
	for(int i=1;i<n&&flag==1;++i)
	{
		flag=0;
		for(int j=1;j<n-i;++j)
		{
			if(A[j]>A[j+1])
			{
				flag=1;
				int temp=A[j+1];
				A[j+1]=A[j];
				A[j]=temp;
			}
		}
	}
	for(int i=1;i<6;++i)
		cout<<A[i]<<", ";	
}

quickSort(int A[],int l,int r)
{
	int mid=A[l],temp;
	whlie(l<r)
	{
		while(A[r]>mid)
		{
			--r;
		}
		temp=A[r];
		A[r]=A[l];
		A[l]=temp;
		while(A[l]>mid)
		{
			--r;
		}
		temp=A[r];
		A[r]=A[l];
		A[l]=temp;
	}
	quickSort(A,)
}

int main()
{
	int A[]={0,5,4,23,16,2};
	bubbleSort(A,6);
}
