#include <iostream>
#include<stdlib.h>
using namespace std;
int power(int n,int k);
int** createsparse(int* arr);
int getval(int* arr,int l,int r);
int min(int a,int b);
int main()
{
    //cout << "Hello World!" << endl;
    int n;
    std::cin>>n;
    int* arr;
    arr=new int[n];
    for(int i=0;i<n;i+=1)
    {
        std::cin>>arr[i];
    }
    int** mat=createsparse(arr);
    int l,r;
    std::cin>>l>>r;
    std::cout<<mat[l][r];
    delete[] mat;
    return 0;
}
int power(int n,int k)
{
    if(k==0)
    {
        return 1;
    }
    return n*power(n,k-1);
}
int getval(int* arr,int l,int r1)
{
    int r=power(2,r1);
    int min=arr[l];
    for(int i=l+1;i<r;i+=1)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
}
int min(int a,int b)
{
    return a<b ? a:b;
}
int** createsparse(int* arr){
    const int len=sizeof(arr)/sizeof(arr[0]);
    int** temp=new int*[len];
    for(int i=0;i<len;i+=1)
    {
        temp[i]=new int[len];
    }
    //memset(temp[0],0,len);
    for(int i=0;i<len;i+=1)
    {
        temp[0][i]=getval(arr,0,i);
    }
    for(int i=1;i<len;i+=1)
    {
        for(int j=1;j<len;j+=1)
        {
            temp[i][j]=min(getval(arr,i,j/2),getval(arr,j/2+1,j));
        }
    }
    return temp;
}