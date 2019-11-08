#include <iostream>
#define n 5
using namespace std;
bool isbipart(int mat[][n]);
void push(int* st,int m);
int t=-1;
int main()
{
    //printf("Hello World!\n");
    int mat[][n]= {{0, 0, 0,0,0},
		{0,0,0,1, 0},
		{0,0, 0, 0, 0},
		{0, 0,1,0, 0},
		{0, 0,0,0, 0}
	};
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(mat[i][j]==1){
            mat[i][j]=0;
        }
        else{
            mat[i][j]=1;
        }
    }
    }
    if(isbipart(mat)){
        std::cout<<"Yes ";
    }
    else{
        std::cout<<"No ";
    }
    return 0;
}
void push(int* st,int m){
    if(t<n-1){
        t++;
        st[t]=m;
    }
}
int pop(int* st){
    int a=st[t];
    t--;
    return a;
}
bool isbipart(int mat[][n]){
    int color[n];
    int stack[n];
    for(int i=0;i<n;i++){
        color[i]=2;
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                if(color[j]<2){
                    color[j]=3;
                }
            }
        }
    }
    bool visited[n];
    visited[0]=true;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    push(stack,j);
                    int a=pop(stack);
                    if(color[j]==color[a]){
                        return false;
                    }
                }
            }
            visited[i]=true;
        }
    }
    return true;
}