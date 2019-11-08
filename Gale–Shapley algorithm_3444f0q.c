#include <stdio.h>
#include <stdlib.h>
#define N 4
int main()
{
    //printf("Hello World!\n");
    int prefer[2*N][N] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    printf("Man-Woman\n\n");
    stableMarriage(prefer);
 
    return 0;
}
int bool_search(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            return 1;
        }
    }
}
int search(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            return i;
        }
    }
}
void stableMarriage(int mat[][N]){
    int visitedm[N];
    int visitedw[N];
    int k=N;
    for(int i=0;i<=N-1 && k<=2*N;i++){
        while(visitedm[i]!=1 && mat[i][k]!=-1){
            int w=mat[i][k];
            if(visitedw[w-N+1]==0){
                printf("%d-%d\n",i,w);
                visitedw[w-N+1]=1;
            }
            else{
                if(i!=0){
                    if(bool_search(mat[w],i)){
                        printf("%d-%d\n",search(mat[w],i),w);
                    }
                    else{
                        printf("%d-%d\n",i,w);
                    }
                }
                else{
                    printf("%d-%d\n",i,w);
                }
            }
            mat[i][k]=-1;
            mat[k][i]=-1;
            visitedm[i]=1;
            k++;
        }
        
    }
}