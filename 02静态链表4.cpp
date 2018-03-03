#include<iostream>
#include<cstdlib>
#include<iomanip>
#define MAX 50
using namespace std;

typedef struct
{
	char data;
	int ptr;
}Node;

typedef struct
{
	Node elem[MAX];
	int length;
}St;

void printS(St S,int n)
{
	cout<<S.elem[n].data<<endl;
	if(S.elem[n].ptr==0)
		return;
	else
		printS(S,S.elem[n].ptr);
}
 
int main()
{
	St S;
	S.elem[0].data='a';
	S.elem[0].ptr=1;
	S.elem[1].data='b';
	S.elem[1].ptr=2;
	S.elem[2].data='c';
	S.elem[2].ptr=3;
	S.elem[3].data='d';
	S.elem[3].ptr=4;
	S.length=4;
	printS(S,0);
}




