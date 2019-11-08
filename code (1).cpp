// Example program
#include <iostream>
#include <string>
int* bellman(int mat[][5]);
int min(int a,int c);
int main()
{
    int mat[5][5]={{0,-1,2,4,5},
    {-2,0,2,1,5},
    {3,1,0,-2,5},
    {1,3,2,0,-2},
    {-1,3,2,4,0}};
    std::cout<<bellman(mat)<<"\n";
}
int min(int a,int c)
{
    return a>c ? a:c;
}
int* bellman(int mat[][5])
{
    int* arr;
    arr=(int*)malloc(sizeof(int)*5);
    *arr=0;
    for(int i=1;i<5;i+=1)
    {
        arr[i]=-5;
    }
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<len;i+=1)
    {
        int a=0;
        for(int j=0;j<5;i+=1)
        {
            
            for(int k=0;k<j;k+=1)
            {
                a=min(arr[k]+arr[j],mat[j][j]);
            }
        }
        arr[i]=min(arr[i],a);
    }
    return (int*)arr[len-1];
}