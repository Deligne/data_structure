#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define MAXSIZE 10
using namespace std;

typedef struct ArcNode 
{
	int adjvex;
	struct ArcNode *nextArc;
}ArcNode;//邻接表的边节点 

typedef struct VNode
{
	char data;
	ArcNode *firstarc;
}VNode;//邻接表的顶点节点 

typedef struct 
{
	VNode adjlist[MAXSIZE];
	int n,e;
}AGraph;//邻接表 

typedef struct MNode 
{
	char data;
}VertexType;

typedef struct 
{
	int edges[MAXSIZE][MAXSIZE];
	int n,e;
	VertexType vex[MAXSIZE];
}MGraph;

void prim(MGraph g,int v0,int &sum)
{
	int lowcost[MAXSIZE],vset[MAXSIZE],v;
	int i,j,k,min;
	v=v0;
	for(i=1;i<=g.n;++i)
	{
		lowcost[i]=g.edges[v0][i];
		vset[i]=0;
	}
	vset[v0]=1;
	sum=0;
	for(i=1;i<g.n;++i)
	{
		min=INF;
		for(j=1;j<g.n;++j)
		{
			if(vset[j]==0&&lowcost[j]<min)
			{
				k=j;
				min=lowcost[j];
			}
		}
		vset[k]=1;
		v=k;
		sum+=min;
		
		for(j=1;j<g.n;++j)
			if(vset[j]==0&&g.edges[v][j]<lowcost[j])
				lowcost[j]=g.edges[v][j];
	}
} 

void DFS(AGraph *G,int v)
{
	ArcNode *p;
	visit[v]=1;
	Visit(v);
	p=G->adjlist[v].firstarc;
	while(p!=NULL)
	{
		if(visit[p->adjvex]==0)
			DFS(G,p->adjvex);
		p=p->nextArc;
	}
}

void BFS(AGraph *G,int v,int visit[MAXSIZE])
{
	ArcNode *p;
	int que[MAXSIZE];
	int front=0,rear=0;//队列定义的简单写法
	int j;
	Visit[v];
	visit[v]=1;
	rear=[rear+1]%MAXSIZE;
	que[rear]=v;
	while(front!=rear)
	{
		front=(front+1%MAXSIZE;
		j=que[front];
		p=G->adjlist[j].firstarc;
		while(p!=NULL)
		{
			if(visit[p->adjvex]==0)
			{
				Visit(p->adjvex);
				visit[p->adjvex]=1;
				rear=(rear+1)%MAXSIZE;
				que[rear]=p->adjvex;
			}
			p=p->nextArc;
		}
	}
}//广度优先搜索







