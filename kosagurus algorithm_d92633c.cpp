#include <iostream>
#include <string.h>
#define n 5
using namespace std;
int t=-1;
void makemat(int mat[][n]);
bool dfs(int mat[][n]);
bool dfsreverse(int mat[n][n]);
void push(int arr[],int m);
bool isthere(int* arr);
int main()
{
    //printf("Hello World!\n");
    int mat[][n]={{0,1,1,0,1},
    {1,0,1,1,0},
    {0,0,1,1,1},
    {1,0,0,0,1},
    {1,1,0,0,0}};
    makemat(mat);
    return 0;
}
void makemat(int mat[][n]){
    int r=rand()-n+1;
    int temp[n-r+1][n];
    for(int i=r;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=mat[i][j];
        }
    }
    if(dfs(temp) && dfsreverse(temp)){
        std::cout<<"Connected"<<"\n";
        return;
    }
    std::cout<<"Not connected"<<"\n";
}
bool dfs(int mat[][n]){
    bool visited[n];
    visited[0]=true;
    int stack[n];
    for(int i=0;i<n;i++){
        if(!visited[i]){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    push(stack,j);
                }
            }
            visited[i]=true;
        }
    }
    return isthere(stack);
}   
bool dfsreverse(int mat[n][n]){
    int temp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=mat[j][i];
        }
    }
    bool a=dfs(mat);
    mat=temp;
    return a;
}
bool isthere(int* arr){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=i){
            return false;
        }
    }
    return true;
}
void push(int* arr,int m){
    if(t<n-1){
        t+=1;
        arr[t]=m;
    }
}