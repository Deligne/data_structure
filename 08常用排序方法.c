#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct
{
	int r[MAXSIZE+1];
	int length;
}SqList;

void swap(SqList *L,int i,int j)
{
	int temp=L->r[j];
	L->r[j]=L->r[i];
	L->r[i]=temp;
}

void output(SqList *L)
{
	int i;
	for(i=1;i<=L->length;++i)
	{
		printf("%d, ",L->r[i]);
	}
}

int bubble(SqList *L)//bubble sort:setting falg; 
{
	int i,j,n,flag=0,count=0;
	n=L->length;
	for(i=1;i<L->length,flag==0;i++,n--)
	{
		flag=1;
		for(j=1;j<n;j++)
		{
			count+=1;
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);
				flag=0;
			}
		}
	}
	printf("   count:%d\n",count);
	return 1;
 } 
 
int insertSort0(SqList *L)
{
	int len=L->length;
	int i,j,count=0;
	for(i=2;i<=len;i++)
	{
		for(j=i;j>=2;j--)
		{
			count++; 
			if(L->r[j]<L->r[j-1])
			{
				swap(L,j,j-1);
			}
			else
			{
				break;
			} 
		}
	}
	printf("count: %d            ",count);
	return 1;
}

int partition0(SqList *L)
{
	int low=1,high=L->length,key=L->r[1];
	while(low<high)
	{
		while(low<high&&L->r[high]>=key)
		{
			high--;
		}	
		swap(L,high,low);
		while(low<high&&L->r[low]<=key)
		{
			low++;
		}
		swap(L,low,high);
	}	
	return low;
}

int partition(SqList *L,int low,int high)
{
	L->r[0]=L->r[low];
	int key=L->r[low];
	while(low<high)
	{
		while(low<high&&L->r[high]>=key) --high;
		L->r[low]=L->r[high];
		while(low<high&&L->r[low]<=key) ++low;
		L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low;
}

void quickSort(SqList *L,int low,int high)
{
	if(low<high)
	{
		int pivotloc=partition(L,low,high);
		quickSort(L,low,pivotloc-1);
		quickSort(L,pivotloc+1,high); 
	}
}

void selectSort(SqList *L)
{
	int i,j,count;
	for(i=0;i<=L->length;i++)
	{
		int min=i;
		for(j=i;j<=L->length;j++)
		{
			count+=1;
			if(L->r[j]<L->r[min]) min=j;
		}
		swap(L,i,min);
	}
	printf("%d,             ",count);
 } 

void merge(SqList *L,int low,int mid,int high)
{
	int i,k;
	SqList M;
	SqList *m=&M;
	int start1=low,end1=mid,start2=mid+1,end2=high;
	for(k=1;start1<end1&&start2<=end2;k++)
	{
		if(L->r[start1]<L->r[start2])
		{
			m->r[k]=L->r[start1++];
		}
		else
		{
			m->r[k]=L->r[start2++];
		}
	 }
	  
	while(start1<=end1)
	{
		m->r[k++]=L->r[start1++];
	}
	while(start2<=end2)
	{
		m->r[k++]=L->r[start2++];
	}
}

void mSort(SqList *L,int low,int high)
{
	int mid=(low+high)/2;
	if(low<high) 
	{
		mSort(L,low,mid);
		mSort(L,mid+1,high);
		merge(L,low,mid,high);
	}
}
 
int main()
{
	SqList L;
	SqList R;
	L.length=MAXSIZE; 
	L.r[0]=10;
	L.r[1]=5;
	L.r[2]=9; 
	L.r[3]=0; 
	L.r[4]=8; 
	L.r[5]=2; 
	L.r[6]=7; 
	L.r[7]=1; 
	L.r[8]=3; 
	L.r[9]=4; 
	L.r[10]=6; 
	R.r[0]=50;
	SqList *l=&L;
	SqList *r=&R;
	mSort(l,1,l->length);
	output(l);
	return 1;
}
