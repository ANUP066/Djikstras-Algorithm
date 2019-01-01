#include<stdio.h>
#include<string.h>
#define INFINITY 9999
#define MAX 10
struct node{
        int n;
        char ip[100];
};
void dijkstra(int G[4][4],int n,int startnode,struct node *start);
void dijkstra2(int G[4][4],int n,int startnode,struct node *start,int m);
void recentre(int G[4][4],int n,int startnode,struct node *start,int m);
void print(int G[4][4],int distance[],int pred[],int startnode,int n,struct node *start);
int find(char *str,struct node *start);

int main()
{
    int i,j,n,u;
    char str[100];
    int G[4][4]={{0,5,17,10},{5,0,0,2},{17,0,0,6},{10,2,6,0}};
    struct node start[4]; 
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    for(i=0;i<4;i++)
    {
        start[i].n=i;
    }
    printf("\nEnter the respective ip address:");
    for(i=0;i<4;i++)
    {
        scanf("%s",start[i].ip);
    }
    printf("\nEnter the starting node:");
    scanf("%s",str);
    u=find(str,start);
    if(u==-1)
    {
        printf("Invalid IP\n");
    }
    else
    {   
        dijkstra(G,n,u,start);  
    }
    return 0;
}

void dijkstra(int G[4][4],int n,int startnode,struct node *start)
{

    int cost[4][4],distance[4],pred[4];
    int visited[4],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
    
    print(G,distance,pred,startnode,n,start);
}
void print(int G[4][4],int distance[],int pred[],int startnode,int n,struct node *start)
{
    int j,k,i,u1,c=0;
    
    char str1[100];
    int opt;
    printf("Enter the distance to :");
    scanf("%s",str1);
    u1=find(str1,start);
    if(u1==-1)
    {
        printf("Invalid IP\n");
    }
    else
    {   k=u1;  }
    
    int m;
    m=u1;
    printf("\nDistance of node %d[ip address:%s]=%d Pings",k,start[k].ip,distance[k]);
    printf("\nPath of node =%d[ip address:%s]",k,start[k].ip);
    j=k;
            do
            {
                j=pred[j];
                c++;
                printf("<-%d[ip address:%s]",j,start[j].ip);
            }while(j!=startnode);
    printf("\nJumps are %d",c);
    printf("\n");
    printf("Do you want to recentre from the same destination[1/0]:");
    scanf("%d",&opt);
    if(opt==1)
    {
        recentre(G,n,startnode,start,m);
    }
    else
    {
        printf("Bye\n");
    }
}
int find(char *str,struct node *start)
{
    int i;
    for(i=0;i<4;i++){
        if(!strcmp(str,start[i].ip))
                return i;
}
        return -1;
}
void recentre(int G[4][4],int n,int startnode,struct node *start,int m)
{
    int u2;
    char str2[100];
    printf("\nEnter the recentred node:");
    scanf("%s",str2);
    u2=find(str2,start);
    if(u2==-1)
    {
        printf("Invalid IP\n");
    }
    else if(u2==startnode)
    {
        printf("Enter the address correctly\n");
        
    }
    else
    {   dijkstra2(G,n,u2,start,m);  }
}
void dijkstra2(int G[4][4],int n,int startnode,struct node *start,int m)
{

    int cost[4][4],distance[4],pred[4];
    int visited[4],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;

        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
    int j1,k,c1=0;
    k=m;
    printf("\nDistance of node %d[ip address:%s]=%d Pings",k,start[k].ip,distance[k]);
    printf("\nPath of node =%d[ip address:%s]",k,start[k].ip);
    j1=k;
            do
            {
                j1=pred[j1];
                c1++;
                printf("<-%d[ip address:%s]",j1,start[j1].ip);
            }while(j1!=startnode);
    printf("\nJumps are %d",c1);
    printf("\n");
 }   
