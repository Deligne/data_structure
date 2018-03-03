#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10

using namespace std;

typedef struct 
{
	int length;
	int *ch; 
}String;

int reverse(String &S)
{
	int i=0,j=S.length-1,k;
	for(i;i<j;i++,j--)
	{
		k=S.ch[i];
		S.ch[i]=S.ch[j];
		S.ch[j]=K;
	}
	return 1; 
}//·´×ª´®

int deleteCh(String &S,char ch)
{
	int i,j;
	for(i=0;i<S.length;i++)
	{
		if(S.ch[i]==ch)
		{
			for(j=i;j<S.length;j++)
			{
				S.ch[j]=S.ch[j+1]; 
			}		
			--S.length;
		}
	}
	return 1;
}//É¾³ý´®SÖÐch 


