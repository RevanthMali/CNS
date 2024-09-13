#include<stdio.h>
#define MAX_NODES 20
// struct to define routing table for each node
struct Node{
    int dist[MAX_NODES];
    int from[MAX_NODES];
};

struct Node route[MAX_NODES];

int main(){
    int dm[MAX_NODES][MAX_NODES];
    int n;
    int i,j,k;
    int flag;
    // Get the input of no.of nodes
    printf("Enter the no.of nodes:\n");
    scanf("%d",&n);
    
    // get the cost matrix 
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        scanf("%d",&dm[i][j]);
        // set the distance to itself as 0
        if(i==j){    
            dm[i][j] = 0;
        }
        route[i].dist[j] = dm[i][j];
        route[i].from[j] = j;
        }
    }
    do{
        flag=0; // reset the flag to indicate the change
         for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){ 
                // check the shorter path
                    if (route[i].dist[j] > route[i].dist[k] + route[k].dist[j]) {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1; // Set flag to indicate a change
                }
            }
          }   
        }
    }while(flag);
    //print the series
    for(i=0;i<n;i++){
    printf("state value for router %d\n",i+1);
        printf("Dest\tnext-Hop\tDist\n");
        for(j=0;j<n;j++){
            printf("%d\t%d\t\t%d\n",j+1,route[i].from[j]+1,route[i].dist[j]);
        }
    }
    return 0;
}
