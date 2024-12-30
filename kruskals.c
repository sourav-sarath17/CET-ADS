#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int rank[20], parent[20], adj[20][20], mst[20][20], n, numEdge=0;
int cost;

struct edge{
    int u, v, cost;
};
void setUnion(int u, int v);
struct edge *getMinEdge();
int find(int node);

void main(){
    printf("\nEnter the no.of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("\nA[%d][%d]= ",i,j);
            scanf("%d",&adj[i][j]);
            mst[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }

    while(numEdge < n-1){
        struct edge *minEdge;
        minEdge=getMinEdge();
        int u = minEdge->u;
        int v = minEdge->v;
        if(find(u) != find(v)){
            setUnion(u,v);
            mst[u][v]= minEdge->cost;
            numEdge++;
        }
    }

    printf("\nMST Nodes and Edges\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mst[i][j] != 0)
                printf("\n%d-%d->Cost=%d",i,j,mst[i][j]);
        }
    }
}

struct edge *getMinEdge(){
    struct edge *Edge=malloc(sizeof(struct edge));
    int minWeight=INT_MAX;
    int cost;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j] !=0 && adj[i][j]<minWeight){
                minWeight=adj[i][j];
                Edge->u=i;
                Edge->v=j;
                Edge->cost=adj[i][j];
            }

        }
    }
    adj[Edge->u][Edge->v]=INT_MAX;
    return Edge;
}

int find(int node){
    if(parent[node] == node){
        return node;
    }

    else{
        return find(parent[node]);
    }
}

void setUnion(int u, int v)
{
    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u] += 1;
    }
}