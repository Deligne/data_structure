#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10

typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
 }SqQueue;
 
int init(SqQueue &Q)
{
	Q.front=0;
	Q.rear=0;
	return 1;
}

int enQueue(SqQueue &Q,int x)
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return 0;
	Q.rear=(Q.rear+1)%MAXSIZE;
	Q.data[Q.rear]=x;
	return 1;
}

int deQueue(SqQueue &Q,int &x)
{
	if(Q.front=Q.rear)
		return 0;//check
	Q.front=(Q.front+1)%MAXSIZE;
	x=Q.data[Q.front];
	return 1;
}

int main()
{
	return 1;
}













