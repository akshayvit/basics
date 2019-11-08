#include <iostream>
using namespace std;
int t=0;int n=30;
int bfs(int** mat);
void push(int* qeu,int n);
int max(int* arr);
int* jump(int** m,int row,int col,int dest);
struct pos{
    int x,y;
    int dest;
    pos(){};
};
int main()
{
    //printf("Hello World!\n");
    pos p;
    int n,tot,row,col;
    std::cin>>row>>col>>tot;
    int** mat;
    mat=(int**)malloc(sizeof(int)*row);
    for(int i=0;i<row;i+=1)
    {
        mat[i]=(int*)malloc(sizeof(int)*col);
    }
    int i=0;
    while(i<=tot-1)
    {
        std::cin>>p.x>>p.y>>p.dest;
        mat[p.x][p.y]=p.dest;
        i+=1;
    }
    std::cout<<bfs(mat)<<"\n";
    return 0;
}
int* jump(int** m,int row,int col,int d,int r,int c){
    if(row>r-1)
    {
        return NULL;
    }
    if(col>c-1)
    {
        return NULL;
    }
    int arr[2];
    if(d==0)
    {
        arr[0]=row;
        arr[1]=col;
        return arr;
    }
    jump(m,row+1,col+1,d,r,c);
    return arr;
}
int max(int* arr)
{
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i+=1)
    {
        if(arr[i]<arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    return arr[0];
}
int bfs(int** mat)
{
    int qeu[n];
    bool* visited;
    int len=sizeof(mat)/(sizeof(mat[0])/sizeof(mat[0][0]));
    int col=(sizeof(mat[0])/sizeof(mat[0][0]));
    visited=(bool*)malloc(sizeof(bool)*len);
    visited[0]=1;
    int count=0;
    for(int i=0;i<len;i+=1)
    {
        if(visited[i]!=1)
        {
        for(int j=0;j<col;j+=1)
        {
            if(mat[i][j]!=0)
            {
                int* temp=jump(mat,i,j,mat[i][j],len,col);
                i=temp[0];
                j=temp[1];
                push(qeu,j);
            }
            count+=1;
            if(i==len-1 && j==col-1)
            {
                break;
            }
        }
        visited[i]=1;
        }
    }
    return count;
}
void push(int* arr,int n)
{
    if(t<n-1){
        t+=1;
        arr[t]=n;
    }
}