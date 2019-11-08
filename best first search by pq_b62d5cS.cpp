#include <iostream>
#include<stdlib.h>
using  namespace std;
int index(int* arr,int n);
void push(int* arr,int tot,int n);
void pop(int* arr,int &n,int item);
int* sorted(int arr[]);
int t=-1;
int main()
{
    //printf("Hello World!\n");
    const int n=5;
    int mat[n][n]={{0,3,5,0,0},{4,0,2,5,0},{0,2,0,3,5},{0,4,1,0,5},{0,0,3,4,6}};
    int* stack=new int[n];
    int* visited=new int[n];
    for(int i=0;i<n;i+=1){
        visited[i]=0;
    }
    visited[0]=1;
    int goal;
    std::cout<<"Enter the goal:\n";
    std::cin>>goal;
    int m=100;
    for(int i=0;i<n;i+=1){
        mat[i]=sorted(mat[i]);
    }
    for(int i=0;i<n;i+=1){
        if(visited[i]!=1){
            for(int j=0;j<n;j+=1){
                if(mat[i][j]!=0){
                    push(stack,m,j);
                    //pop(stack,&m,i);
                    if(j==goal-1){
                        break;
                    }
                }
            }
            pop(stack,m,i);
            visited[i]=1;
        }
    }
    for(int i=0;i<n;i+=1){
       if(stack[i]>0){
           std::cout<<stack[i];
       }
    }
    return 0;
}
void push(int* arr,int tot,int n){
    if(t<tot-1){
        t+=1;
        arr[t]=n;
    }
}
int* sorted(int arr[]){
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i+=1){
        if(arr[i]>arr[i+1]){
            int t=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=t;
        }
    }
    return arr;
}
void pop(int* arr,int &n,int item){
    if(n>=0){
      for(int i=index(arr,item);i<n-1;i+=1){
          arr[i]=arr[i+1];
      }  
      n-=1;
    }
}
int index(int* arr,int n){
    int size=sizeof(arr)/sizeof(arr[0]);
    int m=0;
    for(int i=0;i<size;i+=1){
        if(arr[i]==n){
            m=i;
        }
    }
    return m;
}