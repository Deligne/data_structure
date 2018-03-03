#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

typedef struct 
{
	int data[MAX];
	int length;
}SqList;

int locateElem(SqList L,int e)
{
	int i;
	for(i=1;i<=L.length;i++)
	{
		if(L.data[i]==e)
			return i;
	}
	return 0;
}//���� L ��ֵΪ e ���±� 

int insert(SqList &L,int p,int e)
{
	if(p<1||p>L.length+1||p==MAX)
		return 0;
	int i;
	for(i=L.length;i>=p;i++)
		L.data[i+1]=L.data[i];
	L.data[p]=e;
	L.length++;
	return 1;
 } //�� L �±� P ������ e 

int listDelete(SqList &L,int p,int &e)
{
 	if(p<1||p>L.length)
 		return 0;//Խ���� 
 	int i;
 	e=L.data[p];
 	for(i=p;i<=L.length-1;i++)
 		L.data[i]=L.data[i+1];//ǰ�±��ֵ���ں��±��ֵ,ǰ��һλ 
 	L.length--;//���ȼ�һ 
 	return 1;
}//ɾ���±�ΪP��Ԫ�� 
 
int initList(SqList &L,int n)
{
	L.length=n;
	srand((unsigned int)time(NULL));
	int i;
	for(i=1;i<=L.length;i++)
		L.data[i]=rand()%10;
}
 
int getElem(SqList L,int p,int &e)
{
	if(p<1||p>L.length) return 0;//Խ����
	e=L.data[p];
	return 1; 
}

int print(SqList L)
{
	printf("length:%d.       ",L.length);
	int i;
	for(i=1;i<=L.length;i++)
	{
		printf("%d, ",L.data[i]);
	 } 
}
 
 int main()
 {
 	SqList L;
 	initList(L,5);
 	print(L);
 	insert(L,6,100);
 	printf("%d",locateElem(L,3));
 	print(L);
 }
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
