#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10

using namespace std;

typedef struct 
{
	char *ch;
	int length;
}Str;

int strAssign(Str &S,char *ch);
int print(int A[]);

int getNext(Str S,int next[])
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<S.length)
	{
		if(j==-1||S.ch[i]==S.ch[j])
		{
			++i;
			++j;
			next[i]==j;
		}
		else
			j=next[j];
	}
	print(next);
	return 1;
}

int KMP(Str S,Str A,int next[])
{
	int i=0,j=0;
	while(i<S.length&&j<S.length)
	{
		if(S.ch[i]==A.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			j=next[j];
			if(j==-1)
			{
				j=0;
				++i;
			}
		}
	}
	if(j=A.length)
		return i-A.length;
	else
		return -1;
}
int main()
{
	Str S;
	int Array[6];
	strAssign(S,"ABABABB");
	getNext(S,Array);
	print(Array);
	return 1;
}

int print(int A[])
{
	int i=0;
	while(A[i]>=-1)
	{
		cout<<A[i]<<endl;
		i++;		
	}
	return 1;
}

int strAssign(Str &S,char *ch)
{
	if(S.ch)
		free(S.ch);
	int len=0;
	char *c=ch;
	while(*c)
	{
		++len;
		++c;
	}//count
	if(len==0)
	{
		S.length=0;
		S.ch=NULL;
		return 1;
	}
	else
	{
		S.ch=(char*)malloc((len+1)*sizeof(char));
		if(S.ch==NULL)
			return 0;
		else
		{
			int i=0;
			c=ch;
			for(i;i<=len;++i,++c)
			{
				S.ch[i]=*c;
			}
			S.length=len;
			return 1;
		}
	}
}


