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

int strLength(Str S)
{
	return S.length;
}

int strCompare(Str A,Str B)
{
	int i=0;
	for(i;i<A.length&&i<B.length;i++)
	{
		if(A.ch[i]!=B.ch[i])
			return A.ch[i]-B.ch[i];
	}
	return A.length-B.length;
}

int strCat(Str &S,Str A,Str B)
{
	if(S.ch!=NULL)
		free(S.ch);
	S.ch=(char*)malloc((A.length+B.length+1)*sizeof(char));
	if(!S.ch)
		return 0;
	int i=0;
	while(i<A.length)
	{
		S.ch[i]=A.ch[i];
		++i;
	}
	int j=0;
	while(j<B.length)
	{
		S.ch[i]=B.ch[j];
		++j;
	}
	S.length=A.length+B.length;
	return 1;
}

int subString(Str S,Str &A,int pos,int len)
{
	if(pos<0||pos>=S.length||len<0||len>S.length-pos)
		return 0;//ºÏ≤È ‰»Î
	if(A.ch!=NULL)
	{
		free(A.ch);
		A.ch=NULL;
	}
	if(len==0)
	{
		A.length=0;
		A.ch=NULL;
		return 1;
	} 
	else
	{
		int i=pos,j=0;
		A.ch=(char*)malloc(sizeof(char)*(len+1));
		if(A.ch==NULL)
			return 0;
		while(i<pos+len)
		{
			A.ch[j]=S.ch[i];
			++i;
			++j;
		}
		A.ch[j]='\0';
		A.length=len;
		return 1;
	}
}

int clearStr(Str &S)
{
	if(S.ch)
	{
		free(S.ch);
		S.ch=NULL;
	}
	return 1;
}

int index(Str S,Str A)
{
	int i=0,j=0,k=i;
	while(i<S.length&&j<A.length)
	{
		if(S.ch[i]==A.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			i=++k;
			j=0; 
		}
	}
	if(j==A.length)
		return k;
	else
		return -1;
}


int main()
{
	Str S;
	Str A;
	Str B;
	strAssign(A,"A dream");
	cout<<A.length<<endl;
	return 1;
}

































