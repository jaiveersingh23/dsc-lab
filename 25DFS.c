#include<stdio.h>
#include<stdlib.h>
#define MAX 200
typedef struct node
{
struct node *next;
int vertex;
}node;
void readgraph()
{ int i,vi,vj,no_of_edges;
printf("\nEnter no. of vertices :");
scanf("%d",&n);

for(i=0;i<n;i++)
 G[i]=NULL;

printf("\nEnter no of edges :");
scanf("%d",&no_of_edges);
for(i=0;i<no_of_edges;i++)
{
printf("\nEnter an edge (u,v) :");
 scanf("%d%d",&vi,&vj);
 insert(vi,vj);
 insert(vj,vi);
}
}
void insert(int vi,int vj)
{
node *p,*q;
q=(node *)malloc(sizeof(node));
q->vertex=vj;
q->next=NULL;
 the vertex no. vi
if(G[vi]==NULL)
 G[vi]=q;
else
{
 
 p=G[vi];
 while(p->next!=NULL)
 p=p->next;
 p->next=q;
}
}
void DFS(int i)
{
node *p;
visited[i]=1;
printf("\n%d",i);
for(p=G[i];p;p=p->next)
if(!visited[p->vertex])
DFS(p->vertex);
}
int visited[MAX];
node *G[20]; 
int n; 
void main()
{
int i,op;
do
 { printf("\n\n1)Create\n2)DFS\n4)Quit");
 printf("\nEnter Your Choice: ");
 scanf("%d",&op);
 switch(op)
 { case 1: readgraph();break;
 case 2: for(i=0;i<n;i++)
 visited[i]=0;
 printf("\nStarting Node No. : ");
 scanf("%d",&i);
 DFS(i);break;
 }
 }while(op!=4);
}
