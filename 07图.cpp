#include<iostream>
#include<cstdlib>
#include<iomanip>

#define MAXSIZE 5
#define INF 100
using namespace std;

typedef struct 
{
	int no;
}VertexType;

typedef struct MGraph
{
	int edges[MAXSIZE][MAXSIZE];
	int n,e;
	VertexType vex[MAXSIZE];
}MGraph;

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextArc;
}ArcNode;

typedef struct VNode 
{
	//int data;
	ArcNode *firstarc;
}VNode;

typedef struct AGraph
{
	VNode adjlist[MAXSIZE];
	int n,e;
}AGraph;

void initAG(AGraph *G)
{
	ArcNode *v01=(ArcNode*)malloc(sizeof(ArcNode));
	ArcNode *v03=(ArcNode*)malloc(sizeof(ArcNode));
	ArcNode *v04=(ArcNode*)malloc(sizeof(ArcNode));
	ArcNode *v12=(ArcNode*)malloc(sizeof(ArcNode));
	ArcNode *v14=(ArcNode*)malloc(sizeof(ArcNode));
	ArcNode *v20=(ArcNode*)malloc(sizeof(ArcNode));
	ArcNode *v32=(ArcNode*)malloc(sizeof(ArcNode));
	v01->adjvex=1;
	v03->adjvex=3;
	v04->adjvex=4;
	v12->adjvex=2;
	v14->adjvex=4;
	v20->adjvex=0;
	v32->adjvex=2;
	v01->nextArc=v03;
	v03->nextArc=v04;
	v04->nextArc=NULL;
	v12->nextArc=v14;
	v14->nextArc=NULL;
	v20->nextArc=NULL;
	v32->nextArc=NULL;
	G->adjlist[0].firstarc=v01;
	G->adjlist[1].firstarc=v12;
	G->adjlist[2].firstarc=v20;
	G->adjlist[3].firstarc=v32;
	G->adjlist[4].firstarc=NULL;
	cout<<"init AG succussful"<<endl;
}

void initMG(MGraph *M)
{
	M->e=7;
	M->n=5;
	M->vex[0].no=0;
	M->vex[1].no=1;
	M->vex[2].no=2;
	M->vex[3].no=3;
	M->vex[4].no=4;
	M->edges[0][0]=0;
	M->edges[1][1]=0;
	M->edges[2][2]=0;
	M->edges[3][3]=0;
	M->edges[4][4]=0;
	M->edges[0][1]=5;
	M->edges[0][2]=1;
	M->edges[0][3]=2;
	M->edges[0][4]=100;
	M->edges[1][0]=5;
	M->edges[1][2]=3;
	M->edges[1][3]=100;
	M->edges[1][4]=4;
	M->edges[2][0]=1;
	M->edges[2][1]=3;
	M->edges[2][3]=6;
	M->edges[2][4]=2;
	M->edges[3][0]=2;
	M->edges[3][1]=100;
	M->edges[3][2]=6;
	M->edges[3][4]=3;
	M->edges[4][0]=4;
	M->edges[4][1]=4;
	M->edges[4][2]=2;
	M->edges[4][3]=3;
	cout<<"init MG succussful"<<endl; 
}

int visit[MAXSIZE];
void DFS(AGraph *G,int v)
{
	ArcNode *p;
	visit[v]=1;
	cout<<v<<endl; 
	p=G->adjlist[v].firstarc;
	while(p!=NULL)
	{
		if(visit[p->adjvex]==0)
		{
			DFS(G,p->adjvex);			
		}
		p=p->nextArc;
	}
}

void BFS(AGraph *G,int v)
{
	int que[MAXSIZE];
	ArcNode *p;
	int rear=0,front=0;
	que[++rear]=v;
	visit[v]=1;
	cout<<v<<endl;
	while(front!=rear)
	{
		front=(front+1)%MAXSIZE;
		v=que[front];
		p=G->adjlist[v].firstarc;
		while(p!=NULL)
		{
			if(visit[p->adjvex]==0)
			{
				visit[p->adjvex]=1;
				cout<<p->adjvex<<endl;
				rear=(rear+1)%MAXSIZE;
				que[rear]=p->adjvex;
			}
			p=p->nextArc;
		}
	}
}

void DFS01(AGraph *G,int v)
{
	ArcNode *p;
	visit[v]=1;
	cout<<v<<endl;
	p=G->adjlist[v].firstarc;
	while(p!=NULL)
	{
		if(visit[p->adjvex]==0)
			DFS(G,p->adjvex);
		p=p->nextArc;
	}
 } 
 
void BFS01(AGraph *G,int v)
{
	ArcNode *p;
	visit[v]=1;
	cout<<v<<endl;
	int que[MAXSIZE];
	int rear=0,front=0;
	que[++rear]=v;
	while(front!=rear)
	{
		front=(front+1)%MAXSIZE;
		v=que[front];
		p=G->adjlist[v].firstarc;
		while(p!=NULL)
		{
			if(visit[p->adjvex]==0)
			{
				rear=(rear+1)%MAXSIZE;
				que[rear]=p->adjvex;
				cout<<p->adjvex<<endl;
			}
			p=p->nextArc;
		}	
	} 
}
int sum;

void prim(MGraph g,int v0,int &sum)
{
	int lowcost[MAXSIZE],vset[MAXSIZE];
	int v=v0;
	int i;
	for(i=0;i<g.n;++i)
	{
		vset[i]=0;
		lowcost[i]=g.edges[v0][i];
	}
	vset[v]=1;
	sum=0;
	for(int z=1;z<g.n;++z)
	{
		int min=INF,m;
		for(int k=1;k<g.n;++k)
		{
			if(vset[k]==0&&min>lowcost[k])
			{
				min=lowcost[k];
				m=k;
			}
		}
		cout<<"<"<<v<<","<<m<<">"<<",";
		v=m;
		vset[m]=1;
		sum+=min;
		for(int y=1;y<g.n;++y)
		{
			if(vset[y]==0&&g.edges[v][y]<lowcost[y])
			{
				lowcost[y]=g.edges[v][y];
			}
		}
	}
}

void printPath(int path[],int a)
{
	int stack[MAXSIZE],top=-1;
	while(path[a]!=-1)
	{
		stack[++top]=a;
		a=path[a];
	}
	stack[++top]=a;
	while(top!=-1)
		cout<<stack[top--]<<" ";
	cout<<endl;
}

void Dijkstra(MGraph g,int v,int dist[],int path[])
{
	int set[MAXSIZE];
	int min,i,j,u;
	for(i=0;i<g.n;++i)
	{
		dist[i]=g.edges[v][i];
		set[i]=0;
		if(g.edges[v][i]<INF)
			path[i]=v;
		else
			path[i]=-1;
	}
	set[v]=1;path[v]=-1;
	for(i=0;i<g.n;++i)
	{
		min=INF;
		for(int j=0;j<g.n;++j)
		{
			if(set[j]==0&&dist[j]>min)
			{
				min=dist[j];
				u=j;
			}
		}
		set[u]=1;
		for(int j=0;j<g.n;++j)
		{
			if(set[j]==0&&dist[u]+g.edges[u][j]<dist[j])
			{
				dist[j]=dist[u]+g.edges[u][j];
				path[j]=u;
			}
		}
			
	}
}

void printF(int path[][MAXSIZE],int s,int e)
{
	if(path[s][e]==-1)
		cout<<path[s][e]<<"->";
	else
	{
		int mid=path[s][e];
		printF(path,s,mid);
		printF(path,mid,e);
	}
}

void Floyd(MGraph g,int A[][MAXSIZE],int path[][MAXSIZE])
{
	int i,j,k;
	for(i=0;i<g.n;++i)
	{
		for(j=0;j<g.n;++j)
		{
			A[i][j]=g.edges[i][j];
			path[i][j]=-1;
		}
	}
	for(k=0;k<g.n;++k)
	{
		for(i=0;i<g.n;++i)
		{
			for(j=0;j<g.n;++j)
			{
				if(A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	for(i=0;i<g.n;++i)
	{
		for(j=0;j<g.n;++j)
		{
			cout<<path[i][j]<<", ";
		}
		cout<<endl;
	}
}


int main()
{
	AGraph G;
	AGraph *g=&G;
	initAG(g);
	//DFS(g,0);
	DFS01(g,3);
	MGraph mg;
	initMG(&mg);
	prim(mg,0,sum);
	cout<<endl<<"sum:"<<sum<<endl;
	int dist[MAXSIZE],path[MAXSIZE];
	int path1[MAXSIZE][MAXSIZE],A[MAXSIZE][MAXSIZE];
	Floyd(mg,A,path1);
	printF(path1,0,4);
}














