#include<stdio.h>
#define INFINITY 9999
#define MAX 13
#include<string.h> 
void dijkstra(int G[MAX][MAX],int n,int startnode,char **str);
void print(int G[MAX][MAX],int distance[],int pred[],int startnode,int n,char **str);
int find(char *a,char **l); 
 


int main()
{
    
    FILE *fp1;
    fp1=fopen("is.csv","r");
    char s[1024],*k,*l[27],a[20];
    int i=0,j,m,n,u;
    fgets(s,1024,fp1);
    while(fgets(s,1024,fp1)){
    	k=strtok(s,",");
    	k=strtok(NULL,",");
    	l[i]=strdup(k);
    	i++;
    }  
    printf("travelling the cities :\n ");
    for(int g=0;g<13;g++){
    	printf("%s  ",l[g]);
    }
    printf("\n");
    int G[13][13]={{0,150,0,100,300,0,0,0,0,300,0,0,0},
    		 {150,0,50,0,0,0,0,0,0,100,0,0,0},
    		 {0,50,0,0,0,0,20,0,0,0,200,0,0},
    		 {100,0,0,0,0,400,0,50,0,0,0,0,0},
    		 {300,0,0,0,0,150,220,0,0,0,0,0,0},
    		 {0,0,0,400,150,0,0,0,200,0,0,150,0},
    		 {0,0,20,0,220,0,0,0,500,0,600,0,0},
    		 {0,0,0,50,0,0,0,0,0,0,0,110,0},
    		 {0,0,0,0,0,200,500,0,0,0,0,0,250},
    		 {300,100,0,0,0,0,0,0,0,0,0,0,0},
    		 {0,0,200,0,0,0,600,0,0,0,0,0,100},
    		 {0,0,0,0,0,150,0,110,0,0,0,0,0},
    		 {0,0,0,0,0,0,0,0,250,0,100,700,0}  
    		   };
    
    printf("\nEnter the starting place : ");
    scanf("%s",a);
    u=find(a,l);
    if(u==-1)
      printf("invalid start point\n");
    else
    	dijkstra(G,13,u,l);
}
void dijkstra(int G[MAX][MAX],int n,int startnode,char **str)
{ 
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
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
    count=0;
    
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
                    if(mindistance+cost[nextnode][i]<distance[i] && !visited[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }

    print(G,distance,pred,startnode,n,str);
}
void print(int G[MAX][MAX],int distance[],int pred[],int startnode,int n,char **str)
{
int j,k,u,opt;
char a[20];
printf("enter the distance to ");
scanf("%s",a);
u=find(a,str);
if(u==-1){
  printf("invalid destination\n");
	return ;
}
else 
  k=u;
printf("\nDistance of node %s = %d km",str[k],distance[k]);
 printf("\nPath= %s[%d]",str[k],k);
 j=k;
            do
            {
                j=pred[j];
                printf(" <- %s[%d]",str[j],j);
            }while(j!=startnode);

    printf("\n");
    printf("Do you  want to recenter to another destination or do you want to change the start point[1/0] :");
    scanf("%d",&opt);
    if(opt==1)
    {
	dijkstra(G,n,startnode,str);
    }
    else if(opt==0)
    {
	main();
     }
     else
     	printf("bye\n");
} 

int find(char *a,char **l){
int i;
for(int i=0;i<=27;i++){
  if(!strcmp(a,l[i]))
  	return i;
}
  return -1;
}
